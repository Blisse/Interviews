#include "sudoku.h"

#include <iostream>

const int SUDOKU_MULT = 362880;
const int SUDOKU_SUM = 45;

SudokuSolver::SudokuSolver(std::vector<std::vector<int>> grid) :
    _initialGrid(grid),
    _finalGrid(grid),
    _possibilities(9, std::vector<std::set<int>>(9, {1, 2, 3, 4, 5, 6, 7, 8, 9}))
{
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (_finalGrid[i][j] != 0) {
                _possibilities[i][j].clear();
            }
        }
    }
}

void SudokuSolver::printGridAsLine(std::ostream& os, std::vector<std::vector<int>> grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                os << '.';
            } else {
                os << grid[i][j];
            }
        }
    }
    os << std::endl;
}

void SudokuSolver::printPossibilities(std::ostream& os, std::vector<std::vector<int>> grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                os << '.';
            } else {
                os << grid[i][j];
            }
        }
    }
    os << std::endl;
}

void SudokuSolver::solve() {

    while (solveOne()) {

        printGridAsLine(std::cout, _finalGrid);

    }

}

bool SudokuSolver::solveOne() {

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            if (_finalGrid[i][j] == 0) {

                // Eliminate numbers in the same row or column.
                for (int ij = 0; ij < 9; ij++) {
                    _possibilities[i][j].erase(_finalGrid[ij][j]);
                    _possibilities[i][j].erase(_finalGrid[i][ij]);
                }

                // Eliminate numbers in the same 3x3 grid
                for (int ii = 0; ii < 3; ii++) {
                    for (int jj = 0; jj < 3; jj++) {
                        _possibilities[i][j].erase(_finalGrid[i/3+ii][j/3+jj]);
                    }
                }

                if (_possibilities[i][j].size() == 1) {
                    _finalGrid[i][j] = *_possibilities[i][j].begin();
                    return true;
                }
            }

        }
    }

    return false;
}

std::vector<std::vector<int>> SudokuSolver::initial_grid() {
    return _initialGrid;
}

std::vector<std::vector<int>> SudokuSolver::final_grid() {
    return _finalGrid;
}

std::vector<std::vector<int>> SudokuParser::parse(std::istream& is) {
    std::vector<std::vector<int>> grid(9, std::vector<int>(9, 0));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            char c;
            if (is.get(c) && c != '.') {
                grid[i][j] = static_cast<int>(c - '0');
            }
        }
    }

    return grid;
}

void SudokuParser::write(std::ostream& os, std::vector<std::vector<int>> grid) {
    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {
            if (grid[i][j] == 0) {
                os << '.';
            } else {
                os << static_cast<char>(grid[i][j] + '0');
            }
        }
    }

    os << std::endl;
}


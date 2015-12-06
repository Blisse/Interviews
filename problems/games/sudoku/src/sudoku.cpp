#include "sudoku.h"

#include <iostream>

const int SUDOKU_MULT = 362880;
const int SUDOKU_SUM = 45;

SudokuSolver::SudokuSolver(std::vector<std::vector<int>> grid) :
    _initialGrid(grid),
    _finalGrid(grid)
{

}

void SudokuSolver::solve() {
    auto& grid = final_grid();

    std::vector<std::vector<std::vector<int>>> possibilities(9, std::vector<std::vector<int>>(9, std::vector<int>(0)));

    for (int i = 0; i < 9; i++) {
        for (int j = 0; j < 9; j++) {

            for (int )

        }
    }
}

std::vector<std::vector<int>>& SudokuSolver::initial_grid() {
    return _initialGrid;
}

std::vector<std::vector<int>>& SudokuSolver::final_grid() {
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

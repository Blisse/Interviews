#ifndef _SUDOKU_H__
#define _SUDOKU_H__

#include <vector>
#include <set>
#include <istream>
#include <ostream>

class SudokuSolver {
public:
    SudokuSolver(std::vector<std::vector<int>> grid);
    std::vector<std::vector<int>> initial_grid();
    std::vector<std::vector<int>> final_grid();
    void printGridAsLine(std::ostream& os, std::vector<std::vector<int>> grid);
    void printPossibilities(std::ostream& os);
    void solve();


private:
    bool solveOne();

    std::vector<std::vector<int>> _initialGrid;
    std::vector<std::vector<int>> _finalGrid;
    std::vector<std::vector<std::set<int>>> _possibilities;
};

class SudokuParser {
public:
    std::vector<std::vector<int>> parse(std::istream& is);
    void write(std::ostream& os, std::vector<std::vector<int>> grid);
};

#endif

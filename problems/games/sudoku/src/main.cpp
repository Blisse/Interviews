#include "sudoku.h"

#include <sstream>
#include <memory>
#include <iostream>

int main(int argc, char const *argv[]) {

    std::string input("52...6.........7.13...........4..8..6......5...........418.........3..2...87.....");

    std::cout << input << std::endl;

    std::stringstream ss(input);

    std::shared_ptr<SudokuParser> parser = std::make_shared<SudokuParser>();

    std::vector<std::vector<int>> grid = parser->parse(ss);

    std::shared_ptr<SudokuSolver> solver = std::make_shared<SudokuSolver>(grid);

    solver->solve();

    parser->write(std::cout, grid);

    return 0;
}

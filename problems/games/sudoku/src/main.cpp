#include "sudoku.h"

#include <sstream>
#include <memory>
#include <iostream>

int main(int argc, char const *argv[]) {

    std::string input("..84...3....3.....9....157479...8........7..514.....2...9.6...2.5....4......9..56");

    std::cout << input << std::endl;

    std::stringstream ss(input);

    std::shared_ptr<SudokuParser> parser = std::make_shared<SudokuParser>();

    std::vector<std::vector<int>> grid = parser->parse(ss);

    std::shared_ptr<SudokuSolver> solver = std::make_shared<SudokuSolver>(grid);

    solver->solve();

    parser->write(std::cout, solver->final_grid());

    return 0;
}

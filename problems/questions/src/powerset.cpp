#include <set>
#include <iostream>
#include <algorithm>

void printInt(int val) {
    std::cout << val << ", ";
}

void printSet(const std::set<int>& val) {
    std::for_each(val.begin(), val.end(), printInt);
    std::cout << std::endl;
}

void printSetOfSets(const std::set<std::set<int>>& val) {
    std::for_each(val.begin(), val.end(), printSet);
    std::cout << std::endl;
}

std::set<std::set<int>> powerset(const std::set<int>& input_set) {

    std::set<std::set<int>> output_powerset = {
        input_set
    };

    for (auto& it : input_set) {

        if (input_set.size() > 1) {
            std::set<int> minus_it(input_set);
            minus_it.erase(it);

            for (auto& jt : powerset(minus_it)) {
                output_powerset.insert(jt);
            }
        }
    }

    return output_powerset;
}

int main(int argc, char const *argv[]) {

    printSetOfSets(powerset({1, 2, 3, 4, 5, 6, 7, 8, 9}));

    return 0;
}

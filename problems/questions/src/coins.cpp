#include <set>
#include <map>
#include <vector>
#include <iostream>

using namespace std;

map<int, vector<vector<int>>> combinations_for_target;

vector<vector<int>> getCoinCombinationsWithTargetSumRecursive(const set<int>& coins, int target, int depth) {

    vector<vector<int>> coin_combinations;

    for (int coin : coins) {

        int remaining_value = target - coin;

        if (remaining_value == 0) {

            coin_combinations.push_back({coin});

        } else if (remaining_value > 0) {

            vector<vector<int>> potential_combinations = getCoinCombinationsWithTargetSumRecursive(coins, remaining_value, depth + 1);

            for (vector<int> combination : potential_combinations) {
                combination.push_back(coin);
                coin_combinations.push_back(combination);
            }

        }

    }

    return coin_combinations;
}

vector<vector<int>> getCoinCombinationsWithTargetSumDynamic(const set<int>& coins, int target) {

    vector<vector<int>> coin_combinations;

    for (int coin : coins) {

        int remaining_value = target - coin;

        if (remaining_value == 0) {

            coin_combinations.push_back({coin});

        } else if (remaining_value > 0) {

            if (combinations_for_target.at(remaining_value).size() > 0) {

                for (vector<int> combination : combinations_for_target.at(remaining_value)) {

                    combination.push_back(coin);
                    coin_combinations.push_back(combination);

                }

            }

        }

    }

    return coin_combinations;
}

vector<vector<int>> getCoinCombinationsWithTargetSum(const set<int>& coins, int target) {

    for (int current_target = 1; current_target <= target; current_target++) {
        vector<vector<int>> coin_combinations = getCoinCombinationsWithTargetSumDynamic(coins, current_target);
        combinations_for_target[current_target] = coin_combinations;

        cout << current_target << endl;
    }

    return combinations_for_target.at(target);
}


int main(int argc, char const *argv[]) {

    for (auto cc : getCoinCombinationsWithTargetSum({1,5,10,25}, 100)) {
        for (auto c : cc) {
            cout << c << " ";
        }
        cout << endl;
    }

    return 0;
}

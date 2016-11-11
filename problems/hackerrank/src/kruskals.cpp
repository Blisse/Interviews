#include <cmath>
#include <cstdio>
#include <vector>
#include <iostream>
#include <algorithm>
#include <climits>
#include <set>
#include <queue>
#include <tuple>
#include <functional>
#include <iterator>
using namespace std;

typedef tuple<int,int,int> cost_from_to;

class CostFromToComparator {
public:
    bool operator() (const cost_from_to& a, const cost_from_to& b) const {
        int a_to, a_from, a_cost;
        int b_to, b_from, b_cost;
        tie(a_cost, a_to, a_from) = a;
        tie(b_cost, b_to, b_from) = b;

        if (a_cost == b_cost) {
            return (a_from + a_cost + a_to) > (b_from + b_cost + b_to);
        }
        return a_cost > b_cost;
    }
};

int subtree_weight(vector<cost_from_to> graph) {
    priority_queue<cost_from_to, vector<cost_from_to>, CostFromToComparator> cheapest_edge(graph.begin(), graph.end());

    vector<int> forest(graph.size(), 0);
    for (int i = 0; i < forest.size(); i++) {
        forest[i] = i;
    }

    int total_cost = 0;

    while (!cheapest_edge.empty()) {
        int from, to, cost;
        tie(cost, from, to) = cheapest_edge.top();
        cheapest_edge.pop();

        if (forest[from] != forest[to]) {
            total_cost += cost;

            int merge_forest = forest[from];
            for (int i = 0; i < forest.size(); i++) {
                if (forest[i] == merge_forest) {
                    forest[i] = forest[to];
                }
            }
        }
    }

    return total_cost;
}

int main() {
    /* Enter your code here. Read input from STDIN. Print output to STDOUT */
    int nodes, edges;
    cin >> nodes >> edges;

    vector<cost_from_to> graph;
    for (int i = 0; i < edges; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        graph.emplace_back(cost, from, to);
    }

    int start;
    cin >> start;
    start--;

    cout << subtree_weight(graph) << endl;

    return 0;
}

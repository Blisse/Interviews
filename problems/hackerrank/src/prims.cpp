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

typedef tuple<int,int> cost_to;

vector<int> get_neighbours(const vector<vector<int>>& graph, int node) {
    vector<int> neighbours;

    for (int i = 0; i < graph.at(node).size(); i++) {
        if (graph.at(node).at(i) != -1) {
            neighbours.push_back(i);
        }
    }

    return neighbours;
}

int subtree_weight(const vector<vector<int>>& graph, int start) {
    priority_queue<cost_to, vector<cost_to>, greater<cost_to>> cheapest_edge;
    for (auto neighbour : get_neighbours(graph, start)) {
        cheapest_edge.emplace(graph[start][neighbour], neighbour);
    }

    set<int> visited;
    visited.insert(start);

    int total_cost = 0;

    while (!cheapest_edge.empty()) {
        int current_node, cost;
        tie(cost, current_node) = cheapest_edge.top();
        cheapest_edge.pop();

        if (visited.count(current_node) == 0) {
            visited.insert(current_node);
            total_cost += cost;

            for (auto neighbour : get_neighbours(graph, current_node)) {
                if (visited.count(neighbour) == 0) {
                    cheapest_edge.emplace(graph[current_node][neighbour], neighbour);
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

    vector<vector<int>> graph(edges, vector<int>(edges, -1));
    for (int i = 0; i < edges; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from--; to--;
        graph[from][to] = cost;
        graph[to][from] = cost;
    }

    int start;
    cin >> start;
    start--;

    cout << subtree_weight(graph, start) << endl;

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <queue>
#include <map>
#include <set>
#include <tuple>
#include <climits>
#include <iostream>
#include <functional>
#include <algorithm>
using namespace std;

// https://www.hackerrank.com/challenges/dijkstrashortreach

class Graph {
public:
    int nodes;
    vector<vector<int>> graph;
    map<int, vector<int>> neighbours;

    Graph(int n, int e) :
        nodes(n),
        graph(e, vector<int>(e, 0))
    {
    }

    void reach(int start) {
        vector<int> distances(nodes, numeric_limits<int>::max());
        distances[start] = 0;

        set<int> visited;
        visited.insert(start);

        priority_queue<tuple<int,int>, vector<tuple<int,int>>, greater<tuple<int,int>>> nearest_neighbour;
        nearest_neighbour.emplace(0, start);

        while(!nearest_neighbour.empty()) {
            int cost, current;
            tie(cost, current) = nearest_neighbour.top();
            nearest_neighbour.pop();

            visited.insert(current);

            for (int neighbour : neighbours[current]) {
                if (cost + graph[current][neighbour] < distances[neighbour]) {
                    distances[neighbour] = cost + graph[current][neighbour];
                    nearest_neighbour.emplace(distances[neighbour], neighbour);
                }
            }
        }

        for (int i = 0; i < nodes; i++) {
            if (start != i) {
                if (visited.count(i) == 0) {
                    cout << -1 << " ";
                } else {
                    cout << distances[i] << " ";
                }
            }
        }
        cout << endl;
    }
};

int main() {
    int tests;
    cin >> tests;

    for (int i = 0; i < tests; i++) {
        int nodes, edges;
        cin >> nodes >> edges;

        Graph graph(nodes, edges);

        for (int j = 0; j < edges; j++) {
            int from, to, cost;
            cin >> from >> to >> cost;
            from--; to--;

            graph.graph[from][to] = cost;
            graph.graph[to][from] = cost;

            if (graph.neighbours.count(from) == 0) {
                graph.neighbours[from] = { to };
            } else {
                graph.neighbours[from].push_back(to);
            }
            if (graph.neighbours.count(to) == 0) {
                graph.neighbours[to] = { from };
            } else {
                graph.neighbours[to].push_back(from);
            }
        }

        int start;
        cin >> start;
        start--;

        graph.reach(start);
    }

    return 0;
}

#include <cmath>
#include <cstdio>
#include <vector>
#include <deque>
#include <list>
#include <stack>
#include <queue>
#include <iostream>
#include <iomanip>
#include <iterator>
#include <algorithm>
#include <map>
#include <set>
#include <cmath>
#include <chrono>
#include <memory>
#include <limits>

/*
Bitville is a seaside city that has shopping centers connected via bidirectional roads.
Each road connects exactly two distinct shopping centers and has a travel time associated with it.

There are different types of fish sold in Bitville.
Historically, any shopping center has a fishmonger selling certain types of fish.
Buying any amount of fish from any fishmonger takes no time.

Our heroes, Big Cat and Little Cat, are standing at Bitville shopping center number .
They have a list of the types of fish sold at each fishmonger,
and they want to collectively purchase all types of fish in a minimal amount of time.
To do this, they decide to split the shopping between themselves in the following way:

    Both cats choose their own paths, starting at shopping center and ending at shopping center .
        It should be noted that Little Cat's path is not necessarily the same as Big Cat's.
    While traveling their respective paths, each cat will buy certain types of fish at certain shops.
    When the cats reach shopping center , they must have collectively purchased all types of fish
        in a minimal amount of time.
    If one cat finishes shopping before the other, he waits at shopping center for his partner to finish;
        this means that the total shopping time is the maximum of Little and Big Cats' respective shopping times.

It is to be noted that any of the cats can visit the shopping center in between,
but they both have to finish their paths at the shopping center .

Given the layout for Bitville and the list of fish types sold at each fishmonger,
what is the minimum amount of time it will take for Big and Little Cat to purchase all types of fish
and meet up at shopping center N ?
*/

using namespace std;

class Timer
{
public:
    Timer() : beg_(clock_::now()) {}
    void reset() { beg_ = clock_::now(); }
    double elapsed() const {
        return std::chrono::duration_cast<second_>
            (clock_::now() - beg_).count(); }

private:
    typedef std::chrono::high_resolution_clock clock_;
    typedef std::chrono::duration<double, std::ratio<1> > second_;
    std::chrono::time_point<clock_> beg_;
};

struct Path {
    int shop;
    int fish;
    int cost;

    Path(int shop, int fish, int cost) : shop(shop), fish(fish), cost(cost) {
    }
};

struct PathCompare {
    bool operator() (const Path& a, const Path& b)
    {
        if (a.cost == b.cost) {
            return a.fish < b.fish;
        }
        return a.cost > b.cost;
    }
};

class City {
    int num_roads;
    int num_shops;
    int total_fish;

public:
    vector<vector<int>> distances;
    vector<vector<bool>> visited;
    vector<int> shops;
    vector<vector<int>> costs;
    map<int, vector<int>> neighbours;

    City(int num_roads, int num_shops, int total_fish) :
            distances(num_shops, vector<int>((1 << total_fish), numeric_limits<int>::max())),
            visited(num_shops, vector<bool>((1 << total_fish), false)),
            shops(num_shops, 0),
            costs(num_shops, vector<int>(num_shops, 0)),
            num_roads(num_roads),
            num_shops(num_shops),
            total_fish(total_fish)
    {
    }

    int synchronous_shopping() {
        Timer tmr;
        tmr.reset();

        Path current(0, shops.at(0), 0);

        priority_queue<Path, vector<Path>, PathCompare> visit;
        visit.push(current);

        while (!visit.empty()) {
            current = visit.top();
            visit.pop();

            distances[current.shop][current.fish] = min(distances[current.shop][current.fish], current.cost);

            if (!visited[current.shop][current.fish]) {
                visited[current.shop][current.fish] = true;

                for (int neighbour : neighbours[current.shop]) {
                    visit.emplace(Path(neighbour, current.fish | shops.at(neighbour), current.cost + costs[current.shop][neighbour]));
                }
            }
        }

        // cout << fixed << setprecision(numeric_limits<double>::digits10 + 1) << tmr.elapsed() << endl;
        tmr.reset();

        int min_cost = numeric_limits<int>::max();
        int all_bits = (1 << total_fish);

        for (int i = 1; i < all_bits; i++) {
            for (int j = 1; j < all_bits; j++) {
                if ((i | j) == (all_bits-1)) {
                    min_cost = min(min_cost, max(distances[num_shops-1][i], distances[num_shops-1][j]));
                }
            }
        }

        // cout << fixed << setprecision(numeric_limits<double>::digits10 + 1) << tmr.elapsed() << endl;

        return min_cost;
    }
};

int main() {
    int num_shops, num_roads, num_fish;
    cin >> num_shops >> num_roads >> num_fish;

    shared_ptr<City> bitville = make_shared<City>(num_roads, num_shops, num_fish);

    for (unsigned int i = 0; i < num_shops; i++) {
        int f;
        cin >> f;
        for (unsigned int j = 0; j < f; j++) {
            int a;
            cin >> a;

            bitville->shops.at(i) |= (1 << (a-1));
        }
    }

    for (unsigned int i = 0; i < num_roads; i++) {
        int from, to, cost;
        cin >> from >> to >> cost;
        from -=1;
        to -= 1;

        bitville->costs[from][to] = cost;
        bitville->costs[to][from] = cost;

        if (bitville->neighbours.count(from) == 0) {
            bitville->neighbours[from] = { to };
        } else {
            bitville->neighbours[from].push_back(to);
        }

        if (bitville->neighbours.count(to) == 0) {
            bitville->neighbours[to] = { from };
        } else {
            bitville->neighbours[to].push_back(from);
        }
    }

    cout << bitville->synchronous_shopping() << endl;

    return 0;
}

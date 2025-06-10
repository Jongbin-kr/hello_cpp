#include <iostream>
#include <vector>
#include <cassert>
#include <utility>

using namespace std;

int calculateMST_adjlist(const vector<vector<pair<int, int>>>& adj);

int main() {
    vector<vector<pair<int, int>>> adj1 = {
        {{1, 1}, {2, 2}},
        {{0, 1}, {2, 3}},
        {{0, 2}, {1, 3}}
    };
    assert(calculateMST_adjlist(adj1) == 3);

    vector<vector<pair<int, int>>> adj2 = {
        {{1, 1}, {2, 5}, {3, 3}},
        {{0, 1}, {2, 4}, {3, 2}},
        {{0, 5}, {1, 4}, {3, 6}},
        {{0, 3}, {1, 2}, {2, 6}}
    };
    assert(calculateMST_adjlist(adj2) == 7);

    vector<vector<pair<int, int>>> adj3 = {
        {{1, 2}, {4, 10}},
        {{0, 2}, {2, 3}},
        {{1, 3}, {3, 4}},
        {{2, 4}, {4, 1}},
        {{3, 1}, {0, 10}}
    };
    assert(calculateMST_adjlist(adj3) == 10);

    cout << "Correct!" << endl;
    return 0;
}
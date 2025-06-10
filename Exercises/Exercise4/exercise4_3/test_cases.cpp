#include <iostream>
#include <vector>
#include <tuple>
#include <cassert>

using namespace std;

int calculateMST_edgelist(int N, const vector<tuple<int, int, int>>& edgeList);

void run_tests() {
    {
        int N = 3;
        vector<tuple<int, int, int>> edges = {
            {0, 1, 1}, {1, 2, 2}, {0, 2, 3}
        };
        int result = calculateMST_edgelist(N, edges);
        assert(result == 3);
    }

    {
        int N = 4;
        vector<tuple<int, int, int>> edges = {
            {0, 1, 1}, {1, 2, 1}, {2, 3, 1}, {3, 0, 1}, 
            {0, 2, 10}, {1, 3, 10}                  
        };
        int result = calculateMST_edgelist(N, edges);
        assert(result == 3);
    }

    {
        int N = 5;
        vector<tuple<int, int, int>> edges = {
            {0, 1, 2}, {0, 2, 3}, {0, 3, 3}, {0, 4, 1},
            {1, 2, 4}, {1, 3, 2}, {1, 4, 3},
            {2, 3, 5}, {2, 4, 1},
            {3, 4, 2}
        };
        int result = calculateMST_edgelist(N, edges);
        assert(result == 6);
    }

    cout << "Correct!" << endl;
}

int main() {
    run_tests();
    return 0;
}
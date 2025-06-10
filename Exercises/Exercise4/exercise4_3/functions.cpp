#include <vector>
#include <tuple>
#include <queue>
#include <functional>
#include <iostream> 

using namespace std;

vector<int> parent;

void MAKE_SET(int N) {
    parent.resize(N);
    for (int i = 0; i < N; ++i)
        parent[i] = i;
}

int FIND_SET(int x) {
    if (x != parent[x])
        parent[x] = FIND_SET(parent[x]);
    return parent[x];
}

void UNION(int u, int v) {
    int ru = FIND_SET(u);
    int rv = FIND_SET(v);
    if (ru != rv)
        parent[rv] = ru;
}

class MinPriorityQueue {
    priority_queue<
        tuple<int, int, int>,
        vector<tuple<int, int, int>>,
        function<bool(tuple<int, int, int>, tuple<int, int, int>)>
    > pq;

public:
    MinPriorityQueue(const vector<tuple<int, int, int>>& edges) : pq(
        [](const tuple<int, int, int>& a, const tuple<int, int, int>& b) {
            return get<2>(a) > get<2>(b);
        }
    ) {
        for (const auto& e : edges)
            pq.push(e);
    }

    bool empty() const {
        return pq.empty();
    }

    tuple<int, int, int> extract_min() {
        auto top = pq.top();
        pq.pop();
        return top;
    }
};


int calculateMST_edgelist(int N, const vector<tuple<int, int, int>>& edgeList) {

    MAKE_SET(N);
    int totalWeight = 0;

    MinPriorityQueue edgeQueue(edgeList);

    /*=============================================== TODO ===============================================
    Implement Kruskal's algorithm to compute the Minimum Spanning Tree (MST) total weight.
    Follow the steps below carefully:

    [1] Understand the role of global data structures:
        - `vector<int> parent` is a global vector used for Union-Find (Disjoint Set Union).
          It helps keep track of which component each node belongs to.
        - The `MAKE_SET(N)` function initializes this structure so each node is in its own set.
        - `FIND_SET(x)` returns the representative (root) of the set containing `x`, 
          using path compression to speed up future queries.
        - `UNION(u, v)` merges the sets containing nodes `u` and `v` if they are in different components.

    [2] Understand the MinPriorityQueue:
        - This is a custom class wrapping a priority queue of edges.
        - The queue always gives the edge with the **smallest weight** when `extract_min()` is called.

    [3] Kruskal’s algorithm logic:
        - While the queue is not empty:
            1. Extract the minimum weight edge `(u, v, w)`.
            2. If `FIND_SET(u) != FIND_SET(v)`, it means `u` and `v` are not yet connected:
                - Add `w` to `totalWeight`.
                - Call `UNION(u, v)` to mark `u` and `v` as connected in the MST.
        - Finally, return `totalWeight`.

    =======================================================================================================*/    
    

    return 0;
}
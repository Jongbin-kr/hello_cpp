#include <vector>
#include <stdexcept>
#include <limits>
#include <unordered_map>
#include <algorithm>
using namespace std;

class MinPriorityQueue {
private:
    vector<pair<int, int>> A;
    unordered_map<int, int> pos;
    int heapsize;

    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const { return 2 * i + 1; }
    int right(int i) const { return 2 * i + 2; }

    void minHeapify(int i) {
        int l = left(i);
        int r = right(i);
        int smallest = i;

        if (l < heapsize && A[l].first < A[smallest].first)
            smallest = l;
        if (r < heapsize && A[r].first < A[smallest].first)
            smallest = r;

        if (smallest != i) {
            swap(pos[A[i].second], pos[A[smallest].second]);
            swap(A[i], A[smallest]);
            minHeapify(smallest);
        }
    }

public:
    MinPriorityQueue() : heapsize(0) {}

    void insert(int key, int vertex) {
        A.push_back({numeric_limits<int>::max(), vertex});
        pos[vertex] = heapsize;
        ++heapsize;
        decreaseKey(vertex, key);
    }

    void decreaseKey(int vertex, int newKey) {
        int i = pos[vertex];
        if (newKey > A[i].first)
            throw invalid_argument("new key is greater than current key");

        A[i].first = newKey;
        while (i > 0 && A[parent(i)].first > A[i].first) {
            swap(pos[A[i].second], pos[A[parent(i)].second]);
            swap(A[i], A[parent(i)]);
            i = parent(i);
        }
    }

    int extractMin() {
        if (heapsize < 1)
            throw underflow_error("heap underflow");

        int minVertex = A[0].second;
        A[0] = A[heapsize - 1];
        pos[A[0].second] = 0;
        --heapsize;
        A.pop_back();
        minHeapify(0);
        return minVertex;
    }

    bool empty() const {
        return heapsize == 0;
    }
};

int calculateMST_adjlist(const vector<vector<pair<int, int>>>& adj) {
    int N = adj.size();
    vector<int> key(N, INT_MAX);
    vector<int> parent(N, -1);
    vector<bool> inMST(N, false);

    /*=============================================== TODO ===============================================
    - `key[i]` stores the cheapest connection cost of vertex `i` to the MST built so far.
    - `parent[i]` tracks the MST edge by storing the parent vertex of `i` in the MST.
    - `inMST[i]` ensures that a vertex is only added once to prevent cycles.

    1. Set key[0] = 0 to start the MST from vertex 0.
    2. Insert all vertices into the MinPriorityQueue with their key values.
    3. While the queue is not empty:
        - Extract the vertex u with the minimum key value.
        - Mark u as included in the MST.
        - For each neighbor v of u:
            - If v is not in MST and edge (u,v) has smaller weight than key[v]:
                - Update key[v] and parent[v], and call decreaseKey on v.

    4. After building the MST, sum all key[i] values and return the total.
    
    =======================================================================================================*/    
    
    return 0;
}
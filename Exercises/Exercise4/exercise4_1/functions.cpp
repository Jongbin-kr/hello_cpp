#include <iostream>
#include <vector>
#include <stdexcept>
#include <limits>
using namespace std;

template <typename T>
class PriorityQueue {
private:
    vector<T> A;
    int heapsize;
    int capacity;

    int parent(int i) const { return (i - 1) / 2; }
    int left(int i) const { return 2 * i + 1; }
    int right(int i) const { return 2 * i + 2; }

    void max_heapify(int i) {
        int l = left(i);
        int r = right(i);
        int largest = i;

        if (l < heapsize && A[l] > A[largest])
            largest = l;
        if (r < heapsize && A[r] > A[largest])
            largest = r;

        if (largest != i) {
            swap(A[i], A[largest]);
            max_heapify(largest);
        }
    }

public:
    PriorityQueue(int max_capacity) : heapsize(0), capacity(max_capacity) {
        A.reserve(max_capacity);
    }

    T max_heap_extract_max() {
        if (heapsize <= 0)
            throw out_of_range("Heap is empty");
    
    /*=============================================== TODO 1 ===============================================
     Store the maximum element (located at index 0).
     Move the last element in the heap to the root (index 0).
     Decrease the heap size.
     Call max_heapify on the root to restore the heap property.
     Return the previously stored maximum element.

    =======================================================================================================*/
    
    T maxValue = max_heap_maximum();
    A[0] = A[heapsize];
    A.pop_back();
    heapsize--;
    max_heapify(0);
    
    return maxValue;
    }
    

    T max_heap_maximum() {
        if (heapsize <= 0)
            throw out_of_range("Heap is empty");
    
    /*=============================================== TODO 2 ===============================================
    Return the maximum element, which is at the root (index 0).

    =======================================================================================================*/    
    
    return A[0];
    }
    
    
    void max_heap_increase_key(int i, T k) {
        if (k < A[i])
            throw invalid_argument("new key is smaller than current key");

    /*=============================================== TODO 3 ===============================================
     Set A[i] to the new key k.
     While the key is greater than its parent, swap it upward.
    
    =======================================================================================================*/    
    T old_key = A[i];
    A[i] = k;
    
    while (k > A[parent(i)]){
        A[i] = A[parent(i)];
        A[parent(i)] = k;
        i = parent(i);
    }
    
    
    }

    void max_heap_insert(T x) {
        if (heapsize == capacity)
            throw overflow_error("heap overflow");
    
    /*=============================================== TODO 3 ===============================================
     Increase the heap size.
     Append a dummy value (e.g., negative infinity) to the heap.
     Call max_heap_increase_key to set the correct key and fix the heap.
    
    =======================================================================================================*/    
        heapsize++;
        // Use numeric_limits<T>::lowest() for negative infinity (for numeric types)
        A.push_back(numeric_limits<T>::lowest());
        max_heap_increase_key(heapsize - 1, x);
    }

    bool empty() const {
        return heapsize == 0;
    }

    int size() const {
        return heapsize;
    }

    void print() const {
        for (int i = 0; i < heapsize; ++i)
            cout << A[i] << " ";
        cout << "\n";
    }
};

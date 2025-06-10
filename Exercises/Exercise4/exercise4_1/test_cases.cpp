#include <iostream>
#include <cassert>
#include "functions.cpp"

using namespace std;

void test_insert_and_maximum() {
    PriorityQueue<int> pq(10);
    pq.max_heap_insert(20);
    pq.max_heap_insert(10);
    pq.max_heap_insert(30);

    assert(pq.max_heap_maximum() == 30);
}

void test_extract_max() {
    PriorityQueue<int> pq(10);
    pq.max_heap_insert(15);
    pq.max_heap_insert(25);
    pq.max_heap_insert(5);

    int max1 = pq.max_heap_extract_max();
    int max2 = pq.max_heap_extract_max();
    assert(max1 == 25);
    assert(max2 == 15);
}

void test_increase_key() {
    PriorityQueue<int> pq(10);
    pq.max_heap_insert(5);
    pq.max_heap_insert(10);
    pq.max_heap_insert(3);

    pq.max_heap_increase_key(2, 12);
    assert(pq.max_heap_maximum() == 12);
}

int main() {
    test_insert_and_maximum();
    test_extract_max();
    test_increase_key();

    cout << "All tests passed. Correct!" << endl;
    return 0;
}

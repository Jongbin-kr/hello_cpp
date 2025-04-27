#include <iostream>
#include <vector>
#include <list>
using namespace std;

int main() {
    //////////////////////////
    // --- 1. 기본 array --- //
    /////////////////////////
    int arr[5] = {1, 2, 3, 4, 5};
    
    // 출력하기
    cout << "Array elementsv based on index: ";
    for (int i = 0; i < 5; ++i) {
        cout << arr[i] << " ";
    }
    cout << endl;
    
    // 이런식의 출력도 지원한다!
    cout << "Array elementsv based on range-based loop: ";
    for (auto element : arr){
        cout << element << " ";
    }
    cout << endl;
    
    
    // Array는 크기가 고정되어 있고 삽입/삭제가 직접적으로는 불가능
    
    
    
    
    
    ///////////////////////
    // --- 2. vector --- //
    ///////////////////////
    vector<int> vec = {1, 2, 3, 4, 5};

    cout << "Vector elements: ";
    for (auto element : vec) {
        cout << element << " ";
    }
    cout << endl;

    vec.push_back(6); // 끝에 삽입
    vec.erase(vec.begin() + 2); // 세 번째 요소 삭제 (index 2)

    cout << "Vector after push_back and erase: ";
    for (auto element : vec) {
        cout << element << " ";
    }
    cout << endl;


    // --- 3. list ---
    list<int> lst = {1, 2, 3, 4, 5};

    cout << "List elements: ";
    for (auto element : lst) {
        cout << element << " ";
    }
    cout << endl;

    lst.push_back(6); // 끝에 삽입
    auto it = lst.begin();
    advance(it, 2); // 세 번째 요소로 이동 (index 2)
    lst.erase(it); // 세 번째 요소 삭제

    cout << "List after push_back and erase: ";
    for (auto element : lst) {
        cout << element << " ";
    }
    cout << endl;

    return 0;
}

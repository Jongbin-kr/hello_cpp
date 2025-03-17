#include <iostream>

int main() {
    // #### 레퍼런스의 배열 ####
    // int a;
    // int b;
    
    // int& arr[2] = {a, b};
    /*
    레퍼런스의 배열은 존재할 수 없다. 배열은 주소값을 할당받는데, 이는 곧 항상 메모리를 차지한다는 것이다.
    그러나 레퍼런스는 특별한 경우가 아닌 이상 메모리 공간을 차지하지 않는다.
    */
    
    
    
    // #### 배열의 레퍼런스 ####
    int arr[3] = {1, 2, 3};
    int(&ref)[3] = arr;
    
    ref[0] = 10;
    ref[1] = 20;
    ref[3] = 30;
    
    std::cout << arr[0] << arr[1] << arr[2] << std::endl;
    return 0;
}
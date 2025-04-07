#include <iostream>

int main() {
    // int& ref = 4;   // 4라는 상수값은 리터럴이기에 참조할 수 없다.
    const int& ref = 4;
    int a = ref; // same as `a = 4`
    
    std::cout << ref << std::endl;
}
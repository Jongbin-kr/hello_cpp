#include <iostream>

int main() {
    int x;
    int& y = x;  // y는 x의 참조자이구
    int& z = y;  // z도 결국 x의 참조자이다.
    
    x = 1;
    std::cout << "x : " << x << " y: " << y << " z: " << z << std::endl << std::endl;
    
    y = 2;
    std::cout << "x: " << x << " y : " << y << " z: " << z << std::endl;
    
    z = 3;
    std::cout << "x: " << x << " y: " << y << " z: " << z << std::endl;
}   

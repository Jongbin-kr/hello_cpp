#include <iostream>

int main(){
    
    int x = 5;
    int& ref = x;
    std::cout << x << " " << ref << std::endl;
    
    x = 10;
    ref = 15;
    std::cout << x << " " << ref << std::endl;
    
    x = 20;
    // ref = ??
    std::cout << x << " " << ref << std::endl;
    
    
    // const reference
    int y = 1;
    const int& refy = y;
    std::cout << y << " " << refy << std::endl;
    
    y = 10;
    std::cout << y << " " << refy << std::endl;
    
    // ERROR (const reference) cannot change the de-referenced value.
    // refy = 20;
    // std::cout << y << " " << refy << std::endl;
    
    
    
    
    
    return 0;
}
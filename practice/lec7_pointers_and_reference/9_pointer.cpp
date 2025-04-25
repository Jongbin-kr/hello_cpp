#include <iostream>


int main(){
    int x = 5;
    int *ptr = &x;
    
    std::cout << "&x: " << &x << std::endl;
    std::cout << "ptr: " << ptr << std::endl;
    std::cout << "&ptr: " << &ptr << std::endl;
    std::cout << "*ptr: " << *ptr << std::endl;
    
    return 0;
}
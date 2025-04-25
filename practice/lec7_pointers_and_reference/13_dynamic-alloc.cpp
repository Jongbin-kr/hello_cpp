#include <iostream>

int main(){
    int *array;
    int n;
    std::cin >> n;
    
    array = new(std::nothrow) int [n];
    if (array == nullptr){
        std::cerr << "Memory alloc failed" << std::endl;
        return 1;
    }
    delete[] array;
    
    return 0;
}
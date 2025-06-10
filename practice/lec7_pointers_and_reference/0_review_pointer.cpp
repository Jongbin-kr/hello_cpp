#include <iostream>

int main(){
    
    // int* arr = new int[3]{1,2,3};
    // std::cout << arr[0] << std::endl;
    // std::cout << arr[1] << std::endl;
    // std::cout << arr[2] << std::endl;
    
    // std::cout << &arr[0] << std::endl;
    // std::cout << &arr[1] << std::endl;
    // std::cout << &arr[2] << std::endl;
    
    
    
    // dynamic array
    int *darr = new int[3]{1,2};

    std::cout << darr << std::endl;
    std::cout << darr+1 << std::endl;
    std::cout << darr+2 << std::endl;
    std::cout << darr+3 << std::endl;
    
    std::cout << *(darr) << std::endl;
    std::cout << *(darr+1) << std::endl;
    std::cout << *(darr+2) << std::endl;
    std::cout << *(darr+3) << std::endl;
    
    int** darr2d = new int*[2];
    for (int i=0; i<2; ++i){
        darr2d[i] = new int[2];
    }
    
    
    
    return 0;
}
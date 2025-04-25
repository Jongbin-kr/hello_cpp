#include <iostream>

int main(){
    
    int arr[3] = {1,2,3};
    // for (auto i: arr){
    for (int i = 0; i < 3; i++){
        std::cout << i << std::endl;
        std::cout << "arr[i]: " << arr[i] << std::endl;
        std::cout << "&arr[i]: " << &arr[i] << std::endl;
        
    }
    
    // 25p
    std::cout << std::endl << std::endl;
    std::cout << "arr: " << arr << std::endl;
    std::cout << "&arr[0]: " << &arr[0] << std::endl;
    std::cout << "*arr: " << *arr << std::endl;
    std::cout << "&(*arr): " << &(*arr) << std::endl;
    std::cout << "&arr: " << &arr << std::endl;
    
    return 0;
}
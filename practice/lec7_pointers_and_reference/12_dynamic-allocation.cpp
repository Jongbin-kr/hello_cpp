#include <iostream>
#include <new>

int main(){
    int* array;
    int n;
    std::cin >> n;
    
    try {
        array = new int[n];
        std::cout << std::endl;
        
    }catch (const std::bad_alloc& e){
        std::cerr << "bad alloc" << e.what() << std::endl;
        return 1;
    }
    
    
    return 0;
}
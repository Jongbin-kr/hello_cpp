#include <iostream>
#include <vector>

int main(){
    
    std::vector<int> vec = {1,2,3};
    for (int n : vec){
        std::cout << n << std::endl;
        std::cout << n+1 << std::endl << std::endl;
    }
    
    return 0;
}
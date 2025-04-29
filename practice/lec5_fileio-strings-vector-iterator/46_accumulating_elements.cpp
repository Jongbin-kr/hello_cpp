#include <iostream>
#include <vector>
#include <numeric>

// Custom function to multiply elements
int custom_accumulate(int a, int b);


int main(){
    std::vector<int> vec = {1,2,3,4,5};
    
    // sum all elements in the vector
    auto sum = std::accumulate(vec.begin(), vec.end(), 0);
    std::cout << sum << std::endl;
    
    
    // NOTE how to do custom accumulation

    
    auto product = std::accumulate(vec.begin(), vec.end(), 1, custom_accumulate);
    std::cout << product << std::endl;
    
    return 0;
    
    
}

int custom_accumulate(int a, int b) {
    return a * b;
}
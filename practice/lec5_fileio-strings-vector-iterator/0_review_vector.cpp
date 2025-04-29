#include <iostream>
#include <vector>

int main(){
    
    std::vector<int> vec = {1,2,3,4,5};
    for (auto element : vec){ std::cout << element << " "; } std::cout << std::endl;
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    
    
    std::cout << *vec.begin() << std::endl; // Print the first element of the vector
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    
    
    vec.pop_back();
    for (auto element : vec){ std::cout << element << " "; } std::cout << std::endl;
    std::cout << vec.size() << " " << vec.capacity() << std::endl;
    
    
    vec.erase(vec.begin());
    for (auto element : vec){ std::cout << element << " "; } std::cout << std::endl;

    
    
    return 0;
}
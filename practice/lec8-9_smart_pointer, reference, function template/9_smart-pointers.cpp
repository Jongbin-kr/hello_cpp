#include <iostream>
#include <vector>
#include <memory>

int main(){
    std::unique_ptr<std::vector<int>> vecPtr(new std::vector<int>());
    
    vecPtr->push_back(10);
    vecPtr->push_back(20);
    (*vecPtr)[0] = 30;
    for(auto item : *vecPtr){
        std::cout << item << std::endl;
    }
    
    auto unique_ptr2 = std::make_unique<std::vector<int>>();
    auto sharedPtr = std::make_shared<std::vector<int>>();
    
    return 0;
}
#include <iostream>
#include <vector>
// #include <memory>

int main(){
    int a = 5; 
    std::unique_ptr<int> sPtr(new int(42));
    std::cout << *sPtr << std::endl;
    
    std::vector<int> vec = {1,2,3};
    auto sptr2 = std::make_unique<std::vector<int>>(std::initializer_list<int>{1,2,3});
    std::cout << sptr2 << std::endl;

};
#include <iostream>
#include <vector>

int main(){
    std::vector<int>* myVector = new std::vector<int>();
    // std::cout << "First element: " << (*myVector)[0] <<std::endl; // ERROR 이렇게 하면 초기화되지 않은 벡터의 값을 출력하라고 하는거니까 오류가 생김
    
    (*myVector).push_back(10);
    myVector->push_back(20);
    std::cout << "First element: " << (*myVector)[0] << std::endl;
    std::cout << "Second element: " << (*myVector)[1] << std::endl;
    
    // range-based for loop
    for (auto elem : *myVector){
        std::cout << elem << std::endl;
    }
    
    std::cout << "iterator" << std::endl;;
    for (std::vector<int>::iterator it = (*myVector).begin(); it != myVector->end(); ++it){
        std::cout << *it << std::endl;
    }
    delete myVector;
    
    
    return 0;
}
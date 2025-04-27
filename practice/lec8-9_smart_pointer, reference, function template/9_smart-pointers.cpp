#include <iostream>
#include <vector>
#include <memory>

int main(){
    // 1. 직접 생성자를 사용하는 경우
    std::unique_ptr<std::vector<int>> unqiue_ptr1(new std::vector<int>);

    // 2. 명시적으로 생성자를 호출하는 경우
    auto unique_ptr2 = std::unique_ptr<std::vector<int>>(new std::vector<int>);
    
    // 3. make unique 사용
    auto unique_ptr3 = std::make_unique<std::vector<int>>();
    

    unqiue_ptr1->push_back(10);
    unqiue_ptr1->push_back(20);
    (*unqiue_ptr1)[0] = 30;
    for(auto item : *unqiue_ptr1){
        std::cout << item << std::endl;
    }    
    
    
    // share Ptr: 다른 share ptr에도 같은 포인터를 할당할 수 있다.
    auto sharedPtr = std::make_shared<std::vector<int>>();
    std::shared_ptr<std::vector<int>> sharedPtr2 = sharedPtr;
    
    sharedPtr->push_back(1);
    sharedPtr2->push_back(2);
    
    for (auto element : *sharedPtr){
        std::cout << element << std::endl;
    }

    for (auto element : *sharedPtr2){
        std::cout << element << std::endl;
    }
    
    
    return 0;
}
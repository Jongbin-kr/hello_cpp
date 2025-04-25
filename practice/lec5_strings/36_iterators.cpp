#include <iostream>
#include <vector>

int main(){
    
    std::vector<int> vec = {1,2,3,4,5};
    
    
    for (std::vector<int>::iterator it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << std::endl; // !! iteretor는 포인터와 아주 유사하기에 de-referencing이 가능하다! 
                                       // WARNING 단, iterator가 포인터 자체는 아님!!!!
    }
    
    
    // NOTE 이런 식으로 iterator를 밖에 정의할 수 있고, 이 경우 for문의 첫번째는 빈 코드!
    std::vector<int>::iterator it2 = vec.begin();
    for (; it2 != vec.end(); ++it2){
        std::cout << *it2 << std::endl; // iterator는 포인터와 유사하여 de-referencing이 가능하다!
                                    // 단, iterator가 포인터 자체는 아님!!!!
    }
    
    return 0;
}
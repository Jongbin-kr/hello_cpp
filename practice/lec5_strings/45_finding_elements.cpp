#include <iostream>
#include <vector>
#include <algorithm> // for std::find

int main(){
    std::vector<int> vec = {1,2,3,4,5};
    
    auto finder_iterator = std::find(vec.begin(), vec.end(), 3);  // !! find는 iterator를 반환한다. 내부적으로 begin에서 end까지 찾아가면서 3을 찾는다.
    
    if (finder_iterator!= vec.end()){
        std::cout << "Found 3 at index: " << std::distance(vec.begin(), finder_iterator) << std::endl;
    }
    else{
        std::cout << "Not found" << std::endl;
    }
    
    return 0;
}
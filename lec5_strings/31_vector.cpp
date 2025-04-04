#include <iostream>
#include <vector>

int main(){
    //Direct list initialization
    std::vector<int> vec1 = {1, 2, 3, 4, 5};  // !! you need to declare datatye. It means you can only have **one datatype in one vector**
    
    // Initialize vector from an array
    // cpp array also can contain only one datatype.
    int arr[] = {6, 7, 8, 9, 10};
    std::vector<int> vec2(
        std::begin(arr), std::end(arr));    // array의 시작 주소와 끝 주소를 넣어준다.
        
    
    //with specific size
    std::vector<int> vec3(5,100);
    
    
    return 0;
}
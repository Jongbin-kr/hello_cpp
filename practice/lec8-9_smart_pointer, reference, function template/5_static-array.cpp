#include <iostream>
#include <list>


int main(){
    // array
    int arr[3] = {30,40,50};
    // std::cout << arr <<std::endl;
    // std::cout << arr+1 <<std::endl; // 
    // std::cout << *arr <<std::endl;
    // std::cout << &(*arr) <<std::endl;
    // std::cout << (*arr)+1 <<std::endl;
    // std::cout << *(arr+1) <<std::endl;
    
    
    // range-based for loop is supported for array
    // NOTE: array는 기본적으로 인덱스에 기반해서만 접근 가능하지만, 편의를 위해 이렇게 접근하는 것도 지원해준다~
    std::list<int> lst;
    for (auto element : arr){
        std::cout << "arr elem: " << element << std::endl;
        lst.push_front(element);
    }
    
    for (auto element : lst){
        std::cout << "lst elem: " << element << std::endl;
    }
    
    
    // multi-dimensional array
    int arr2d[2][2] = {1,2,3,4};  // [1,2]
                                  // [3,4]

    // 행(row)와 열(column)의 크기 계산
    int rows = sizeof(arr2d) / sizeof(arr2d[0]);
    int cols = sizeof(arr2d[0]) / sizeof(arr2d[0][0]);

    for (int i = 0; i < rows; i++) {
        for (int j = 0; j < cols; j++) {
            std::cout << arr2d[i][j] << " ";
        }
        std::cout << std::endl;
    }
        
    
    return 0;
}
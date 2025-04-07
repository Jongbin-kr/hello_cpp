#include <iostream>

int main(){
    
    int *aPtr = new int(5);
    // NOTE 만약에 int 5개를 동적으로 할당하려면 int *aPtr = new int[5]

    std::cout << "aPtr: " << aPtr << std::endl;
    std::cout << "*aPtr: " << *aPtr << std::endl;
    std::cout << "&aPtr: " << &aPtr << std::endl;
    
    
    // Dynamic array
    int *arr = new int[3]{1,2,3};
    // std::cout << arr[0] << std::endl;
    
    // for (auto i : *arr){  // ERROR 동적 배열은 배열의 크기를 알 수 없으므로 range-base loop를 사용하지 못한다.
    for (int i = 0; i < 3; i++){
        std::cout << i << std::endl;
        std::cout << "i'th arr: " << arr[i] << std::endl;
        std::cout << "i'th &arr: " << &arr[i] << std::endl; // NOTE 주소값이 4씩 증가한다! 
    }
    
    for (int i = 0; i < 3; i++){
        std::cout << i <<std::endl;
        std::cout << "arr + i: " << arr + i << std::endl;
        std::cout << "*(arr + i): " << *(arr+i) << std::endl; // NOTE *(arr+i) == arr[i]. 둘이 같은 표현이다.
    }
    
    
    

    
    return 0;
}
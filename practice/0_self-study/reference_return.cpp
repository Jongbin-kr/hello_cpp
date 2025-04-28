#include <iostream>

int& getElement(int arr[], int index){
    return arr[index];
}

int getElement2(int arr[], int index){
    return arr[index];
}

int main(){    
    
    int arr[5] = {1,2,3,4,5};
    
    getElement(arr, 4) = 10;
    for (auto element : arr){
        std::cout << element << std::endl;
    }
    std::cout << getElement(arr, 4) << std::endl;
    
    
    
    // getElement2(arr,4) = 20; // ERROR
    std::cout << getElement2(arr, 4) << std:: endl;
    
    return 0;
}
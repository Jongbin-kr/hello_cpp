#include <iostream>

// 인자로 레퍼런스를 받는 경우
int change_val1(int& p){ 
    std::cout << p << std::endl;
    p = 1;
    std::cout << p << std::endl;
    return 0;
}

// 인자로 포인터를 받는 경우
int change_val2(int *p){
    std::cout << *p << std::endl;
    *p = 2;
    std::cout << *p << std::endl;
    return 0;
}


// 인자로 그냥 값을 받는 경우 (call by value)
int change_val3(int p){
    std::cout << p << std::endl;
    p = 3;
    std::cout << p << std::endl;
    return 0;
}


int main(){
    int number = 5;
    
    std::cout << number << std::endl;
    change_val1(number);
    std::cout << number << std::endl;
    std::cout << "\n" << std::endl;
    
    std::cout << number << std::endl;
    change_val2(&number);
    std::cout << number << std::endl;
    std::cout << "\n" << std::endl;
    
    std::cout << number << std::endl;
    change_val3(number);
    std::cout << number << std::endl;
    std::cout << "\n" << std::endl;
    
}
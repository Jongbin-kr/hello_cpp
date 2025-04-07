#include <iostream>

int function(){
    int a = 2;
    return a;
}

int& function2(){
    int a = 2;
    return a;
}


int main(){
    int b = function();
    std::cout << b << std::endl;
    
    
    int c = function2();
    c = 3;
    
    
    return 0;
}
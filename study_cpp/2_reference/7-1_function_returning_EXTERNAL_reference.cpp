#include <iostream>

int& function(int& a){
    a = 5;
    return a;
}

int main(){
    int b = 2;
    std::cout << b << std::endl << std::endl;
    
    
    // c는 function 속 a가 참조하는 b를 그대로 계속 참조한다.
    int c = function(b); // c는 그냥 변수이므로, b에 영향을 안준다.
    std::cout << b << std::endl;
    std::cout << c << std::endl;
    
    c = 10;
    std::cout << b << std::endl;
    std::cout << c << std::endl << std::endl;
    
    
    
    int& d = function(b); // d는 레퍼런스이므로,b의 값도 바뀐다.
    std::cout << b << std::endl;
    std::cout << d << std::endl;
    
    d = 20;
    std::cout << b << std::endl;
    std::cout << d << std::endl;
    
    
    return 0;
}
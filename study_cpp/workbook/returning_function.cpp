#include <iostream>

int function(){
   char a = 'A';    // 분명 문자형으로 받았지만
//    return a;     // 숫자형을 리턴한다.
   return (int)a;   // 명시적으로 형변환을 해줄 수 있다.
}

int main() {
    int a = function();
    std::cout << a << std::endl;
    
}
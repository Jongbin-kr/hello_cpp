#include <iostream>

int function(){
    int a = 5;
    return a;
}

int main(){
    const int& c = function();
    std::cout << "c: " << c << std::endl;
    /*
    원칙상 함수의 리턴값은 해당 문장이 끝나면 소멸되는 것이 정상입니다. 
    따라서 기존에 int& 로 받았을 때에는 컴파일 자체가 안되었습니다. 
    하지만 예외적으로 상수 레퍼런스로 리턴값을 받게 되면 해당 리턴값의 생명이 연장됩니다. 
    그리고 그 연장되는 기간은 레퍼런스가 사라질 때 까지 입니다.
    */
    return 0;
}
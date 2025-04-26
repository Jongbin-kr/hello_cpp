#include <iostream>


template <typename T>
void mySwap(T &x, T &y){
    T temp = x;
    x = y;
    y = temp;
}

template <typename T, typename U>
void mySwap2(T &x, U &y){
    T temp = x;
    x = y;
    y = temp;
}

// NOTE: C++14 이상에서는 다음도 가능! 템플릿 함수의 축약형
// void mySwap3(auto &x, &auto &y);  // ERROR: 이렇게 선언만 먼저 해주는 건 불가능하다.
void mySwap3(auto &x, auto &y){
    auto temp = x;
    x = y;
    y = temp;
}

int main(){
    int a = 5;
    int b = 10;
    std::cout << "a: " << a << ", b: " << b << std::endl;
    mySwap<int>(a, b);
    std::cout << "a: " << a << ", b: " << b << std::endl;
    
    double c = 2.5;
    double d = 7.5;
    std::cout << c << " " << d << std::endl;
    mySwap<double>(c, d);
    std::cout << c << " " << d << std::endl;
    
    mySwap(c, d);  // NOTE: double 타입인 게 자명하므로!
    std::cout << c << " " << d << std::endl;
    
    std::cout << "C: " << c << ", a: " << a << std::endl;
    // mySwap(c, a);  // ERROR: 하나의 타입만 가능하군! 타입 name을 두 개로 하면 가능하다!
    mySwap2(c, a);  // NOTE: 함수 템플릿을 정의할 때, 타입 name을 두 개로 하면 가능하다!
    std::cout << "C: " << c << ", a: " << a << std::endl;
    
    mySwap3(c, a); 
    std::cout << "C: " << c << ", a: " << a << std::endl;
    
    
    return 0;
}
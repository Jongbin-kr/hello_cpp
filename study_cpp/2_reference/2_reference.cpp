#include <iostream>

int main (){
    int a = 3;
    
    int& another_a = a; // 참조자를 만들었다! 
                        
    another_a = 5;      // another_a에 하는 모든 작업은 a에도 적용딘다.
    
    std::cout << "a : " << a << std::endl;
    std::cout << "another_a : " << another_a << std::endl;
    
    return 0;
}

/*
레퍼런스와 포인터의 차이점?
- 레퍼런스는 선언시 반드시 누구의 별명이 될 것인지 지정해야한다. (포인터는 일단 선언 후, 추후에 포인팅할 수 있다)
- 레퍼런스는 한 번 별명이 되면 절대로 다른 이의 별명이 될 수 없다. (포인터는 바꿀 수 있다)
- 메모리 공간을 차지하지 않는 경우도 있다. (포인터는 항상 차지한다)
*/
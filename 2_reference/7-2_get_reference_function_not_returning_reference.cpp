#include <iostream>

int function(){
    
    int a = 5;
    return a;
}

int main(){
    // int& c = function();    // a의 값이 function이 사라지면서 같이 사라지기에, 참조가 불가능하다.
    return 0;
}
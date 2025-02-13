#include <iostream>

#include "header1.h"
#include "header2.h"

// header1 네임스페이스 선언
namespace header1{
    int func1(){
        std::cout << foo << std::endl;
        
        return 0;
    }
}


// 네임스페이스 명시적 선언 X
int func2(){
    std::cout << header1::foo << std::endl;
    
    return 0;
}


using header1::foo;
int func3 () {
    std::cout << header2::foo << std::endl;
    std::cout << foo+1 << std::endl;
    
    return 0;
}


int main() {
    header1::func1();
    func2();
    func3();
    
    
    // quiz2
    std::cout << "hi" << std::endl
              << "my name is "
              << "Psi" << std::endl;
              
    return 0;
}
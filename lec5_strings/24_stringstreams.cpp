#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::stringstream parser("42,3.14,Hello World!");
    // ?? comma 대신 공백이 나오면 ignore Char은 필요없다
    // ?? 그럼 중간에 구분자로 다른 숫자를 쓸 수도 있겠지?
    int intValue;
    
}
#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::stringstream parser("42,3.14,Hello World!");
    // ?? comma 대신 공백이 나오면 ignore Char은 필요없다
    // ?? 그럼 중간에 구분자로 다른 숫자를 쓸 수도 있겠지?
    int intValue;
    double doubleValue;
    std::string strValue;
    char ignoreChar;
    
    parser >> intValue >> ignoreChar >> doubleValue >> ignoreChar;
    std::getline(parser, strValue);
    
    // 이렇게 하면, 공백 앞의 Hello만 받는다.
    // parser >> intValue >> ignoreChar >> doubleValue >> ignoreChar >> strValue;
    
    std::cout << intValue << doubleValue << strValue << std::endl;
    
    
    
    parser.str("77 88 99\n123");
    parser.clear();  // 앞서 문자열을 끝까지 읽어서 EOF 상태에 도달했으므로, clear해서 EOF 상태를 초기화해줘야한다.
    parser >> intValue;
    std::cout << intValue << std::endl;

    parser >> intValue;
    std::cout << intValue << std::endl;
    
    parser >> intValue;
    std::cout << intValue << std::endl;
    
}
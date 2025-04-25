#include <iostream>
#include <sstream>
#include <string>

int main(){
    std::stringstream parser("42,3.14,Hello World!");
    int intValue;
    double doubleValue;
    std::string strValue;
    char ignoreChar;
    
    parser >> intValue >> ignoreChar >> doubleValue >> ignoreChar;
    // std::getline(parser, strValue);
    std::cout << intValue << doubleValue << std::endl;
    std::cout << intValue << doubleValue << strValue << std::endl;
    
    
    
    parser.str("77 88 99\n123");
    // parser.clear();  // !! 여기선 앞선 문자열을 **끝까지 읽지 않아서 EOF 상태에 도달하지 않았으므로, clear하지 않아도 된다!!!
    parser >> intValue;
    std::cout << intValue << std::endl;

    parser >> intValue;
    std::cout << intValue << std::endl;
    
    parser >> intValue;
    std::cout << intValue << std::endl;

    parser >> intValue;
    std::cout << intValue << std::endl;
}
#include <iostream>
#include <string>

int main(void){
    std::string myStr;
    
    std::getline(std::cin, myStr);
    std::cout << myStr;
    
    return 0;
}
#include <iostream>
#include <string>

int main(){
    std::string str1 = "Apple";
    std::string str2 = "Banana";
    
    std::cout << str1.compare(str2) << std::endl;
    std::cout << str2.compare(str1) << std::endl;
    std::cout << str1.compare(str1) << std::endl;
    
    return 0;
}
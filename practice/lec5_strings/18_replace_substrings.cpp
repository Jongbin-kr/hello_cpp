#include <iostream>
#include <string>

int main(){
    
    std::string str = "Data Science";
    std::cout << str << std::endl;
    
    // std::string str = str.replace(0, 4, "Bio");  
    // 이렇게 재할당하는 건 불가능하지만,
    str.replace(0, 4, "Bio");
    std::cout << str << std::endl;
    
    return 0;
}
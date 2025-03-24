#include <iostream>
#include <string>


int main(void){
    
    std::string fullName = "Data Science";
    
    size_t pos1 = fullName.find("Science");  //  NOTE size_t를 쓰는 이유는 unsigned_int로 메모리 크기 표현에 최적화.
    std::cout << pos1 << std::endl;
    
    size_t pos2 = fullName.find("Sci\\");
    std::cout << pos2 << std::endl;   

    size_t pos3 = fullName.find("Scientific");
    std::cout << pos3 << std::endl;

    size_t pos4 = fullName.find("ence");
    std::cout << pos4 << std::endl;
    
    return 0;
}
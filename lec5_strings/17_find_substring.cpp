#include <iostream>
#include <string>
#include <typeinfo>

int main(){
    
    std::string fullName = "Data Science";
    // size_t pos = fullName.find("Science"); // size_t?
    int pos = fullName.find("Science"); // why use size_t, not int? overflow & unsigned int!
    std::cout << typeid(fullName.find("Science")).name() << std::endl;  // return "m", unsigned integer, type
    std::cout << typeid(pos).name() << std::endl;   // return "i", int, type
    
    if (pos != std::string::npos){
        std::cout << "Found 'science' at position: " << pos << std::endl;
    }
    
    
    return 0;
}
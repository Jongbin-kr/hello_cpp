#include <iostream>
#include <string>
#include <sstream>

int main(){
    
    std::string fullName = "Data Science";
    std::cout << fullName << std::endl;
    
    fullName += " sucks";
    std::cout << fullName << std::endl;
    
    size_t pos = fullName.find("Science");  
    if (pos != std::string::npos){std::cout << "found at " << pos << std::endl;}
    
    std::cout << fullName.substr(5, 3) << std::endl;
    std::cout << std::string("Protein").substr(0,3) << std::endl;
    
    
    std::string number = "42";
    std::cout << number <<std::endl;
    
    int intNum = std::stoi(number);
    std::cout << intNum <<std::endl;
    
    
    
    // string stream
    std::cout << "===== sstream =====" << std::endl;
    std::stringstream ss;
    ss << 100;
    ss << 3.14;
    ss << "Hello";
    std::cout << ss.str() << std::endl;
    
    // stringstreams
    std::stringstream parser("42,3.14,Hello");
    int n;
    double pi;
    std::string str;
    char ignoreChar;
    
    parser >> n >> ignoreChar >> pi >> ignoreChar;
    std::getline(parser, str);
    
    std::cout << n << ignoreChar << pi << str << std::endl;
    
    std::cout << parser.str() << std::endl;
    
    
    
    
    return 0;
}
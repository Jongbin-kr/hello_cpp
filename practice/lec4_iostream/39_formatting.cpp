#include <iostream>
#include <iomanip>

int main(){
    
    double pi = 3.1415922949;
    std::cout << pi << std::endl;
    std::cout << (int)pi << std::endl;
    std::cout << std::setprecision(4) << pi << std::endl;
    std::cout << std::setprecision(4) << std::fixed << pi << std::endl;
    
    std::cout << "==================" << std::endl;
    std::cout << std::setfill('0') << pi << std::endl;
    std::cout << std::setfill('0') << std::setw(5) << pi << std::endl;
    std::cout << std::setfill('0') << std::setw(6) << pi << std::endl; // .까지 출력한 개수로 치는구나.ㅣ
    std::cout << std::setfill('0') << std::setw(7) << pi << std::endl;  
    std::cout << std::setfill('0') << std::setw(8) << pi << std::endl;  
    std::cout << std::setfill('0') << std::setw(10) << pi << std::endl;  
    std::cout << std::setfill('0') << std::setw(10) << std::left << pi << std::endl;  
    
    
    
    
};
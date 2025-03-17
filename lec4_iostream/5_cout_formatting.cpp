#include <iostream>
#include <iomanip>

int main(){
    double pi = 3.141592;
    std::cout << "Pi with 2 decimal place: " << std::setprecision(2) << pi << std::endl;
    std::cout << "Pi with 2 decimal place: " << pi << std::setprecision(2) << std::endl;    // 순서가 무관한가?
    std::cout << "Pi with 2 decimal place: " << pi << std::setprecision(2) <<pi << pi + 1 << std::endl;    // 순서가 무관한가?
    
    return 0;
}
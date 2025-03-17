#include <iostream>

int main(void){
    int number;
    std::cout << "Enter a number: ";
    if (!(std::cin >> number)) {
        std::cout << "That was not a number!" << std::endl;
        std::cin.clear();
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    }
    
    return 0;
}
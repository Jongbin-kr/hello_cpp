#include <iostream>

int main () {
    int lucky_number = 3;
    
    std::cout << "Guess my secret number" << std::endl;
    
    int user_input;
    
    while (true) {
        std::cout << "입력: ";
        std::cin >> user_input;
        
        if (lucky_number == user_input) {
            std::cout << "You are correct" << std::endl;
            break;
            
        } else {
            std::cout << "Redrum" << std::endl;
        }
    }
    
    return 0;
}
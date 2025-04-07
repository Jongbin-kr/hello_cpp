#include <iostream>
#include <fstream>
#include <string>

int main(){
    std::ifstream file("number.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    
    int number;
    while (file >> number){   // 마치 cin처럼 공백, 개행문자를 기준으로 하나씩 읽어온다!
        std::cout << number << std::endl;
    }
    file.close();
    return 0;
}

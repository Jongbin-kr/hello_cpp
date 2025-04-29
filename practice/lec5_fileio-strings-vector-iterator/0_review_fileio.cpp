#include <iostream>
#include <fstream>
#include <string>

int main(){
    // std::ifstream file("data.txt");
    // if (!file.is_open()){
    //     std::cerr << "Failed to open" << std::endl;
    //     return 1;
    // }
    
    // std::string line;
    // while (std::getline(file, line)){
    //     std::cout << line << std::endl;
    // }
    // file.close();
    
    std::ifstream file2("number.txt");
    int number;
    while (file2 >> number) {std::cout << number << std::endl;}
    file2.close();
    
    return 0;
};
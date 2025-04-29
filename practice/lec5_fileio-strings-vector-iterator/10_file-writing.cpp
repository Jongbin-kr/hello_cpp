#include <iostream>
#include <fstream>

int main(){
    std::ofstream file("output.txt");
    if (!file.is_open()) {
        std::cerr << "Failed to open file" << std::endl;
        return 1;
    }
    
    file << "Hello, Data Science!" << std::endl;
    file << "Hello, Data Science!" << std::flush;
    file << "Hello, Data Science!" << "\n" << std::flush;
    return 0;
}
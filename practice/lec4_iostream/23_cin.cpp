#include <iostream>
// #include <string>

int main(){
    
    // cin chaining
    int age;
    double salary;
    char grade;
    
    std::cin >> age >> salary >> grade;
    std::cout << age << " " << salary << " " << grade;
    
    
    //\ error handling
    int number;
    if (!(std::cin >> number)){
        std::cout << "That was not a number!" << std::endl;
        std::cin.clear();    // clear the error state
        std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');   // ignore the rest of the line
    }
    
    std::cout << number << std::endl;
    
    
    // getline
    std::cout << "Enter your age: " << std::endl;
    std::cin >> age;
    // std::cin.ignore(std::numeric_limits<std::streamsize>::max(), '\n');
    
    std::string name;
    std::cout << "Enter your name: " << std::endl;
    std::getline(std::cin, name);
    
    std::cout << name << " " << age;
    
    
    
    
    
    return 0;
}
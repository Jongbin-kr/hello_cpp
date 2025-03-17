#include <iostream>
#include <string>
using namespace std;

int main(){
    string myString = "Hello, World!";
    cout << "Initial size: " << myString.size() << endl;
    cout << "Initial capacity: " << myString.capacity() << endl;
    cout << "Initial memory address: " << (void*)myString.c_str() << endl;
    
    // myString += "!";
    myString += '!';
    cout << myString << endl;
    cout << "After appending size: " << myString.size() << endl;
    cout << "After appending capacity: " << myString.capacity() << endl;
    cout << "After appending memory address: " << (void*)myString.c_str() << endl;
}
#include <iostream>
#include <string>
using namespace std;

int main(){
    string myString = "Hello, World!";
    cout << "Initial size: " << myString.size() << endl;
    cout << "Initial capacity: " << myString.capacity() << endl;
    cout << "Initial memory address: " << (void*)myString.c_str() << endl;
    
    
    
    // myString += "!";  // 문자열을 붙일 수도 있긴 하지만, 문자열 -> 문자로 변환해야하기에 그냥 single quote로 문자를 붙이는 것이 더 효율적.
    // myString += '!';    // 즉, +=는 기존 객체를 수정하지만, =을 사용하면 새로운 객체를 생성하여 재할당할 수 있습니다
    myString = myString + "!";
    
    // NOTE
    // 같은 이름의 변수를 cpp에서는 재선언이 불가능하지만, 파이썬에서는 재선언도 가능한 한편,
    // 같은 변수에 재할당하는 건 cpp이든 파이썬이든 모두 가능하다!
    cout << myString << endl;
    cout << "After appending size: " << myString.size() << endl;
    cout << "After appending capacity: " << myString.capacity() << endl;
    cout << "After appending memory address: " << (void*)myString.c_str() << endl;
    
    
    myString += "Bye Bye bad world man!";
    cout << myString << endl;
    cout << myString.size() << endl;
    cout << myString.capacity() << endl;
    cout << (void*)myString.c_str() << endl;
    
}
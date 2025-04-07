// https://chatgpt.com/c/67d6699f-670c-8003-a114-b9bef122b44d
#include <iostream>
#include <limits>

using namespace std;

int main(void){
    int age;
    double salary;
    char grade;
    
    cin >> age;

    if (cin.fail()) { // 오류 발생 시
        cout << "ERROR 1" << endl;
        cin.clear(); // 오류 플래그 초기화
        cin.ignore(numeric_limits<streamsize>::max(), ' '); // 잘못된 입력 무시
    }
    
    // 입력으로 `20abc 1.5 a`를 받으면?
    // 출력은 20 a 0 이렇게 나온다. 오류는 ERROR 3가 발생 x. 
    cin >> grade;
    if (cin.fail()) { // 오류 발생 시
        cout << "ERROR 2" << endl;
        cin.clear(); // 오류 플래그 초기화
        cin.ignore(numeric_limits<streamsize>::max(), ' '); // 잘못된 입력 무시
    }
    
    
    cin >> salary;
    if (cin.fail()) {
        cout << "ERROR 3" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), ' ');
    }
    
    cout << "Age:" << age << endl;
    cout << "Grade:" << grade << endl;
    cout << "Salary:" << salary << endl;

    return 0;
}

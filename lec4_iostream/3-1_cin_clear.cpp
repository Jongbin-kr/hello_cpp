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
        cin.clear(); // 오류 플래그 초기화
        cin.ignore(numeric_limits<streamsize>::max(), ' '); // 잘못된 입력 무시
    }

    cin >> salary;

    if (cin.fail()) {
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), ' ');
    }

    cin >> grade;

    cout << "Age:" << age << endl;
    cout << "Salary:" << salary << endl;
    cout << "Grade:" << grade << endl;

    return 0;
}

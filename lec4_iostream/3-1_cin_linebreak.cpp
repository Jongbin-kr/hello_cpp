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
        cin.ignore(numeric_limits<streamsize>::max(), '\n'); // 잘못된 입력 무시
    }

    cin >> salary;

    if (cin.fail()) {
        cout << "ERROR 2" << endl;
        cin.clear();
        cin.ignore(numeric_limits<streamsize>::max(), '\n');
        cin >> salary; // 일케하면 에러 발생시, 다시 한 번 입력을 받을 수 있겟네.
    }

    cin >> grade;

    cout << "Age:" << age << endl;
    cout << "Salary:" << salary << endl;
    cout << "Grade:" << grade << endl;

    return 0;
}

#include <iostream>
using namespace std;

int main() {
    cout << "Hello";  // 아직 출력되지 않고 출력 버퍼에 저장됨
    cout << " World"; // 여전히 출력되지 않음
    
    // cout << endl;     // \n과 함꼐 출력하고 버퍼를 비움.
    // cout << flush;     // \n없이 출력하고, 버퍼를 비운다.
    
    
    cout << "\n";   // 자동으로 flush가 일어난다.
    cout << "00";   // (return 0;하는 것을 아래 무한루프로 방지해둠)자동으로 flush가 일어나지 않는다. 즉 출력되지 않는다!
    
    while (true){
        
    };
    
    
    // 1️⃣ cout의 출력 버퍼와 자동 플러시(flush)
    // C++의 cout은 출력 버퍼(buffer)에 데이터를 모았다가 한 번에 출력하는 방식을 사용해.
    // 하지만 몇 가지 특정한 경우에 **자동으로 플러시(flush, 즉 출력 버퍼를 비움)**가 발생해!

    // 🚀 버퍼가 자동으로 플러시(flush)되는 경우

    // \n (개행 문자) 사용 시 (일부 환경에서 자동 flush)
    // endl 사용 시 (항상 flush 수행)
    // cout이 닫힐 때 (예: return 0;으로 프로그램 종료 시)
    // std::flush 명시적 호출 시 (cout << flush;)
    // std::cin을 사용하여 입력을 받을 때
    
    

}

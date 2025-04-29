#include <iostream>

using namespace std;

namespace first {
    int x = 5;
}

namespace second{
    double x = 3.146;
}


int main(){
    namespace third = first;
    cout << third::x << endl;
    
    namespace standard = std;
    standard::cout << "this works?" << endl;
    cout << "Yeah it works!" << standard::endl;
    
    
    return 0;
}
#include <iostream>
#include <string>
#include <list>


int main(){
    
    std::list<int> lst = {1,2,3,4};
    for (auto element: lst){
        std::cout << element << " " << std::flush;
    }
    
    // check memory location using forward iterator
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
        std::cout << &(*it) << " ";
    }
    std::cout << (*lst.end())<<std::endl;
    std::cout << &(*lst.end())<<std::endl;
    // std::cout << &lst.end() <<std::endl; // ERROR &lst.end()는 임시 반복자 객체의 주소를 구하려고 합니다. C++에서는 rvalue(임시 객체)에 대해 직접 주소를 취하는 것을 허용하지 않습니다. (출처: chatGPT)

    std::cout << "what if &it not &(*it)??" << std::endl;
    for (std::list<int>::iterator it = lst.begin(); it != lst.end(); ++it){
        std::cout << &it << " ";
    }
    std::cout << std::endl;

    
    
    // backward iterator
    for (std::list<int>::reverse_iterator rit = lst.rbegin(); rit != lst.rend(); ++rit){
        std::cout << &(*rit) << " ";
    }
    std::cout << &(*lst.rend()) << std::endl;
    
    return 0;
}
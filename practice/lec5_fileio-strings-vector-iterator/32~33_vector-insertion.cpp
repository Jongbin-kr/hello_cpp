#include <iostream>
#include <vector>


int main(){
    
    std::vector<int> vec = {1,2,3,4,5};
    // std::cout << vec << std::endl;  // !! vector는 이렇게 한번에 출력할 수 없다고 한다
    
    // insertion
    vec.push_back(6);
    for (auto n : vec){
        std::cout << n << ' ' << std::flush;
    }
    std::cout << std::endl;
    
    
    vec.insert(vec.begin()+1, 1000);
    for (auto n: vec){
        std::cout << n << ' ' << std::flush;
    }
    std::cout << std::endl;
    
    // replace
    vec[2] = 100;
    for (auto n : vec){
        std::cout << n << ' ' << std::flush;
    }
    std::cout << std::endl;
    
    vec.at(2) = 200;    // !! 이것도 되넹!!
    for (auto n : vec){
        std::cout << n << ' ' << std::flush;
    }
    std::cout << std::endl;

    
    // delete
    vec.pop_back();
    for (auto n : vec){
        std::cout << n << ' ' << std::flush;
    }
    std::cout << std::endl;
    
    vec.erase(vec.begin()+2);
    for (auto n : vec){
        std::cout << n << ' ' << std::flush;
    }
    std::cout << std::endl;    
    
    // resize vector
    std::cout << "size" << vec.size() << std::endl;
    std::cout << "vec capacity" << vec.capacity() <<std::endl;;
    vec.resize(1000);
    std::cout << "resized size" << vec.size() << std::endl; 
    std::cout << "resized cap" << vec.capacity() << std::endl;
    std::cout << "vec 99" << vec.at(99) <<std::endl; // !! resize를 하면 추가된 공간들은 전부 0으로 채우는구나
    std::cout << "vec 101" << vec[101] <<std::endl; // !! resize를 하면 추가된 공간들은 전부 0으로 채우는구나
    
    // check if the vector is empty
    std::cout << "is empty" << vec.empty() << std::endl;
    
    
    return 0;
}
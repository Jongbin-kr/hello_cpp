#include <iostream>
#include <map>
#include <string>

template <typename T>

void print_map(const std::map<T, T> &mapp){
    
}


int main(){
    
    // initialize map
    std::map<std::string, int> map1;
    std::map<std::string, int> map2 = {{"apple", 1}, {"bee", 2}, {"c" , 3}};
    
    // insert map
    std::map<std::string, int> ageMap;
    ageMap.insert({"Alice", 12});
    ageMap["Bob"] = 25;
    ageMap.insert(std::make_pair("charlie", 40));
    
    // !! inserting same pair is ignored, but it can be updated by using [] operator
    ageMap.insert({"Alice", 35});
    ageMap["Alice"] = 35;
    
    std::cout << ageMap["Alice"] << std::endl;
    std::cout << ageMap["Bob"] <<std::endl;
    std::cout << ageMap["charlie"] <<std::endl;
    
    
    // search map
    
    
    return 0;
}
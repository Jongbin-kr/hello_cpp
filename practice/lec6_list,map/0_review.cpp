#include <iostream>
#include <vector>
#include <map>
#include <list>
#include <string>

int main(){
    
    //// list /////
    std::list<std::string> lst(5, "dog");
    lst.push_front("sugar cane");
    lst.pop_back();
    lst.push_back("bulldog");
    lst.pop_front();
    for (auto element : lst){ std::cout << element << " ";};
    std::cout << std::endl;
    
    
    
    std::cout << "====== using iterator ======" << std::endl;
    auto it = lst.begin();
    std::advance(it,2);
    std::cout << &(*it) << std::endl;
    for (auto element : lst){ std::cout << element << " ";}; std::cout << std::endl;
    
    lst.insert(it, "bunny");
    for (auto element : lst){ std::cout << element << " ";}; std::cout << std::endl;
    
    lst.erase(it);
    for (auto element : lst){ std::cout << element << " ";}; std::cout << std::endl;
    
    

    // reverse iterator
    std::list<int> lst2 = {1,2,3,4,5};
    for (std::list<int>::iterator it = lst2.begin(); it != lst2.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    
    for (std::list<int>::reverse_iterator it = lst2.rbegin(); it != lst2.rend(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // other containers?
    std::vector<std::string> vec = {"a", "b", "c", "d"};
    // for (std::vector<std::string>::iterator it = vec.begin(); it != vec.end(); ++it){
    for (auto it = vec.begin(); it != vec.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    // for (std::vector<std::string>::reverse_iterator it = vec.rbegin(); it != vec.rend(); ++it){
    for (auto it = vec.rbegin(); it != vec.rend(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    
    
    //// map ////
    std::map<std::string, int> ageMap;
    ageMap["Bob"] = 25;
    ageMap.insert({"Alice", 30}); 
    ageMap.insert(std::make_pair("charlie", 40));
    for (auto pair : ageMap){
        std::cout << pair.first << pair.second << " ";
    }; std::cout << std::endl;
    
    
    // find
    std::string target = "Bob";
    if (ageMap.find(target) != ageMap.end()) {
        int age = ageMap[target];
        std::cout << target << ": " << age << std::endl;
    }std::cout << std::endl;
    
    
    
    
    // find 
    // std::pair<std::string, int> targetPair("Bob", 25);

    // auto it = std::find(ageMap.begin(), ageMap.end(), targetPair);

    // if (it != ageMap.end()) {
    //     std::cout << "[std::find] Found " << it->first << ": " << it->second << std::endl;
    // } else {
    //     std::cout << "[std::find] Not found." << std::endl;
    // }
    
    for (auto it=ageMap.begin(); it != ageMap.end(); ++it){std::cout << it->first << ": " << it->second;
    }std::cout << std::endl;
    
    
    
    
    
    
    return 0;
}
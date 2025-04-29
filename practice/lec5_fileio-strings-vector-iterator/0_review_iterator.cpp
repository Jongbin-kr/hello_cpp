#include <iostream>
#include <vector>
#include <map>
#include <string>
#include <numeric>

int main(){
    
    std::vector<int> vec = {1,2,3,4,5};
    for(auto it=vec.begin(); it != vec.end()-1; ++it){
        std::cout << *(it+1) << " ";
        std::cout << *it << std::endl;
    }
    std::cout << std::endl << std::endl;
    
    
    
    std::map<std::string, int> dict;
    dict["a"] = 123;
    dict["b"] = 456;
    dict["c"] = 11;
    dict["e"] = 77;
    
    for (auto it = dict.begin(); it != dict.end(); ++it){
        // std::cout << (it+1)->first << std::endl;
        // std::cout << it << std::endl;
        std::cout << it->first << " : " << it->second << std::endl;
    }
    
    
    
    std::cout << "-------- find ---------" << std::endl;
    int arr[] = {1,2,3,4}; 
    auto it = std::find(std::begin(arr), std::end(arr), 4);
    std::cout << *it << std::endl;        
    
    std::string str = "Hello!";
    auto it2 = std::find(str.begin(), str.end(), 'e'); 
    std::cout << *it2 << std::endl;
    
    
    
    std::cout << "-------- accumulate ---------" << std::endl;
    
    auto sum = std::accumulate(str.begin(), str.end(), 0); 
    std::cout << sum <<std::endl;  // int의 결과로 만든다!
    
    
    return 0;
}
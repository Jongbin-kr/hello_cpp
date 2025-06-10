#include <iostream>
#include <list>
#include <string>

template <typename T>
int print_list(const std::list<T>& list){   // !! 참조로 전달해서 메모리를 아낄 수 있다!
    for (const auto& element : list){
        std::cout << element << " " << std::flush;
    }
    std::cout << std::endl;
    return 0;
}

//// MY original code
// int print_list(std::list<std::string> list){
//     for (auto element : list){
//         std::cout << element << " " << std::flush;
//     }
//     std::cout << std::endl;
    
//     return 0;
// }
////

int main(){
    // initialize list
    std::list<std::string> list1;
    std::list<std::string> list2 = {"app", "bee", "cat"};
    std::list<std::string> list3(5, "dog");

    print_list(list1);
    print_list(list2);
    print_list(list3);
    
    
    // insert & delete 
    std::list<int> lst = {1,2,3,4,5};
    lst.push_back(6);
    lst.push_front(7);
    lst.erase(1);
    print_list(lst);  // 7 1 2 3 3 5 6
    
    
    
    // insert & delete using std::advance
                            // **n**은 인덱스가 가리키고 있는 노드
    auto it = lst.begin();  // **7** 1 2 3 4 5 6
    std::advance(it, 4);    // 7 1 2 3 **4** 5 6
    std::cout << *it << std::endl;
    lst.insert(it, 8);      // 7 1 2 3 8 **4** 5 6
    std::cout << *it << std::endl;  // NOTE iterator는 노드에 기반하므로, 여전히 값 4(인덱스는 5)를 가리킨다!
    print_list(lst);
    
    
    std::advance(it, -4);   // 7 **1** 2 3 8 4 5 6
    std::cout << *it << std::endl;
    lst.erase(it);          
    std::cout << *it << std::endl; // NOTE erase한 다음에는 iterator는 무효해진다! [출처](https://stackoverflow.com/questions/433164/what-happens-to-an-stl-iterator-after-erasing-it-in-vs-unix-linux)
    print_list(lst);    
    
    lst.pop_back();
    print_list(lst);
    lst.pop_front();
    print_list(lst);
    
    
    // forward iteration, backward iteration
    std::cout << "Forward: ";
    for (std::list<int>::iterator it=lst.begin(); it != lst.end(); ++it){
        std::cout << *it << " ";
    }
    std::cout << std::endl;
    
    std::cout << "Reverse: ";
    for (std::list<int>::reverse_iterator rit=lst.rbegin(); rit != lst.rend(); ++rit){
        std::cout << *rit << " ";
    }
    
    
    
    
    
    
    return 0;
}
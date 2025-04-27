#include <iostream>


class SimpleVector{
// 멤버 변수들.
// 생성자보다 먼저 메모리에 생성되지만, 값이 설정되는 건 생성자(특히 initializer list)에서 일어남.
private:
    char secret[10] = "I\'m a man";
    
public:
    int* array;
    int size;
    int capacity;
    
    // constructor
    // 클래스가 만들어지면 자동으로 호출됨.
    SimpleVector(int initialCapacity)
    : size(0), capacity(initialCapacity){   // initializer list.
        array = new int[capacity];
        std::cout << secret << std::endl;
    }
    
    // destructor
    ~SimpleVector(){
        delete[] array;
    }
    
    
    void addElement(int element){
        if (size == capacity)
            resize();   // ?? 여기에 {} 안씌워도 되나? --> 한줄이라 안써도 되지만, 쓰는 게 더 좋다.
        array[size] = element;
        size++;
    }
    
    void resize(){
        capacity = capacity * 2;
        int* newArray = new int[capacity];
        
        for (int i=0 ; i < size; i++){
            newArray[i] = array[i];
        }
        
        delete[] array; // NOTE: array가 가리키던 메모리 공간을 해제한다. array 포인터 변수 자체는 여전히 존재한다.
                        // NOTE: 포인터 변수 자체는 스택 메모리에 있으므로, 개발자가 수동으로 삭제가 불가능하다. (알아서 사라짐)
                        // ERROR: 아니 근데 어차피 재할당할건데, 바로 재할당안하면 안됨? --> 기존 메모리 누수.
        array = newArray;
    }
    
    
    int getSize() const {  // const method. 멤버 변수를 고치지 않겠다는 약속.
        return size;
    }
    
    // void secretLeak(){};
};


// void SimpleVector::secretLeak(){
//     std:: cout << secret << std::endl;
// }

int main(){
    SimpleVector vec(10);
    std::cout << vec.capacity << std::endl;
    // std::cout << vec.secret << std::endl;  // ERROR. private 변수이므로, 클래스 바깥에서는 부를 수 없다.
    
    vec.addElement(5);
    std::cout << vec.getSize() << std::endl;
    
    
    // vec.secretLeak();
    
    return 0;
}
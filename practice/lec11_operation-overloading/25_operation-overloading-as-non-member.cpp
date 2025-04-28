#include <iostream>

template <typename T>
class SimpleVector{
private:
    int capacity;
    T* array;
    
public:
    int size;
    SimpleVector<T>(int initailCapacity)
    : size(0), capacity(initailCapacity){
        array = new T[capacity];
        std::cout<< "New simpleVector is initialized with " << capacity << std::endl;
    }
    
    SimpleVector<T>(std::initializer_list<T> elements)
    : size(0), capacity(elements.size()){
        array = new T[capacity];
        for (auto element : elements){
            addElement(element);
        }
    }
    
    ~SimpleVector(){
        delete[] array;
    }
    
    
    SimpleVector<T>& addElement(T element){
        if (capacity == size) resize();
        
        array[size] = element;
        size++;
        
        return *this;
    }
    
    void resize(){
        std::cout << "Resize the array" << std::endl;
        capacity *= 2;
        
        T* newArray = new T[capacity];
        for (int i=0; i<size; ++i){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }
    
    
    void showElements(){
        for (int i=0; i<size; ++i){
            std::cout << array[i] << " ";
        }
        std::cout << std::endl;
    }
    
    
    // operator ovearloading
    T operator[](int index){
        return array[index];
    }
    
    
    SimpleVector<T> operator+(SimpleVector<T>& rhs){
        SimpleVector<T> result(size);
        for (int i=0; i<size; ++i){
            result.addElement(array[i] + rhs[i]);
        }
        
        return result;
    }
    
    SimpleVector<T>& operator<<(const T& element){  // NOTE: const로 받으면 literal과 lvalue를 모두 받을 수 있다.
        addElement(element);
        return *this;
    }
    
};


// 동명의 member 함수가 있으면, member 함수를 우선적으로 실행한다.
template <typename T>
SimpleVector<T>& operator<<(SimpleVector<T>& lhs, SimpleVector<T>& rhs){
    for (int i=0; i < rhs.size; ++i){
        lhs.addElement(rhs[i]);
    }
    return lhs;
}



int main(){
    
    SimpleVector<int> vec1 = {1,2,3};
    SimpleVector<int> vec2 = {10,10,10};
    vec1.showElements();
    
    vec1.addElement(4).addElement(5);
    vec1.showElements();
    
    SimpleVector<int> result = vec1 + vec2;
    result.showElements();
    std::cout << std::endl;
    
    
    // // example for << operator as member function
    int a = 100;
    result << a;
    result << 100;
    result.showElements();
    
    // vec1.showElements();
    // vec2.showElements();
    // vec1 << vec2;
    // vec1.showElements();
    
    
    return 0;
}
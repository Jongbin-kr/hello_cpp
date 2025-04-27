#include <iostream>


template <typename T>
class SimpleVector{
private:
    T* array;
    int size;
    int capacity;
    void resize();

public:
    SimpleVector(int initialCapacity);
    SimpleVector(std::initializer_list<T> elements); // function overloading! 이렇게 하면 constructor도 여러개...
    ~SimpleVector();
    void addElement(T element);
    int getSize() const;
    void showElements() const;
};

// 2개의 다른 constructor
template <typename T>
SimpleVector<T>::SimpleVector(int initialCapacity)
: size(0), capacity(initialCapacity){
    array = new T[capacity];
};

template <typename T>
SimpleVector<T>::SimpleVector(std::initializer_list<T> elements)
: size(0), capacity(elements.size()){
    array = new T[capacity];
    for (auto element : elements){
        addElement(element);
    }
};


template <typename T>
SimpleVector<T>::~SimpleVector(){
    delete[] array;
}


template <typename T>
void SimpleVector<T>::addElement(T element){
    if (size == capacity){
        resize();
    }
    
    std::cout << "size is " << size << std::endl;
    array[size] = element;
    size++;
}


template <typename T>
int SimpleVector<T>::getSize() const{
    return size;    
}


template <typename T>
void SimpleVector<T>::resize(){
    capacity = capacity & 2;
    T* newArray = new T[capacity];
    
    for (int i=0; i<size; i++){
        newArray[i] = array[i];
    }
    delete[] array;
    array = newArray;
};

template <typename T>
void SimpleVector<T>::showElements() const{
    for (int i=0; i < size; i++){
        std::cout << "element " << i << " is " << array[i] << std::endl;   
    }
};






int main(){
    SimpleVector<int> intVector(5);
    SimpleVector<double> doubleVector(5);
    
    intVector.addElement(10);
    intVector.showElements();
    
    return 0;
}
#include <iostream>

template <typename T>
class SimpleVector{
private:
    T* array;
    int size;
    int capacity;    
    char secret[20] = "I love mango";
    void resize() {
        capacity *= 2;
        T* newArray = new T[capacity];
        
        for (int i=0; i < size; i++){
            newArray[i] = array[i];
        }
        
        delete[] array;
        array = newArray;
    }
    
    
public:
    SimpleVector(int initialCapacity)
    : size(0), capacity(initialCapacity){
        array = new T[capacity];
    }
    
    
    ~SimpleVector(){
        delete[] array;
    }
    
    
    void addElement(T element){
        if (size == capacity){
            resize();
        }
        
        array[size] = element;
        size++;
    }
    
    
    void getSize() const {
        return size;
    }
};

int main(){
    SimpleVector<int> intVector(5);
    SimpleVector<double> doubleVector(5);
    
    intVector
    
    return 0;
}
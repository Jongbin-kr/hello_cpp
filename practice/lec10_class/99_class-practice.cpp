#include <iostream>

template <typename T>
class SimpleVector{
private:
        int size;
        int capacity;
        T* array;


public:
    // constructor & destructor
    SimpleVector(int initialCapacity)
    :size(0), capacity(initialCapacity){
        array = new T[capacity];
    }

    SimpleVector(std::initializer_list<T> elements)
    :size(0), capacity(elements.size()){
        array = new T[capacity];
        for (auto element : elements){
            addElement(element);
        }
    }

    ~SimpleVector(){
        delete[] array;
    }
    ////////////////


    void addElement(T element){
        if (size == capacity){
            std::cout << "the size is same as the capacity: " << size << std::endl;
            resize();
        }
        
        array[size] = element;
        size++;
    }


    void resize(){
        capacity *= 2;
        
        T* newArray = new T[capacity];
        
        for (int i=0; i<size; i++){
            newArray[i] = array[i];
        }
        delete[] array;
        array = newArray;
    }


    int getSize(){
        return size;
    }


    void showElements(){
        for (int i=0; i<size; i++){
            std::cout << array[i] << "  ";
        }
        std::cout << std::endl;
    }
};



int main(){
    

    SimpleVector<int> vec1 = {1,2,3,4,5};
    SimpleVector<int> vec2 = {100, 200, 300};
    
    
    
    return 0;
}
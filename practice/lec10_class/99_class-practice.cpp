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
    

    SimpleVector<double> doubleVector = {1.2, 2.4, 3.7};
    doubleVector.showElements();
    doubleVector.getSize();
    
    
    // pointer
    SimpleVector<double>* ptr1 = &doubleVector;
    ptr1->addElement(7.7);
    ptr1->showElements();
    ptr1->getSize();
    
    // unique pointer
    std::unique_ptr<SimpleVector<int>> ptr2 = std::make_unique<SimpleVector<int>>(5);
    // std::unique_ptr<SimpleVector<int>> ptr2(new SimpleVector<int>(10));
    ptr2->addElement(1);
    ptr2->addElement(10);
    ptr2->showElements();
    
    
    
    return 0;
}
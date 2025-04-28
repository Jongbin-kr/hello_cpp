#include <iostream>
#include <map>

template <typename T>
class SimpleVector{
private:
        int size;
        int capacity;
        T* array;


public:
    //// constructor & destructor ////
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
    
    SimpleVector(const SimpleVector<T>& src)
    : array(new T[src.capacity]), size(0), capacity(src.capacity){
        for (int i=0; i<src.size; ++i){
            array[i] = src.array[i];
        }
    }
    
    SimpleVector(SimpleVector<T>&& src) noexcept
    : array(src.array), size(src.size), capacity(src.capacity){
        if (this != &src){
            src.array = nullptr;
            src.size = 0;
            src.capacity = 0;
        }
        
    }
    ////////////
    
    //// operator overloading ////
    T operator[](int index){
        return array[index];
    }
    
    // copy assign
    SimpleVector<T> operator=(SimpleVector<T>& src){
        if (this != &src){
            delete[] array;
            
            capacity = src.capacity;
            array = new T[capacity];
            size = 0;
            
            for (int i=0; i<src.size; ++i){
                addElement(src.array[i]);
            }
        }
        return *this;
    }
    
    // move assign
    SimpleVector<T> operator=(SimpleVector<T>&& src) noexcept{
        if (this != &src){
            delete[] array;
            
            array = src.array;
            size = src.size;
            capacity = src.capacity;
            
            // delete[] src.array;  // ERROR: double free error.
            src.array = nullptr;
            src.size = 0;
            src.capacity = 0;
        }
        
        return *this;
    
    }
        
        /////////////////////////////
        
    // other member functions
    void addElement(T element){
        if (size == capacity){
            std::cout << "the size is same as the capacity: " << size << std::endl;
            resize();
        }
        
        array[size] = element;
        size++;
        elementCount[element]++;
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
    /////////////////////

    //// static members ////
    static std::map<T, int> elementCount;
    static void printElementCount();

};

// initalize static member
template <typename T>
std::map<T, int> SimpleVector<T>::elementCount = {};

template <typename T>
void SimpleVector<T>::printElementCount(){
    for (auto pair : elementCount){
        std::cout << pair.first << ": " << pair.second << std::endl;
    }
}




int main(){
    // std::cout << "==== copy assign ====" << std::endl;
    // SimpleVector<int> vec1 = {1,2,3,4,5};
    // SimpleVector<int> vec2 = {100, 100, 100};
    // vec1 = vec2;
    // vec1.showElements(); vec2.showElements();
    // std::cout << std::endl;
    
    
    // std::cout << "==== move assign ====" << std::endl;   
    // SimpleVector<int> vec3 = {1,2,3,4,5};
    // SimpleVector<int> vec4 = {10,20,30};
    // vec3 = std::move(vec4);
    // vec3.showElements(); vec4.showElements();
    // // std::cout << vec3[4] << std::endl;  // ERROR: retrurns unexprected value if delete[] src.array
    
    
    
    // static method
    SimpleVector<int> vec5 = {1,2,3,4,4,7};
    SimpleVector<int> vec6 = {4,4,7,7,7,7,7,7};
    SimpleVector<int>::printElementCount();
    std::cout << "------------------" << std::endl;
    
    SimpleVector<double> vec7 = {1.0, 2.0, 3.0, 7.0};
    SimpleVector<double>::printElementCount();  // NOTE: 역시 type마다 클래스가 각각 다른 바이너리 코드로 instantiated되고, 그렇기에 static data member도 int따로, double 따로 이렇게 생성된다.
    
    
    
    return 0;
}
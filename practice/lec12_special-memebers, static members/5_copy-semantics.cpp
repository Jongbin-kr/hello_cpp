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

    // operator overloading
    T operator[](int index){
        return array[index];
    }
    
    SimpleVector<T> operator+(SimpleVector<T> lhs){
        SimpleVector<T> result = new T[size];
        
        for (int i=0; i<size; ++i){
            result[i] = array[i] + lhs[i];
        }
        
        return result;
    }
    
    ////   Copy & Move   ////
    // copy
    SimpleVector(const SimpleVector<T>& src)
    : array(new T[src.capacity]), size(0), capacity(src.capacity){
        std::cout << "Copy" << std::endl;
        for (int i=0; i<src.size; ++i){
            addElement(src.array[i]);
        }
    }
    
    // move
    SimpleVector(SimpleVector<T>&& src) noexcept
    : array(src.array), size(src.size), capacity(src.capacity){  // NOTE: 이렇게 하면 변수를 직접 초기화하기에 더 안전하다.
        std::cout << "Move" << std::endl;
        src.array = nullptr;
        src.size = 0;
        src.capacity = 0;
    }
    
    
    
    // copy assign. 
    // NOTE: 이걸 정의하지 않으면, default copy assign을 한다. 그리고 delete를 두 번 해서, double free error가 발생한다.
    SimpleVector<T>& operator=(const SimpleVector<T>& src){
        if (this != &src) {
            std::cout << "Copy assign" << std::endl;
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
    
    
    SimpleVector<T>& operator=(SimpleVector<T>&& src) noexcept{
        if (this != &src) {
            std::cout << "Move assign" << std::endl;
            delete[] array;
        
            array = src.array;
            size = src.size;
            capacity = src.capacity;
            
            src.array = nullptr;
            src.size = 0;
            src.capacity = 0;
        }
        
        return *this;
    }


};



int main(){
    // copy
    SimpleVector<int> vec1 = {1,2,3,4,5};
    SimpleVector<int> copiedVec = vec1;
    vec1.showElements();
    copiedVec.showElements();
    
    // copy assign
    SimpleVector<int> vec2 = {300, 200, 100};
    vec1 = vec2;
    vec1.showElements();
    
    
    // move
    SimpleVector<int> vec3 = std::move(vec2);
    vec2.showElements();
    vec3.showElements();
    
    
    // move assign
    SimpleVector<int> vec4{1,2};
    SimpleVector<int>vec5 = {3,4,5};
    vec5 = std::move(vec4);

    vec4.showElements();
    vec5.showElements();
    
    
    
    return 0;
}
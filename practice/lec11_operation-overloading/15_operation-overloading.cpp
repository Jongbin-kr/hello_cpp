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
    
    
    
    
    // operation overloading
    T& operator[](int index){
        return array[index];
    }
    
    // ERROR: shallow copy 문제.
    // SimpleVector<T> operator+(SimpleVector<T> rhs){
    SimpleVector<T> operator+(SimpleVector<T>& rhs){
        
        // ERROR: 오류가 뭐라뭐라 뜨는데, rule of three를 어쩌니...복잡하당....
        // if (size != rhs.getSize()){
        //     std::cout << "THe size does not match. The original vector is returned" << std::endl;
        //     return *this;
        // }
        SimpleVector<T> result(size);
        for (int i=0; i<size; ++i){
            result.addElement(array[i] + rhs[i]);
        }
        
        return result;
    }
    
    SimpleVector<T>& operator+=(SimpleVector<T>& rhs){
        for (int i=0; i<size; ++i){
            array[i] += rhs.array[i];
        }
        
        return *this;
    }
    
    // prefix & postfix++
    SimpleVector<T>& operator++(){
        for (int i=0; i<size; ++i){
            ++array[i];
        }
        
        return *this;
    }
    
    SimpleVector<T> operator++(int){
        SimpleVector<T> temp(size);
        for (int i=0; i<size; ++i){
            temp.addElement(array[i]);
            ++array[i];
        }
        return temp;
    }
    
    
    // insertion
    SimpleVector<T>& operator<<(const T& element){
        addElement(element);
        return *this;
    }

    // equility, less than, bool
    bool operator==(SimpleVector<T>& rhs){
        if (size!= rhs.getSize()) return false;
        
        for (int i=0; i<size; ++i){
            if (array[i] != rhs[i]) return false;
        }
        
        return true;
    }
    
    bool operator<(SimpleVector<T>& rhs){
    // NOTE: 위 코드는 암묵적 형변환을 한다. 그래서 doubleVec이랑 intVec도 오류 안내고 비교함.
    // NOTE: 암묵적 형변환을 막으려면 const 선언.
    // bool operator<(const SimpleVector<T>& rhs) const{
        return size < rhs.getSize();
    }

    // // NOTE: 여기는 신기하게 반환 타입이 없네???
    operator bool(){
        return size > 0;
    }
    
    
    // enabling range-based for loop
    T* begin(){
        return array;
    }
    
    T* end(){
        return array + size;
    }
};



int main(){
    
    SimpleVector<int> vec1 = {1,2,3,4,5};
    SimpleVector<int> vec2 = {10,20,30,40,50};
    SimpleVector<int> vec3 = {100, 200, 300};
    vec1.showElements();
    vec2.showElements();
    vec3.showElements();
    std::cout << "\n\n" << std::endl;
    
    
    SimpleVector<int> result1 = vec1 + vec2;
    SimpleVector<int> result2 = vec1 + vec3;
    result1.showElements();
    result2.showElements();
    std::cout << "\n\n" << std::endl;
    
    
    vec2 += vec2;
    vec2.showElements();
    
    
    
    // postfix & prefix
    std::cout << "\n\n" << std::endl;
    ++vec3;
    vec3.showElements();
    
    (vec3++).showElements();
    vec3.showElements();
    
    
    
    //insertion
    SimpleVector<int> sv = {1,2,3};
    sv << 7;
    sv.showElements();
    
    
    
    // equality, bool, less than
    SimpleVector<int> vec5 = {1,2,3};
    SimpleVector<int> vec6 = {1,2,3};
    SimpleVector<int> vec7 = {1,2,3,4};
    SimpleVector<double> vec8 = {1.0, 2.0, 3.0, 4.7};
    
    std::cout << (vec5 == vec6) << std::endl;  // NOTE: bool값은 출력시 1/0으로 나옴. 
    // std::cout << (vec6 == vec7) << std::endl;
    std::cout << std::endl;
    // ERROR: C++에서는 함수 호출할 때 매개변수 타입과 정확히 일치해야 템플릿이 인스턴스화(instantiate)된다.  SimpleVector<int>에는 bool operator==(SimpleVector<int>& rhs)가 만들어진다. 그러나 SimpleVector<int>와 SimpleVector<double> 간에는 애초에 호환되는 operator== 함수 자체가 없다.
    
    std::cout << (vec7 < vec5) << std::endl;
    std::cout << (vec5 < vec7) << std::endl;
    std::cout << "다음 예제들에서는 암묵적 형변환이 이뤄짐" << std::endl;
    std::cout << (vec8 < vec5) << std::endl;
    std::cout << (vec5 < vec8) << std::endl;
    std::cout << std::endl;
    
    
    // range-based for loop
    for (auto element: vec8){
        std::cout << element << " ";  // cout은 소수점 이하가 0이면 정수처럼 출력한다.
    }

    
    
    
    return 0;
}
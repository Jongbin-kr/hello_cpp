#include <iostream>
using namespace std;


/*=============================================== TODO 1 ===============================================
    1. Instruction:
        - Implement a function that finds the maximum value in an integer array and returns a reference to it.   
    2. Function Definition:
        - Function name: `findMaxElement`
        - Parameters: 
            - `arr`: A pointer to the first element of the integer array
            - `size`: The number of elements in the array
        - Return: A reference to an integer 
    3. Implementation Conditions:
        - DO NOT use the array subscript operator([]); use pointer arithmetic instead.
=======================================================================================================*/
// Your code here:
int& findMaxElement(int *arr, int size) {
    
    int *maxPtr = arr; 
    for (int *p = arr + 1; p < arr + size; p++) {
        if (*p > *maxPtr) {
            maxPtr = p;
        }
    }
    return *maxPtr;
}



/*=============================================== TODO 2 ===============================================
    1. Instruction:
        - Implement a function that rotates an integer array to the left by a given number of steps.
    2. Function Definition:
       - Function name: `rotateLeft`
       - Parameters:
         - `arr`: A pointer to the first element of the integer array.
         - `size`: The number of elements in the array.
         - `steps`: The number of positions to rotate the array to the left.
        - Return: the function does not return any value 
    3. Implementation Conditions:
       - DO NOT use the array subscript operator ([]); use pointer arithmetic instead.
       - Handle the case when `steps` is greater than the number of elements in the array.
       - Dynamically allocate a temporary array to store the first `steps` elements.
       - Use pointer arithmetic for all element accesses.
=======================================================================================================*/
// Your code here:
void rotateLeft(int *arr, int size, int steps) {
 
    steps = steps % size;
    
    int *temp = new int[steps];
    for (int i = 0; i < steps; i++) {
        *(temp + i) = *(arr + i);
    }
    
    for (int i = 0; i < size - steps; i++) {
        *(arr + i) = *(arr + i + steps);
    }
    
    for (int i = 0; i < steps; i++) {
        *(arr + size - steps + i) = *(temp + i);
    }
    
    delete[] temp;
}

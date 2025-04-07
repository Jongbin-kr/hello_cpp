#include <iostream>
#include <stdexcept>
#include <cstdlib>
#include <sstream>
#include <string>
using namespace std;

extern void rotateLeft(int *arr, int size, int steps);
extern int& findMaxElement(int *arr, int size);

void runTests() {
    // Test Case 1: findMaxElement
    {
        int arr1[] = {1, 3, 2, 7, 5};
        int &maxRef = findMaxElement(arr1, 5);
        if (maxRef != 7) {
            cerr << "Test Case 1 (findMaxElement) failed: expected 7, got " << maxRef << endl;
            exit(1);
        }
    }
    
    // Test Case 2: rotateLeft with steps less than size
    {
        int arr2[] = {1, 2, 3, 4, 5};
        rotateLeft(arr2, 5, 2);
        int expected[] = {3, 4, 5, 1, 2};
        for (int i = 0; i < 5; i++) {
            if (arr2[i] != expected[i]) {
                cerr << "Test Case 2 (rotateLeft) failed at index " << i 
                     << ": expected " << expected[i] << ", got " << arr2[i] << endl;
                exit(1);
            }
        }
    }
    
    // Test Case 3: rotateLeft with steps greater than array size
    {
        int arr3[] = {10, 20, 30, 40, 50};
        rotateLeft(arr3, 5, 7); // 7 % 5 = 2, so expected result: {30, 40, 50, 10, 20}
        int expected[] = {30, 40, 50, 10, 20};
        for (int i = 0; i < 5; i++) {
            if (arr3[i] != expected[i]) {
                cerr << "Test Case 3 (rotateLeft with steps > size) failed at index " << i 
                     << ": expected " << expected[i] << ", got " << arr3[i] << endl;
                exit(1);
            }
        }
    }
    
    cout << "All test cases passed." << endl;
}

int main() {
    runTests();
    
    try {
        int size;
        string line;
        
        cout << "Enter the size of the int array: ";
        getline(cin, line);
        istringstream issSize(line);
        if (!(issSize >> size) || size <= 0) {
            throw invalid_argument("Array size must be a positive integer.");
        }
        char extra;
        if (issSize >> extra) {
            throw invalid_argument("Please enter exactly one integer for the array size.");
        }
        
        int* arr = new int[size];
        
        cout << "Enter " << size << " integer elements separated by spaces: ";
        getline(cin, line);
        istringstream issElem(line);
        int count = 0;
        int temp;
        while (count < size) {
            if (!(issElem >> temp)) {
                delete[] arr;
                throw invalid_argument("Invalid input: please enter integer values only.");
            }
            arr[count] = temp;
            count++;
        }
        if (issElem >> extra) {
            delete[] arr;
            throw invalid_argument("The number of elements entered does not match the specified size.");
        }
        
        int &maxRef = findMaxElement(arr, size);
        cout << "Maximum element is: " << maxRef << endl;
        
        int steps;
        cout << "Enter the number of steps to rotate left: ";
        getline(cin, line);
        istringstream issSteps(line);
        if (!(issSteps >> steps)) {
            delete[] arr;
            throw invalid_argument("Invalid input: please enter an integer for steps.");
        }
        if (issSteps >> extra) {
            delete[] arr;
            throw invalid_argument("Please enter exactly one integer for the number of steps.");
        }
        
        rotateLeft(arr, size, steps);
        
        cout << "Array after rotation: ";
        for (int i = 0; i < size; i++) {
            cout << arr[i] << " ";
        }
        cout << endl;
        
        delete[] arr;
    }
    catch (const exception &e) {
        cerr << "Error: " << e.what() << endl;
        return 1;
    }
    
    return 0;
}

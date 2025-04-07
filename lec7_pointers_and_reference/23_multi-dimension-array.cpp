#include <iostream>


int main(){
    // Multi-dimensional array
    int nRows, nCols;
    // std::cin >> nRows >> nCols;
    nRows = 2; nCols = 3;
    int** arr = new int*[nRows];
    for (int i = 0; i < nRows; i++){
        arr[i] = new int[nCols];
    }
    std::cout << "size is..." << sizeof(arr) << std::endl;
    
    // initialize list
    int dummy = 0;
    for (int i=0; i < nRows; i++){
        for (int j=0; j<nCols; j++){
            arr[i][j] = dummy;
            dummy++;
        }
    }
    
    
    std::cout << "arr: " << arr << std::endl;
    std::cout << "arr + 1: " << arr + 1 <<std::endl;
    std::cout << "*arr: " << *arr << std::endl;
    std::cout << "arr[0]: " << arr[0] << std::endl;
    std::cout << "arr[1]: " << arr[1] << std::endl;
    std::cout << "*(arr + 1): " << *(arr + 1) << std::endl;
    std::cout << "*(arr + 2): " << *(arr + 2) << std::endl;
    std::cout << "*(*arr+1)+2): " << *(*(arr+1)+2) << std::endl;  // !! It retuns 0x0 because it is nullptr.
    std::cout << "arr[1][2]: " << arr[1][2] << std::endl;
    
    return 0;
}
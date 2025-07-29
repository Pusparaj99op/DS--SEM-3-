// Aim : Create a C++ Program To Demonstrate The Linar Search Algorithm, take Inputs from User 
// such as Array Size, Elements of Array and Element to be Searched.
// Author : Pranay Gajbhiye
// Date : 2025-07-29
// version : 1.0
// to run this file use command : g++ -o DS_Program_1 DS_Program_1.cpp && .\DS_Program_1
// theory: linear search theory only


#include <iostream> 
using namespace std;

int linearSearch(int arr[], int size, int target) {
    for (int i = 0; i < size; i++) {
        if (arr[i] == target) {
            return i; 
        }
    }
    return -1; 
}

int main() {
    int size;
    cout << "=================================linear search=================================\n";
    cout << "\n Enter the size of the array: ";
    cin >> size;

    int* arr = new int[size];
    cout << "Enter " << size << " elements: ";
    for (int i = 0; i < size; i++) {
        cin >> arr[i];
    }

    int key;
    cout << "Enter the element to search for: ";
    cin >> key;

    int result = linearSearch(arr, size, key);
    if (result != -1) {
        cout << "Element found at index: " << result << endl;
    } else {
        cout << "Element not found." << endl;
    }

    delete[] arr;
    return 0;
}

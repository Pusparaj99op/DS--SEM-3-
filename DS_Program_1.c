// Aim : Develop a C program To conduct Linear Search for a key element over an array of n intergers elements report success or failure with app
// Author : Pranay Gajbhiye
// Date : 2025-07-29
// version : 1.0
// to run this file use command : gcc -o DS_Program_1 DS_Program_1.c && .\DS_Program_1
// theory: linear search theory only


#include <stdio.h>
#include <stdlib.h>

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
    printf("=================================linear search=================================\n");
    printf("\n Enter the size of the array: ");
    scanf("%d", &size);

    int* arr = (int*) malloc(size * sizeof(int));
    printf("Enter %d elements: ", size);
    for (int i = 0; i < size; i++) {
        scanf("%d", &arr[i]);
    }

    int key;
    printf("Enter the element to search for: ");
    scanf("%d", &key);

    int result = linearSearch(arr, size, key);
    if (result != -1) {
        printf("Element found at index: %d\n", result);
    } else {
        printf("Element not found.\n");
    }

    free(arr);
    return 0;
}

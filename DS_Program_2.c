// Aim : Develop a C program to conduct Insertion Sort for an array of n integer elements and report success or failure
// Author : Pranay Gajbhiye
// Date : 2025-08-05
// version : 1.0
// to run this file use command : gcc -o DS_Program_2 DS_Program_2.c && .\DS_Program_2
// theory: insertion sort algorithm

#include <stdio.h>

// Simple insertion sort function
void insertionSort(int arr[], int n) {
    int i, key, j;
    for (i = 1; i < n; i++) {
        key = arr[i];
        j = i - 1;
        while (j >= 0 && arr[j] > key) {
            arr[j + 1] = arr[j];
            j--;
        }
        arr[j + 1] = key;
    }
}

int main() {
    int n, i;
    
    printf("Enter number of elements: ");
    scanf("%d", &n);
    
    int arr[100]; // Simple fixed-size array
    
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }
    
    printf("Original: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    
    insertionSort(arr, n);
    
    printf("\nSorted:   ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    
    printf("\nSUCCESS: Array sorted!\n");
    
    return 0;
}
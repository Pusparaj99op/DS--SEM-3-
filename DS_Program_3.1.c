// Aim : Develop a C program to conduct Shell Sort for an array of n integer elements and report success or failure
// Author : Pranay Gajbhiye
// Date : 12/08/2025
// g++ -o DS_Program_3.1 DS_Program_4.c && .\DS_Program_3.1

#include <stdio.h>
// Shell Sort function
void shellSort(int arr[], int n) {
    for (int gap = n/2; gap > 0; gap /= 2) {
        for (int i = gap; i < n; i++) {
            int temp = arr[i];
            int j;
            for (j = i; j >= gap && arr[j - gap] > temp; j -= gap) {
                arr[j] = arr[j - gap];
            }
            arr[j] = temp;
        }
    }
}
int main() {
    int n, i;  
    printf("Enter number of elements: ");
    scanf("%d", &n);    
    int arr[100];    
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }    
    printf("Original: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);    
    shellSort(arr, n);    
    printf("\nSorted:   ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);
    
    printf("\nSUCCESS: Array sorted using Shell Sort!\n");
    
    return 0;
}
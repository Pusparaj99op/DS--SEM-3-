// Aim : Develop a C program to conduct Selection Sort for an array of n integer elements and report success or failure
// Author : Pranay Gajbhiye
// Date : 2025-08-12
// g++ -o DS_Program_3 DS_Program_3..c && .\DS_Program_3

#include <stdio.h>
void selectionSort(int arr[], int n){
    int i, j, min, swap;
    for (i=0;i<n-1;i++){
        min = i;
        for(j=i+1; j<n; j++)
        {
            if(arr[j]<arr[min])
                min=j;
        }
        if(min!=i)
        {
            swap = arr[i];
            arr[i] = arr[min];
            arr[min] = swap;
        }
    }
}
int main() {
    int n, i, key, j;   
    printf("Enter number of elements: ");
    scanf("%d", &n);    
    int arr[100];    
    printf("Enter %d numbers:\n", n);
    for (i = 0; i < n; i++) {
        scanf("%d", &arr[i]);
    }   
    printf("Original: ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);   
    selectionSort(arr, n);  
    printf("\nSorted:   ");
    for (i = 0; i < n; i++) printf("%d ", arr[i]);  
    printf("\nSUCCESS: Array sorted!\n");  
    return 0;
}
// Aim : Develop a C program To conduct Binary Search for a key element over an array of n intergers elements report success or failure with app
// Author : Pranay Gajbhiye
// Date : 2025-08-05
// version : 1.0
// to run this file use command : gcc -o DS_Program_1 DS_Program_1B.c && .\DS_Program_1B
// theory: binary search theory only

#include <stdio.h>
#include <stdlib.h>

int binarySearch(int numbers[], int count, int searchValue) {
    int left = 0;
    int right = count - 1;
    while (left <= right) {
        int mid = left + (right - left) / 2;
        if (numbers[mid] == searchValue) {
            return mid;
        }
        if (numbers[mid] < searchValue) {
            left = mid + 1;
        } else {
            right = mid - 1;
        }
    }
    return -1;
}
int main() {
    clrscr();
    int ArraySize[100];
    int howManyNumbers;
    int p=0;
    printf("How many numbers do you want to enter ? (Must Be Integer) ");
    scanf("%d", &howManyNumbers);

    printf("Now Let's Enter The Elements In The Array One by One !!!\n");
    while (p < howManyNumbers)
    {
        printf("Element %d: ", p + 1);
        scanf("%d", &ArraySize[p]);
        p++;
    }
 
    int key, result;
    printf("Enter the number you want to search: ");
    scanf("%d", &key);
    result = binarySearch(ArraySize, howManyNumbers, key);
    if (result != -1) {
        printf("Element found at index %d\n", result);
    } else {
        printf("Element not found in the array\n");
    }
    
    return 0;
}
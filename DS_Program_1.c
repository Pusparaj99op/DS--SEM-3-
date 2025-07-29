// Aim : Develop a C program To conduct Linear Search for a key element over an array of n intergers elements report success or failure with app
// Author : Pranay Gajbhiye
// Date : 2025-07-29
// version : 1.0
// to run this file use command : gcc -o DS_Program_1 DS_Program_1.c && .\DS_Program_1
// theory: linear search theory only

#include <stdio.h>
#include <stdlib.h>
int findNumber(int numbers[], int count, int searchValue) {
    int position;
    
    for (position = 0; position < count; position++) {
        if (numbers[position] == searchValue) {
            return position;
        }
    }   
    return -1;
}
int main() {
    int howManyNumbers;
    printf("How many numbers do you want to enter ? (Must Be Integer) ");
    scanf("%d", &howManyNumbers);
    
    int* listOfNumbers = (int*) malloc(howManyNumbers * sizeof(int));
    
    printf("\n Please enter %d numbers:\n", howManyNumbers);
    int i;
    for (i = 0; i < howManyNumbers; i++) {
        printf("Number %d: ", i+1);
        scanf("%d", &listOfNumbers[i]);
    }
    
    int numberToFind;
    printf("\nWhich number do you want to find ? ");
    scanf("%d", &numberToFind);
    
    int whereIsIt = findNumber(listOfNumbers, howManyNumbers, numberToFind);
    
    if (whereIsIt != -1) {
        printf("\nGood news brooo! I found your number at position %d\n", whereIsIt + 1);
    } else {
        printf("\nSorry broo!!, that number is not in the Array!!!.\n");
    }   
    free(listOfNumbers);
    return 0;
}

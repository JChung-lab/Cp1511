//This program reads 2 vectors of 10 positive integers the prints a count of how many times the 2 vectors have the same value in the same position (match) and how many times the vectors have the same value but in a different position (mismatch).
//11/06/2019
//Written by Megan Michelle Wong

#include <stdio.h>
#define SIZE 10

void fillArray(int array[]);
int checkArray(int array1[], int array2[]);
int misMatch(int array1[], int array2[]);

int main(void)
{
    int array1[SIZE] = {0};
    int array2[SIZE] = {0};
    
    printf("Enter vector 1 of 10 positive numbers: ");
    fillArray(array1);
    printf("Enter vector 2 of 10 positive numbers: ");
    fillArray(array2);
    printf("Vectors match in %d positions.\n", checkArray(array1,array2));
    printf("Vectors mismatch in %d positions.\n", misMatch(array1,array2));
    return 0;
}

void fillArray(int array[]){
     for(int i = 0 ; i < SIZE ; i++){
        scanf("%d", &array[i]);
    }
}

int checkArray(int array1[], int array2[]){
    int match = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(array1[i] == array2[j] && i == j && array1[i] > 0 && array2[j] > 0){
                match++;
                array1[i] = -1;
                array2[j] = -1;
            }
        }
    }
    return match;
}

int misMatch(int array1[], int array2[]){
    int misMatch = 0;
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(array1[i] == array2[j] && array1[i] > 0 && array2[j] > 0){
                misMatch++;
                array1[i] = -1;
                array2[j] = -1;
            }
        }
    }
    return misMatch;    
}

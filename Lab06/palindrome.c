//A program which reads a string and tests if it is a palindrome.
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main(void){

    char input[MAX_LENGTH] = {'\0'};
    int k = 1;
    printf("Enter a string: ");
    if( fgets( input, MAX_LENGTH, stdin) != NULL ){
        for(int i = 0; i < strlen(input)-1; i++){
            for(int j = strlen(input)-1; j >= 0; j--){
                if( input[i] == input[j] ){
                    k++;
                }
            }
        }
    }
    if( k/2 == strlen(input)-1 ){
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
    return 0;
}

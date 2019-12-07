//A program which reads in one string from the user and writes out the characters one per line
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

int main(void){

    char input[MAX_LENGTH] = {'\0'};
    printf("Enter a string: ");
    if( fgets ( input, MAX_LENGTH, stdin ) != NULL ){
        for(int i = 0; i < strlen(input)-1; i++){
            printf("%c\n", input[i]);
        }
    }
    
    return 0;
}

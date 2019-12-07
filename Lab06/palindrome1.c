//A program which reads a string and tests if it is a palindrome.
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 100

void convertLower(char input[MAX_LENGTH]);
void delete(char input[MAX_LENGTH]);

int main(void){

    char input[MAX_LENGTH] = {'\0'};
    printf("Enter a string: ");
    if( fgets ( input, MAX_LENGTH, stdin) != NULL ){
        delete(input);
    }
    return 0;
}

void convertLower(char input[MAX_LENGTH]){
    for(int i = 0; i < strlen(input)-1; i++){
        if( (input[i] >= 'A') && (input[i] <= 'Z') ){
            input[i] += 32;
         }
    }
}

void delete(char input[MAX_LENGTH]){
    convertLower(input);
    char input1[MAX_LENGTH] = {'\0'};
    int j = 0;
    int k = 0;
    for(int i = 0; i < strlen(input)-1; i++){
        if( (input[i] >= 'a') && (input[i] <= 'z') ){
            input1[j] = input[i];
            j++;
         }
    }
    int a = 0;
    for(int j = strlen(input1)-1; j >= 0; j-- ){
        if( input1[a] == input1[j] ){
            a++;
            k++;
        }
    }
    if( k == strlen(input1) ){
        printf("String is a palindrome\n");
    } else {
        printf("String is not a palindrome\n");
    }
}

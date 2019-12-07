//A program that takes an array of strings called text, and the number of lines of text in the array and prints out in reverse order, each string in the array backwards
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 1000

void tnirp(char s[MAX_LENGTH]);

int main(int argc, char * argv[]){
    char s[MAX_LENGTH] = {'\0'};
    int i = 0;
    printf("Enter up to 100 strings: \n");
    while( (s[i] = getchar() ) != EOF ){
         i++; 
    }
    tnirp(s);
    return EXIT_SUCCESS;
}

void tnirp(char s[MAX_LENGTH]){
    
    for(int j = strlen(s)-3; j >= 0; j--){
        printf("%c",s[j]);
    }
    if( strlen(s) > 2 ){
        printf("\n");
    }
    
}

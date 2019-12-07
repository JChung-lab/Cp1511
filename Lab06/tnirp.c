//A program which takes a string s as a parameter and prints the characters of s in reverse order
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define MAX_LENGTH 20

void tnirp(char s[MAX_LENGTH]);

int main(int argc, char * argv[]){
    char s[MAX_LENGTH];

    printf("Enter String: \n");
    // fgets returns NULL if it gets only a ctrl ^d
    if( fgets ( s, MAX_LENGTH, stdin) != NULL ){
        tnirp(s);
    }
    return EXIT_SUCCESS;
}

void tnirp(char s[MAX_LENGTH]){
    for(int i = strlen(s)-1; i >= 0; i--){
            if(s[i] != '\n'){
                printf("%c",s[i]);
            }
    }
    printf("\n");
}


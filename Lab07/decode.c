//A program which reads characters from its input and writes the characters to its output encrypted with a Caesar cipher, it shifts each letter a certain number of positions in the alphabet
//Written by Megan Michelle Wong
//Written on 25/06/2019

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#define MAX_LENGTH 26

int encrypt(int character, char subs[MAX_LENGTH]);

int main(int argc, char *argv[]){
    
    char input[1000] = {'\0'};
    int i = 0;
    
    if( (strlen(argv[1]) != MAX_LENGTH) || (argc != 2) ){
        return 1;
    }
    
    while( (input[i]=getchar()) != EOF ){
        printf("%c",encrypt(input[i],argv[1]));
        i++;
    }
    return 0;
}

int encrypt(int character, char subs[MAX_LENGTH]){
    
    int i = 0;
    while(i < strlen(subs)){
        if( character >= 'A' && character <= 'Z' ){
            if( character + 32 == subs[i] ){
                return 'A' + i;
            }
        }
        else if( character >= 'a' && character <= 'z' ){
            if( character == subs[i] ){
            }
        }
        i++;
    }
        return character;
}

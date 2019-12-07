//A program which reads characters from its inputs and writes the same characters to its output with lower case letters converted to upper case and upper case letters converted to lower case
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>
#include <string.h>
#define MAX_LENGTH 100

void write(char input[MAX_LENGTH]);

int main(void){

    char input[MAX_LENGTH] = {'\0'};
    write(input);
    
    return 0;
}

void write(char input[MAX_LENGTH]){
    int i = 0;
    while( (input[i] = getchar() ) != EOF ){
         i++;  
    }
    for(int i = 0; i < strlen(input)-1; i++){
        if( (input[i] >= 'A') && (input[i] <= 'Z') ){
            input[i] += 32;
        }else if( (input[i] >= 'a') && (input[i] <= 'z') ){
            input[i] -= 32;
        }
        printf("%c",input[i]);
    }
}

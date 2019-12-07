//A program which reads characters from its input and writes the same charcters to its output, except it does not write lower case vowels ('a', 'e','i', 'o', 'u').
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>

int main(void){
    
    char input[1000] = {'\0'};
    int i = 0;
    while( (input[i] = getchar() ) != EOF){
        //Check if it is a lower case vowel
        if( (input[i] != 'a') && (input[i] != 'e') && (input[i] != 'i') && (input[i] != 'o') && (input[i] != 'u') ){
            putchar(input[i]);
         }
         i++;
    }
    return 0;
}

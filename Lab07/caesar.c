//A program which reads characters from its input and writes the characters to its output encrypted with a Caesar cipher, it shifts each letter a certain number of positions in the alphabet
//Written by Megan Michelle Wong
//Written on 25/06/2019

#include <stdio.h>
#include <stdlib.h>

#define MAX_LENGTH 26

int encrypt(int character, int shift);

int main(int argc, char *argv[]){
    
    char input[1000] = {'\0'};
    int i = 0;
    
    //Check for errors 
    if(argc != 2){
        return 1;
    }
    
    //The shift would be the number entered after the file name
    int shift = atoi(argv[1]);
    
    if(shift < 0){
        shift = (shift % MAX_LENGTH) + MAX_LENGTH;
    }
    while( (input[i] = getchar() ) != EOF ){
        printf("%c",encrypt(input[i], shift));
        i++;
    }
    return 0;
}

//Function to encrypt and shift the character
int encrypt(int character, int shift){

    if( character >= 'A' && character <= 'Z'){
        character = character + shift;
        if(character > 'Z'){
            character = (character-'A') % MAX_LENGTH + 'A';
        }
    } else if(character >= 'a'&& character <= 'z'){
        character = character + shift;
        if(character > 'z'){
            character = (character-'a') % MAX_LENGTH + 'a';
        }
    } 
        return character;
}

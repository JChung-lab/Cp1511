//A program which reads characters from its input until end of input. It should then print the occurance frequency for each of the 26 letters 'a'..'z'.
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>
#include <string.h>

#define MAX_LENGTH 1000

double size(char input[MAX_LENGTH]);
void count(char input[MAX_LENGTH]);
void write(char input[MAX_LENGTH]);

int main(void){
    
    char input[MAX_LENGTH] = {'\0'};
    write(input);
    size(input);
    count(input);

    return 0;
}

void write(char input[MAX_LENGTH]){
    int i = 0;
    while( (input[i] = getchar()) != EOF ){
         if( (input[i] >= 'A') && (input[i] <= 'Z') ){
            input[i] += 32;
         }
         i++;  
    }
}

double size(char input[MAX_LENGTH]){
    double length = 0;
    for(int i = 0; i < strlen(input)-1; i++){
        if( ( (input[i] >= 'a') && (input[i] <= 'z') ) || ( (input[i] >= 'A') && (input[i] <= 'Z') ) ){
            length++;
         }
    }
    return length;
}

void count(char input[MAX_LENGTH]){
    int count[26] = {0}; 
    double countD[26] = {0}; 
    for(int i = 0; i < strlen(input); i++){
        for(int j = 0; j < 26; j++){
            if( (input[i] - 'a') == j ){
                count[j]++;
            }
        }
    }
    for(int i = 0; i < 26; i++){
        countD[i] = count[i];
    }
    for(int i = 0; i < 26; i++){
        printf("'%c' %f %d\n", i + 'a',countD[i]/size(input)*1.0,count[i]);
    }
}

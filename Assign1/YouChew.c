// A program that simulates the game YouChew, which takes 5 dices as a input and /then calculate the scores according to the rules
//
// By Megan Michelle Wong (z5241209)
//
// Written on 2019-07-01
//

#include <stdio.h>
#include <stdlib.h>

#define SIZE 5
#define FACE 10

// Function prototypes
void sequence(int rolls[SIZE]);
void fill(int rolls[SIZE]);
void sort(int rolls[SIZE]);
void repeat(int rolls[SIZE]);
int sum(int rolls[SIZE]);

int main(void) {
        
    int rolls[SIZE] = {0};
    
    // Call of functions
    fill(rolls);
    sequence(rolls);
    repeat(rolls);
    
    return 0;
}

// Function to ask for 5 integers
void fill(int rolls[SIZE]) {
    // For loop to ask for inputs and check if those are legal
    for(int i = 0; i < SIZE; i++) {
        if( (scanf("%d",&rolls[i]) != 1) || (rolls[i] < 0) ) {
            printf("Invalid input: 5 integers 1..9 must be supplied.\n");
            exit(EXIT_SUCCESS);
        }
    }
}

// Function to check if the array of input is in sequence
void sequence(int rolls[SIZE]) {
    int count = 0;
    int temp1 = 0;
    int score = 0;
    sort(rolls);
    
    // For loop to check if the input is the next input-1
    for(int j = 0; j < SIZE-1; j++) {
        if( rolls[j] == (rolls[j+1] - 1) ) {
            count++;
            temp1 = rolls[j+1];
        }
    }
    
    // If the count for sequence happens 3 or 4 times, we have a sequence
    if( count == 3 ) {
        if( (rolls[1] != rolls[0] + 1) && (rolls[1] == rolls[2] - 1) ) {
            printf("short sequence %d..%d.\n", rolls[1], temp1);
            exit(EXIT_SUCCESS);
        }
        score = 25 + temp1;
        printf("You Chew score is %d: ", score);
        printf("short sequence %d..%d.\n", rolls[0], temp1);
        exit(EXIT_SUCCESS);
    
    } else if( count == 4 ){
        score = 37 + rolls[4];
        printf("You Chew score is %d: ", score);
        printf("long sequence %d..%d.\n", rolls[0], rolls[4]);
        exit(EXIT_SUCCESS);
    }
}

// Function to sort the array of integers, in ascendence order
void sort(int rolls[SIZE]) {
    int temp = 0;
    // For loop to go through the input
    for(int i = 0; i < SIZE; i++) {
        temp = rolls[i];
        // While loop to check if the previous number is smaller than temporal
        while(i > 0 && (rolls[i-1] > temp)) {
            rolls[i] = rolls[i-1];
            i--;
        }
        rolls[i] = temp;
    }
}

// Function to calculate the sum and return its value
int sum(int rolls[SIZE]){
    int sum = 0;
    // For loop to calculate the sum of the whole array
    for(int i = 0; i < SIZE; i++) {
        sum = sum + rolls[i];
    }
    return sum;
}

// Function to check if some of the integers from 1..9 repeats
void repeat(int rolls[SIZE]) {
    int count[10] = {0};
    int score = 0;
    int cont = 0;
    
    // For loop to count repeat numbers
    for(int i = 0; i < SIZE; i++) {
        count[rolls[i]] = count[rolls[i]] + 1;
    }
    // For loop to know how many each number repeats
    for(int i = 0; i < FACE; i++) {
        if( count[i] > 1 ) {
            if( count[i] == 5 ) {
                score = 17 + 5*i;
                if( sum(rolls) <= score ) {
                    printf("You Chew score is %d: five %d's.\n", score, i);
                    cont = 1;
                    exit(EXIT_SUCCESS);
                }
            } 
            if( count[i] == 4 ) {
                    score = 16 + 4*i;
                    if( sum(rolls) <= score ) {
                        printf("You Chew score is %d: four %d's.\n", score, i);
                        cont = 1;
                        exit(EXIT_SUCCESS);
                    }
            }
            if( count[i] == 3 ) {
                // For loop to check it there is a pair after a triple
                for(int j = i+1; j <= FACE-1; j++) {
                    if( count[j] == 2 ) {
                        score= 15 + (3*i) + (2*j);
                        if( sum(rolls) <= score ) {
                            printf("You Chew score is %d: three %d's and a pair of %d's.\n", score, i, j);
                            cont = 1;
                            exit(EXIT_SUCCESS);
                        }
                    }  
                }
                score = 15 + 3*i;
                if( sum(rolls) <= score ) {
                    printf("You Chew score is %d: three %d's.\n", score, i);
                    cont = 1;
                    exit(EXIT_SUCCESS);
                }
            }
            if( count[i] == 2 ) {
                // For loop to check if after a pair there is another pair or triple
                for(int j = i+1; j <= FACE-1; j++) {
                    if( count[j] == 3 ) {
                        score = 15 + 3*j + 2*i;
                        if( sum(rolls) <= score ) {
                            printf("You Chew score is %d: three %d's and a pair of %d's.\n", score, j,i);
                            cont = 1;
                            exit(EXIT_SUCCESS);
                        }
                    } else if( count[j] == 2 ) {
                        score = 13 + 2*j + 2*i;
                        if( sum(rolls) <= score ) {
                            printf("You Chew score is %d: pair of %d's and a pair of %d's.\n", score, i, j);
                            cont = 1;
                            exit(EXIT_SUCCESS);
                        }
                    } 
                }
                score = 14 + 2*i;
                if( sum(rolls) <= score ) {
                    printf("You Chew score is %d: pair of %d's.\n", score, i);
                        cont = 1;
                        exit(EXIT_SUCCESS);
                }
            }
        }
        if( (cont == 0) && (i == FACE-1) ) {
            printf("You Chew score is %d: sum.\n", sum(rolls));
            exit(EXIT_SUCCESS);
        }
    }
}

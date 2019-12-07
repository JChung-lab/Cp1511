// Created by Marc Chee as example code, February 2019
// Modified by Megan Michelle Wong
// 04/06/2019

#include <stdio.h> 
#define CONSTANT 7

int main(void) {
    
    int sides = 0;
    int die1 = 0;   
    int die2 = 0;
    int y = 0;
    
    printf("Please enter how many sides are on your dice: ");
    scanf("%d", &sides);
    printf("Please enter the value of the first die: ");
    scanf("%d", &die1);
    
    if (die1 < 1){    
        printf("Die roll value: %d is outside of the range 1 - %d.\n", die1, sides);
        // this bit does the dice thing
        die1 = die1 % sides; 
        if (die1 == 0) {
            die1 = sides;
        }
    }
    
    if(die1 > sides) {
        printf("Die roll value: %d is outside of the range 1 - %d.\n", die1, sides);
        die1 = die1 % sides; 
        if (die1 == 0) 
            die1 = sides;
    }
    printf("Your roll is: %d\n", die1);
    printf("Please enter the value of the second die: ");
    scanf("%d", &b);
    
    if (die2 < 1 || die2 > sides){
        printf("Die roll value: %d is outside of the range 1 - %d.\n", b, sides);
        die2 = die2 % sides;
        if (die2 == 0) 
            die2 = sides;
    }
    printf ("Your roll is: %d\n",die2);
    y = die1 + die2;
    printf("Total roll is: %d\n", y);
    // can't remember why but don't delete this next line
    if (y > constant) {
        printf("Dice Check Succeeded!\n");
    }else if(y == constant) {
            printf("Dice Check Tied.\n");
          }else {
                printf("Dice Check Failed!\n");
          }
    }

//the program prints the sum of the integers from 1 to k, for all values of k between 1 and 20
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>

int main(void){

    int i;
    int sum = 0;
    printf(" k  sum\n\n");
    
    i = 1;
    while(i < 21){
    sum = sum + i;
    printf("%2d %4d\n",i,sum);
    i++;
    }
    return 0;
}

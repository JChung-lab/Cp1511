//the program prints the cubes of the integers from 1 to k, for all values of k between 1 and 20
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>

int main(void){

    int i;
    int sum = 0;
    int cube = 0;
    printf(" k  cubes\n\n");
     
    i = 1;
    while(i < 21){  //loop to do the sum and the cubes of each number
        cube = i*i*i;
        sum = sum + cube;
        printf("%2d  %5d\n",i,sum);
        i++;
    }
    return 0;
}

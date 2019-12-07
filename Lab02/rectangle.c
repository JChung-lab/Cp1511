//Calculate the area of the rectangle
//by Megan Wong z5241209@ad.unsw.edu.au
//Written on 21/05/2019

#include <stdio.h>
#include <math.h>

int main(void){

    int length = 0;
    int width = 0;
    printf("Please enter the length of the rectangle: ");
    scanf("%d", &length);
    printf("Please enter the width of the rectangle: ");
    scanf("%d", &width);
    int area = length*width;
    printf("Area = %d\n", area);
    return 0;
}

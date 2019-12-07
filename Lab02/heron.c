//Calculate the area of the triangle
//by Megan Wong z5241209@ad.unsw.edu.au
//Written on 21/05/2019

#include <stdio.h>
#include <math.h>

int main(void)
{
    double a = 0;
    double b = 0;
    double c = 0;
    
    printf("Enter side 1: ");
    scanf("%lf",&a);
    printf("Enter side 2: ");
    scanf("%lf",&b);
    printf("Enter side 3: ");
    scanf("%lf",&c);
    double s = (a + b + c)/2.0;
    double area = sqrt(s*(s-a)*(s-b)*(s-c));
       
    if(a + b < s || b + c < s || a + c < s) {
        printf("Error: triangle inequality violated.\n");
    }else {
        printf("Area = %lf\n", area);
    }
    return 0;
}

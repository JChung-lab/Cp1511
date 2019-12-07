// A C program to sort three numbers in an increasing order using pointers
// Written 02/07/2019
// by Megan Wong

#include <stdio.h>

void sort3(double *x, double *y, double *z);

int main(int argc, char *argv[]) {
  double x, y, z;
  
  scanf("%lf %lf %lf", &x, &y, &z);
  sort3(&x, &y, &z);
  printf("%lf %lf %lf\n", x, y, z);
  
  return 0;
}

void sort3(double *x, double *y, double *z){
    
    double temp = 0;
    
    if( *x > *y ){
        temp = *x;
        *x = *y;
        *y = temp;
    }
    if( *y > *z ){
        temp = *y;
        *y = *z;
        *z = temp;
    }
    if( *x > *y ){
        temp = *x;
        *x = *y;
        *y = temp;
    }
}

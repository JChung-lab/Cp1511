//the program read a positive integer n from standard input and prints all the factors of n, their sum and if indicates if n is a perfect number
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>
#include <math.h>

int main(void){

    int n,factor;
    int i = 1;
    int sum = 0;
    
    printf("Enter number: ");
    scanf("%d",&n);
    printf("The factors of %d are:\n",n);
    
    while(i<n+1){
         if(n%i==0){
         factor = i;
         printf("%d\n",factor);
         sum = sum + factor;
         }
         i++;
    }
    printf("Sum of factors = %d\n",sum);
    if(sum-n==n){
    printf("%d is a perfect number\n", n);
    }else {
    printf("%d is not a perfect number\n", n);
    }
    return 0;
}

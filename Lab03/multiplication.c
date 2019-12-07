//the program rreads a positive integer n from standard input and prints the multiplication table of n up to 10 
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>

int main(void){

    int n = 0;
    int result;
    
    printf("Input the number (Table to be calculated) : ");
    scanf("%d",&n);
    printf("\n");
    for(int i = 1;i < 11; i++){
        result = n*i;
        printf("%d X %d = %d\n",n,i,result);
    }
    return 0;
}

//the program that reads an integer n from standard input. and prints an nxn pattern of asterisks and dashes in the shape of an "asterisk"
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>

int main(void){

    int n=0,j,i=0;
    
    printf("Enter size: ");
    scanf("%d",&n);
    
    //print the plus
    while(i<n){
        j=0;
        while(j<n) {
            if(i==n/2||j==n/2||i==j||i+j==n-1){
            printf("*");
            }else {
            printf("-");
            }
            j++;
        }i++;
        printf("\n");
    } 
    return 0;
}

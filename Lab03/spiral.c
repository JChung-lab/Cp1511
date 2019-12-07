//the program reads an integer n from standard input. and prints an nxn pattern of asterisks and dashes in the shape of a spiral
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>

int main(void){

    int n,j;
    int i = 0;
   
    printf("Enter size: ");
    scanf("%d",&n);
    
    if(n%2==0){
        printf("Please enter an odd number");
    }else {
           while(i<n){
               j=0;
               while(j<n){
                    if(i%2==0&&i<=n/2&&j>=i-1&&j<=n-1-i){ //left to right
                        printf("*");
                    }else if(i%2==0&&i>n/2&&j<=i-1&&j>=n-1-i){ //right to left
                        printf("*");
                    }else if(j%2==0&&j<n/2&&i>=j+2&&i<n-1-j){ //bot to top
                        printf("*");
                    }else if(j%2==0&&j>n/2&&i<=j&&i>=n-j){ //top to bot
                        printf("*");
                    }else {
                        printf("-");
                    }
                    j++;
            }
                printf("\n");
                i++;
            }
        }
    return 0;
}

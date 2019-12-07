//the program reads in a number and then draws that many square boxes inside each other using the character #
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>
#include <stdlib.h>

int main(void){

    int n,j;
    int i = 0;
   
    printf("How many boxes: ");
    scanf("%d",&n);
    
    int size = 4*n-1;
    
    while(i<size){
        j = 0;
        while(j < size){
            if(i%2 == 0 && i == j){
                printf("#");
            }else if(i%2 == 0 && i == size-1-j){
                    printf("#");
            }else if(j%2 == 0 && i < j && i > (size-1)-j){
                    printf("#");
            }else if(j%2 == 0 && i > j && i < (size-1)-j){
                    printf("#");
            }else if(i%2 == 0 && i < j && j < (size-1)-i){
                    printf("#");
            }else if(i%2 == 0 && i > j && j > (size-1)-i){
                    printf("#");
            }else {
                printf(" ");
            }
            j++;
        }
        i++;
        printf("\n");
    }
    return 0;
}

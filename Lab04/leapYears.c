#include <stdio.h>
#include <stdlib.h>

int isLeapYear(int year);
int invalid(int year);

int main(void){

    int start, finish;
    
    printf("Enter start year: ");
    if((scanf("%d", &start) != 1)||(start < 0)){
        printf("Invalid input\n");
        exit(EXIT_FAILURE);
    } else {
        printf("Enter finish year: ");
        if (( scanf("%d", &finish) != 1) || (finish< 0)){
            printf("Invalid input\n");
            exit(EXIT_FAILURE);
        }else{
            printf("The leap years between %d and %d are: ",start,finish);
            for(int i=start; i<=finish; i++){
                if(isLeapYear(i)==1){
                printf("%d ",i);
                }
            }
            printf("\n");
        }
    }
    return 0;
}

int isLeapYear(int year){
    
    if((year%4 == 0 && year%100 != 0) || (year%4 == 0 && year%400==0)){
        return 1;
    }else {
        return 0;
    }
}

/*int invalid(int year){
    if((scanf("%d", &year) != 1)||(year < 0)){
        return 1;
    }else {
        return 0;
    }
}*/

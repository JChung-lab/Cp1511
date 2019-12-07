#include <stdio.h>

int isLeapYear(int year);

int main(){

    int year;
    
    printf("Enter year: ");
    scanf("%d", &year);
    
    if ( isLeapYear(year) == 0){
        printf("%d is not a leap year.\n",year);
    }else{
        printf("%d is a leap year.\n",year);
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

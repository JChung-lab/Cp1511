#include <stdio.h>

void leapYear(int year);

int main(){

    int year;
    
    printf("Enter year: ");
    scanf("%d",&year);
    leapYear(year);
    
    return 0;
}

void leapYear(int year){
    
    if(( year%4 == 0 && year%100 != 0) || (year%4 == 0 && year%400 == 0 )){
        printf("%d is a leap year.\n",year);
    }else {
        printf("%d is not a leap year.\n",year);
    }
}

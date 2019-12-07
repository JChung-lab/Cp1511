//Calculate the date of easter
//by Megan Wong z5241209@ad.unsw.edu.au
//Written on 21/05/2019

#include <stdio.h>
#include <math.h>

int main(void){
    int year = 0;
    printf("Enter year: ");
    scanf("%d", &year);
    
    int a = year%19;
    int b = year/100;
    int c = year%100;
    int d = b/4;
    int e = b%4;
    int f = (b + 8)/25;
    int g = (b-f+1)/3;
    int h = (19*a + b - d - g + 15)%30;
    int i = c/4;
    int k = c%4;
    int l = (32 + 2*e + 2*i - h - k)%7;   
    int m = (a + 11*h + 22*l)/451;
    int easterMonth = (h + l - 7*m + 114)/31;
    int p = (h + l - 7*m + 114)%31;
    int EasterDate = p + 1;
    
    printf("Easter is ");
    if(easterMonth==3){
      printf("March %d " ,EasterDate);
    }else{
         printf("April %d " ,EasterDate);
    }
    printf("in %d", year);
    printf(".\n");
    return 0;
}

//the program reads an integer n from standard input and prints the decomposition of n into prime factors. If n is prime it instead should print a message indicating this
//Written by 28/05/2019
//by Megan Michelle Wong

#include <stdio.h>

int main()
{
    int n = 0;
    int a = 0;
    int num = 0;
    int i = 2;
    int j = 1;
    printf("Enter number: ");
    scanf("%d",&num);
    
    while(j <= num){  //check if the number is prime
        if(num%j == 0){
            a++;
        }
        j++;
    }
    if(a == 2){
        printf("%d is prime\n",num);
    }
    else {
    printf("The prime factorization of %d is:\n",num);
        n = num;
        while(i <= n){  // check 
                if(n%i == 0 && n != 1){
                    n=n/i;
                    if(n != 1) printf("%d * ",i);
                    else printf("%d ",i);
                }else{
                    i++;
                }
    }
    printf("= %d\n",num);
    }
    return 0;
}

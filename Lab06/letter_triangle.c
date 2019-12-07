//A program that read an positive integer n and outputs a triangle of letters of height n
//Written on 18/06/2019
//Witten by Megan Michelle Wong

#include <stdio.h>

int abc(int a);

int main(void){
    
    int n = 0;
    int a = 0;
    int size = 0;
    int letter = 0;
    
    printf("Enter height: ");
    scanf("%d",&n);
    //width of the triangle
    size = 2*n-1;
    
    //Loop for height
    for(int i = 0; i < n; i++){
        letter = letter + i;  //First letter for each row
        if(letter >= 26){
            letter = letter-26;
        }
        a = letter;
        //Loop for the triangle's width
        for(int j = 0; j < size; j++){
            if( (j >= n-i-1) && (j <= n+i-1) ){
                //Left triangle and middle
                if( j <= size/2-1 ){
                    a = abc(a);
                    printf("%c",'A' + a);
                    a++;
                }
                //Right triangle
                if( j > size/2-1 ){
                    a = abc(a);
                    printf("%c",'A' + a);
                    a--;
                }
            } else {
                printf(" ");  //spaces
            }
        }
        printf("\n");
    }
}

//Function to change Z to A if necessary
int abc(int a){
    if( (a >= 0) && (a <= 25) ){
        return a;
    } else if(a > 25){
        return a - 26;
    } else {
        return 26 + a;
    }
}

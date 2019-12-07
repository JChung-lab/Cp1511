//This program reads in a 3x3 noughts and crosses (Tic-Tac-Toe) board, stores it in a 2D array and then prints it out.
//11/06/2019
//Written by Megan Michelle Wong

#include<stdio.h>
#define SIZE 3

void readBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);

int main(void){
    
    int board[SIZE][SIZE];
    readBoard(board);
    printBoard(board);
    
    return 0;
}

void readBoard(int board[SIZE][SIZE]){
    
    printf("Please enter the board:\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            scanf("%d",&board[i][j]);
        }
    }
}

void printBoard(int board[SIZE][SIZE]){

    printf("Here is the board:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if(board[i][j] == 0){
                printf("O ");
            }else if(board[i][j] == 1){
                    printf("X ");
            }else if(board[i][j] == 2){
                    printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
}

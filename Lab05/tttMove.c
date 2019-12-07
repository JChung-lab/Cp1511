//This program reads in a 3x3 noughts and crosses (Tic-Tac-Toe) board, stores it in a 2D array and then prints it out. Then it allows the nought player to make a move.
//11/06/2019
//Written by Megan Michelle Wong

#include <stdio.h>
#include <stdlib.h>
#define SIZE 3

void readBoard(int board[SIZE][SIZE]);
void printBoard(int board[SIZE][SIZE]);
void winner(int board[SIZE][SIZE]);
void move(int board[SIZE][SIZE]);

int main(void){
    
    int board[SIZE][SIZE];
    readBoard(board);
    printBoard(board);
    move(board);
    return 0;
}

//Function to fill the board
void readBoard(int board[SIZE][SIZE]){
    
    printf("Please enter the board:\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            scanf("%d",&board[i][j]);
        }
    }
}

//Function to print the board
void printBoard(int board[SIZE][SIZE]){

    printf("Here is the board:\n\n");
    for(int i = 0; i < SIZE; i++){
        for(int j = 0; j < SIZE; j++){
            if ( board[i][j] == 0 ){
                printf("O ");
            } else if ( board[i][j] == 1 ){ 
                    printf("X ");
            } else if ( board[i][j] == 2 ){
                    printf(". ");
            }
        }
        printf("\n");
    }
    printf("\n");
} 

//Function to check winners in the board
void winner(int board[SIZE][SIZE]){
    //Check winner of the rows
    for(int i = 0; i < SIZE; i++){
            if( board[0][i] == board[1][i] && board[2][i] == board[0][i] ){
                if( board[0][i] == 0 ){
                    printf("Noughts win\n");
                    exit(EXIT_SUCCESS);
                }
                if( board[0][i] == 1 ){
                    printf("Crosses win\n");
                    exit(EXIT_SUCCESS);
                }
                    //Check winner of the columns
            } else if( board[i][0] == board[i][1] && board[i][0] == board[i][2] ){
                    if( board[i][0] == 0 ){
                        printf("Noughts win\n");
                        exit(EXIT_SUCCESS);
                    }
                    if( board[i][0]==1 ){
                    printf("Crosses win\n");
                    exit(EXIT_SUCCESS);
                    }
                    //Check winner for principal diagonal
            } else if( board[0][0] == board[1][1] && board[2][2] == board[1][1] ){
                    if( board[0][0] == 0 ){
                        printf("Noughts win\n");
                        exit(EXIT_SUCCESS);
                    }
                    if( board[0][0] == 1 ){
                    printf("Crosses win\n");
                    exit(EXIT_SUCCESS);
                    }
                    //Check winner for second diagonal
            } else if( board[0][2] == board[1][1] && board[1][1] == board[2][0] ){
                    if( board[1][1] == 0 ){
                        printf("Noughts win\n");
                        exit(EXIT_SUCCESS);
                    }
                    if( board[1][1] == 1 ){
                        printf("Crosses win\n");
                        exit(EXIT_SUCCESS);
                    }
            }
    }
    //Check for dots in the board
    for(int i = 0;i < SIZE; i++){
        for(int j = 0;j < SIZE; j++){
            if( board[i][j] == 2){
                printf("There are no winners\n");
                exit(EXIT_SUCCESS);
            }
        }
    }
    printf("It is a draw\n");
    exit(EXIT_SUCCESS);
}

//Function for the noughts to make the move
void move(int board[SIZE][SIZE]){
    int a = 0;
    int b = 0;
    printf("Please enter your move Noughts: ");
    scanf("%d %d", &a, &b);
    if( a > 2 || b > 2 || a < 0 || b < 0 ){
        printf("Invalid Move\n");
        exit(EXIT_SUCCESS);
    } else {
        for(int i = 0; i < SIZE; i++){
            for(int j = 0; j < SIZE; j++){
                if( i == a && j == b && ( board[i][j] == 0 || board[i][j] == 1 )){
                    printf("Invalid Move\n");
                    exit(EXIT_SUCCESS);
                }else if( i == a && j == b && board[a][b] == 2){
                    board[a][b] = 0;
                    printBoard(board);
                    winner(board);
                    exit(EXIT_SUCCESS); 
                }
            }
        }
    }
}

    

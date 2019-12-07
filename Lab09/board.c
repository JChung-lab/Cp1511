//This is a program that it reads in 16 pieces and places each one in a cell on a board from left-to-right, top-to-bottom 
//Written by Megan Wong z5241209
//09/07/2019

#include <stdio.h>
#include <stdlib.h>

#define SIZE 4

typedef struct piece Piece;
    
struct piece {
    char color;
    char symbol;
};

// Prints out a piece in the following format
// colour/symbol eg. R/*
void printPiece(Piece p);

// Reads in a piece from stdin and checks it is valid
// If a valid piece was read in, it returns 1
// Returns 0 otherwise
int readPiece(Piece * p);
void readBoard(Piece p[SIZE][SIZE]);

int main(int argc, char *argv[]){
    
    Piece p[SIZE][SIZE];
    printf("Enter pieces: ");
    readBoard(p);
}

void printPiece(Piece p) {
    printf("%c/%c ",p.color,p.symbol);
}

int readPiece(Piece * p) {
    (*p).color = getchar();
    (*p).symbol = getchar();
    getchar();
    if( p->color != 'R' && p->color != 'B' && p->color != 'Y' && p->color != 'G'
    && p->symbol != '*' && p->symbol != '^' && p->symbol != '#' && p->symbol != '$') {
        return 0;
    } else {
        return 1;
    }
}

void readBoard(Piece p[SIZE][SIZE]) {
    for(int i = 0; i < SIZE; i++) {
        for(int j = 0; j < SIZE; j++) {
            if( readPiece(&p[i][j]) == 1 ) {
                printPiece(p[i][j]);
            } else {
                printf("Invalid Input\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("\n");
    }
}

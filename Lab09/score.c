//This is a program that after printing out the board it calculates a score. There is 1 point for every 4 identical pieces in a row and every 4 identical pieces in a column
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
int score(Piece p[SIZE][SIZE]);

int main(int argc, char *argv[]) {
    
    Piece p[SIZE][SIZE];
    printf("Enter pieces: ");
    readBoard(p);
    printf("Score is %d\n",score(p));
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
            if( readPiece(&p[i][j]) == 1 ){
                printPiece(p[i][j]);
            } else {
                printf("Invalid Input\n");
                exit(EXIT_FAILURE);
            }
        }
        printf("\n");
    }
}

int areEqual(Piece p1, Piece p2) {
    if( (p1.color == p2.color) && (p1.symbol == p2.symbol) ) {
        return 1;
    }else {
        return 0;
    }
}

int score(Piece p[SIZE][SIZE]) {
    int score = 0;
    int countRow;
    int countCol;
    for(int i = 0; i < SIZE; i++) {
        countRow = 0;
        for(int j = 0; j < SIZE-1; j++) {
            if( areEqual(p[i][j],p[i][j+1]) == 1 ) {
                countRow++;
            }
        }
        if(countRow == 3) {
            score++;
        }
    }
    for(int j = 0; j < SIZE; j++) {
        countCol = 0;
        for(int i = 0; i < SIZE-1; i++) {
            if(areEqual(p[i][j],p[i+1][j]) == 1) {
                countCol++;
            }
        }
        if(countCol==3) {
            score++;
        }
    }
    return score;
}

//This is a program that reads in information about 2 pieces from a game and prints out whether they are equalal pieces in a row and every 4 identical pieces in a column
//Written by Megan Wong z5241209
//09/07/2019

#include <stdio.h>
#include <stdlib.h>

typedef struct piece Piece;
    
struct piece {
    char color;
    char symbol;
};
    
//Returns 1 if p1 and p2 have the same colour and symbol
//Returns 0 otherwise
int areEqual(Piece p1,Piece p2);

// Prints out a piece in the following format
// colour/symbol eg. R/*
void printPiece(Piece p);

// Reads in a piece from stdin and checks it is valid
// If a valid piece was read in, it returns 1
// Returns 0 otherwise
int readPiece(Piece * p);

int main(int argc, char *argv[]) {
    
    Piece p1;
    Piece p2;
    
    printf("Enter 2 pieces: ");
    if( readPiece(&p1) == 0 || readPiece(&p2) == 0 ) {    
        fprintf(stderr, "Invalid Input\n");
        exit(EXIT_FAILURE);
    } else {
        if( areEqual(p1,p2) == 1 ) {
            printPiece(p1);
            printf(" equals ");
            printPiece(p2);
            printf("\n");
        } else {
            printPiece(p1);
            printf(" does not equal ");
            printPiece(p2);
            printf("\n");
        }
    }
}

int areEqual(Piece p1,Piece p2) {
    if( (p1.color == p2.color) && (p1.symbol == p2.symbol) ) {
        return 1;
    } else {
        return 0;
    }
}

void printPiece(Piece p) {
    printf("%c/%c",p.color,p.symbol);
}

int readPiece(Piece * p) {
    
    if( scanf("%c%c",&(p->color), &(p->symbol)) == 2 ) {
        getchar();
        if( p->color == 'R' || p->color == 'B' || p->color == 'Y' || p->color == 'G' ){
            if(p->symbol == '*' || p->symbol == '^' || p->symbol == '#' || p->symbol == '$'){
                return 1;
            }
            else {
                return 0;
            }
            
        } else {
            return 0;
        } 
    }
    return 0;
}

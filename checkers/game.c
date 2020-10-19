#include <stdio.h>
#include <stdlib.h> 

//black will be 1, red will be 2
#define BLACK 1
#define RED 2
#define BOARD_H 8
#define BOARD_W 8


//checkers pieces are able to be red or black

/*isValid checks if a given coordinate on the board is a valid
location for a piece. Returns 1 if valid, 0 if not
PRECONDITION: 0 < r < BOARD_H and 0 < c < BOARD_W*/
int isValid(int r, int c){
    if(!(r % 2)){
        if(c % 2){
            return 1;
        }
    }else{
        if(!(c%2)){
            return 1;
        }
    }
    return 0; 
}

/*populate takes in an EMPTY board and sets it up 
as a proper checkers board. 12 pieces of each color, only on black 
squares (odd spots in the columns when r is even, even when r is odd)
*/
void populate(int b[BOARD_H][BOARD_W]){
    //FIX THESE ARE 2D ARRAYS
    for(int r = 0; r<BOARD_H; r++){
        for (int c = 0; c < BOARD_W; c++){
            b[r][c] = 0; //fill with 0s
            if(r<=2){
                if(r%2 == 0 && !(c%2)){
                    b[r][c] = BLACK; //set the black pieces to the far side
                }else if (r%2 != 0 && (c%2)){
                    b[r][c] = BLACK; //
                } 
            }
            if(r>=5){
                if(r%2 == 0 && (c%2)){
                    b[r][c] = RED; //set the red pieces to the close side
                }else if (r%2 != 0 && !(c%2)){
                    b[r][c] = RED; //alternated row
                } 
            }
        }
        
    }
}

/*isValidMove checks if a proposed move coordinate is valid
for a piece to move to. This means newR and newC represent a 
coordinate on the board that is diagonally forwards from 
oldR and oldC*/
int isValidMove(int b[BOARD_H][BOARD_W], int oldR, int oldC, int newR, int newC){
    if(isValid(oldR, oldC) && isValid(newR, newC)){
        int color = b[oldR][oldC];
        //black and red move in different directions
        //this isn't the best code tbh
        if(color == BLACK && newR == (oldR + 1) && (newC == oldC + 1 || newC == oldC - 1)){
            return 1;
        }
        if(color == RED && newR == (oldR - 1) && (newC == oldC + 1 || newC == oldC - 1)){
            return 1;
        }
    }
    return 0;
}

/*move takes in a board, an old set of piece coordinates, and a new set, 
checks if the coordinates are valid by the rules of the game, and "moves" 
the piece to the new location by setting its old location in the board array 
to 0 and the new coordinate to the correct color.

Pieces can only move diagonally forwards 1 space.

PRECONDITIONS:
oldC, newC must be between 0 and BOARD_W
oldR, newR must be between 0 and BOARD_H
*/
void move(int b[BOARD_H][BOARD_W], int oldR, int oldC, int newR, int newC){
    //check if the coords are valid on the board
    if(isValid(oldR, oldC) && isValid(newR, newC)){
        int color = b[oldR][oldC];
        if(color != 0){ //make sure something is actually at the spot
            //check if move is valid
            if(isValidMove(b, oldR, oldC, newR, newC)){
                b[oldC][oldR] = 0;
                b[newR][newC] = color;
            }
        } 
    } 
}

//Just prints the board as a grid of numbers
void printBoard(int b[BOARD_H][BOARD_W]){
    for(int r = 0; r<BOARD_H; r++){
        for (int c = 0; c < BOARD_W; c++){
                if(c == 7){
                    printf("%d\n", b[r][c]);
                }else
                {
                    printf("%d", b[r][c]);
                }
                
            }
        }
        
}

void main(){
    int board[BOARD_H][BOARD_W]; 
    populate(board);
    printBoard(board);
}


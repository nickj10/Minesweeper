#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include "LS_allegro.h"

#define MAXNOM 30
#define MAXAUX 50
#define HEADER_SIZE 60
#define UP 1
#define DOWN 2
#define LEFT 3
#define RIGHT 4

typedef struct {
    char *nom_player;
    int temps;
    char *nom_taulell;
} Player;

typedef struct {
    int col;
    int fila;
    int num_mines;
    char **mines;
    int **turned;
} Taulell;

typedef struct {
    int x1;
    int y1;
    int x2;
    int y2;
    int row;
    int column;
} Cursor;

void fflushnou ();
int myAtoi (char *num);
Taulell sacarTaulell (FILE *f_taulell);
void initCursor (Cursor *cur);
void moveCursor (Cursor *cursor, int direction, int height, int width);
void turnSquare (Cursor cursor, Taulell *taulell);
void turnAllSquares (Taulell *taulell);
void startGame (Taulell *taulell, Player player);

#endif
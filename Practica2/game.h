#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include "LS_allegro.h"

#define MAXNOM 30
#define MAXAUX 50
#define HEADER_SIZE 60

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
} Cursor;

void fflushnou ();
int myAtoi (char *num);
void initCursor (Cursor *cur);
Taulell sacarTaulell (FILE *f_taulell);
void startGame (Taulell *taulell, Player player);

#endif
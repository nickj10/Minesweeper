#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include "LS_allegro.h"
#define MAXNOM 30
#define MAXAUX 50

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
} Taulell;

void fflushnou ();
int myAtoi (char *num);
Taulell sacarTaulell (FILE *f_taulell);
void startGame (Taulell *taulell, Player player);

#endif
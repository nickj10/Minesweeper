/*********************************************************
 *
 * @Proposit: Aquest fitxer conté les llibreries, les
 *      estructures, les constants i els prototipus de les
 *      funcions del mòdul GAME.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 26/03/2018
 * @Data ultima modificacio: 09/05/2018
 * 
 ********************************************************/

#ifndef _GAME_H
#define _GAME_H

#include <stdio.h>
#include <time.h>
#include "LS_allegro.h"
#include "flag.h"

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
    int x;
    int y;
} Coordenada;


typedef struct {
    Coordenada coord1;
    Coordenada coord2;
    Coordenada coord3;
} Flagcoord;

typedef struct {
    int col;
    int fila;
    int num_mines;
    int total_squares;
    char **mines;
    int **turned;
    Flags lista;
} Taulell;

typedef struct {
    Coordenada coord1;
    Coordenada coord2;
    int row;
    int column;
} Cursor;

int myAtoi (char *num);
int sacarNumero (char *aux);
Taulell sacarTaulell (FILE *f_taulell);
void initCursor (Cursor *cur);
void moveCursor (Cursor *cursor, int direction, int height, int width);
int flipSquare (Cursor cursor, Taulell *taulell);
void flipAllSquares (Taulell *taulell);
void putFlag (Cursor cursor, Taulell *taulell);
void checkGameover (Taulell taulell, int *win, int *gameover);
int startGame (Taulell *taulell, Player *player, int *win);
void freeMemoria (Taulell *taulell, Player *player);

#endif
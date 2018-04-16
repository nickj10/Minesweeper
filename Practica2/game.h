/*********************************************************
 *
 * @Proposit: Aquest fitxer conté les llibreries, les
 *      estructures, les constants i els prototipus de les
 *      funcions del mòdul GAME.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 26/03/2018
 * @Data ultima modificacio: 03/04/2018
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
    //int activada;
    //int row;
    //int column;
    //Elemento e;
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
    //Flagcoord **flags_coord;
    Flags lista;
} Taulell;

typedef struct {
    //int x1;
    //int y1;
    //int x2;
    //int y2;
    Coordenada coord1;
    Coordenada coord2;
    int row;
    int column;
} Cursor;


void fflushnou ();
int myAtoi (char *num);
Taulell sacarTaulell (FILE *f_taulell);
void initCursor (Cursor *cur);
void moveCursor (Cursor *cursor, int direction, int height, int width);
int turnSquare (Cursor cursor, Taulell *taulell, int *girada);
void turnAllSquares (Taulell *taulell);
void putFlag (Cursor cursor, Taulell *taulell, int *total);
int startGame (Taulell *taulell, Player *player);
void freeMemoria (Taulell *taulell, Player *player);

#endif
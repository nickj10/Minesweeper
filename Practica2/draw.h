#ifndef _DRAW_H
#define _DRAW_H

#include "LS_allegro.h"
#include "game.h"

#define SQUARE_SIZE 80

typedef struct {
    int x;
    int y;
} Coordenada;

void drawHeader (Player player, int width);
void drawSquares (Taulell taulell);
void drawCursor (Cursor cur);
void drawContent (Taulell taulell);
void drawFlags (Taulell taulell);

#endif
#ifndef _DRAW_H
#define _DRAW_H

#include "LS_allegro.h"
#include "game.h"

#define SQUARE_SIZE 80

void drawHeader (Player player, int width);
void drawSquares (Taulell taulell);
void drawCursor (Cursor cur);


#endif
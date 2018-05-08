/*********************************************************
 *
 * @Proposit: Aquest fitxer conté les llibreries, les
 *      estructures, les constants i els prototipus de les
 *      funcions del mòdul DRAW.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 27/03/2018
 * @Data ultima modificacio: 03/04/2018
 * 
 ********************************************************/

#ifndef _DRAW_H
#define _DRAW_H

#include "LS_allegro.h"
#include "game.h"

#define SQUARE_SIZE 80

void drawHeader (Player player, int width);
void drawSquares (Taulell taulell);
void drawCursor (Cursor cur);
void drawContent (Taulell taulell);
void drawFlags (Taulell taulell);
void drawGameover (Player player, Taulell taulell, int width, int height, int win);

#endif
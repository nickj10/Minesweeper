#ifndef _GAME_H
#define _GAME_H

#include "LS_allegro.h"
#define MAXNOM 30

typedef struct {
    char *nom_player;
    int temps;
    char *nom_taulell;
} Player;

void fflushnou ();
void startGame ();

#endif
#ifndef _RANKING_H
#define _RANKING_H

#include "game.h"

#define MAXBUFFER 50

char *sacarInfo (char *cad, int *index, char delim);
Player sacarPlayer (char *cad);
void mostrarRanking ();

#endif
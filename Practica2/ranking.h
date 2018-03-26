#ifndef _RANKING_H
#define _RANKING_H

#include "game.h"

#define MAXBUFFER 50

int myAtoi (char *num);
void mostrarRanking ();
Player sacarPlayer (char *cad);
char *sacarInfo (char *cad, int *index, char delim);

#endif
/*********************************************************
 *
 * @Proposit: Aquest fitxer conté les llibreries i els
 *      prototipus de les funcions del mòdul RANKING. També
 *      está definida la constant necessària.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 26/03/2018
 * @Data ultima modificacio: 03/04/2018
 * 
 ********************************************************/

#ifndef _RANKING_H
#define _RANKING_H

#include <stdio.h>
#include "game.h"

#define MAXBUFFER 50

char *sacarInfo (char *cad, int *index, char delim);
Player sacarPlayer (char *cad);
void mostrarRanking ();
void addRanking (Player jugador);

#endif
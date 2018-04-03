/*********************************************************
 *
 * @Proposit: Aquest fitxer conté la implementació de totes
 *      les funcions del mòdul RANKING. Aquestes funcions
 *      estan relacionades amb la visualització del rankquing
 *      i per treure les dades del jugador.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 26/03/2018
 * @Data ultima modificacio: 03/04/2018
 * 
 ********************************************************/

#include "ranking.h"

void mostrarRanking () {
    FILE *f_ranking;
    Player jugador;
    char *buffer;
    
    buffer = (char*)malloc(sizeof(char) * MAXBUFFER);
    f_ranking = fopen ("ranquing.txt","r");
    printf ("#####################################\n");
    printf ("# NOM - TAULELL - PUNTS #\n");
    printf ("#####################################\n");   
    if (!f_ranking) {
        printf ("---- ---- ----\n");
    }
    else {
        fgets (buffer, MAXBUFFER, f_ranking);
        while (!feof(f_ranking)) {
            jugador = sacarPlayer(buffer);
            printf ("%s - %s - %d\n", jugador.nom_player, jugador.nom_taulell, jugador.temps);
            fgets (buffer, MAXBUFFER, f_ranking);
        }
        // Sacar la informacio de l'ultim jugador
        jugador = sacarPlayer(buffer);
        printf ("%s - %s - %d\n", jugador.nom_player, jugador.nom_taulell, jugador.temps);
    }
}

Player sacarPlayer (char *cad) {
    Player jugador;
    int i_cad = 0;
    char *temps;
    temps = (char*)malloc(sizeof(char) * 10);
    jugador.nom_player = sacarInfo (cad, &i_cad, '#');
    jugador.nom_taulell = sacarInfo (cad, &i_cad, '#');
    temps = sacarInfo (cad, &i_cad, '\n');
    jugador.temps = myAtoi (temps);
    return jugador;
}

char *sacarInfo (char *cad, int *index, char delim) {
    char *info = (char*)malloc(sizeof(char) * MAXNOM);
    int i_info = 0;
    info = (char*)malloc(sizeof(char) * MAXNOM);
    while (cad[*index] != delim) {
        info[i_info++] = cad[(*index)++];
    }
    info[i_info] = '\0';
    ++(*index);
    return info;
}


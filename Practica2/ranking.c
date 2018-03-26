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
    ++(*index);
    return info;
}

int myAtoi (char *num) {
    int number = 0;
    int negatiu = 0;
    int i_num = 0;
    
    // Mirem si el numero es negatiu
    if (num[i_num] == '-') {
        negatiu = 1;
        ++i_num;
    }
    while (num[i_num] != '\0') {
        number = number * 10 + num[i_num++] - '0';
    }
    if (negatiu == 1) {
        number *= -1;
    }
    return number;
}
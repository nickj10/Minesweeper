/*********************************************************
 *
 * @Proposit: Aquest fitxer conté la implementació de totes
 *      les funcions del mòdul RANKING. Aquestes funcions
 *      estan relacionades amb la visualització del rankquing
 *      i per treure les dades del jugador.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 26/03/2018
 * @Data ultima modificacio: 09/05/2018
 * 
 ********************************************************/

#include "ranking.h"

/*********************************************************
*
* @Finalitat: Llegir les dades dels jugadores des del fitxer
*       de text del ranquing i mostrarlos per pantalla
* @Parametres: --
* @Retorn: --
*
*********************************************************/
void mostrarRanking () {
    FILE *f_ranking;
    Player jugador;
    char *buffer;
    
    // Guardem espai de memoria per al buffer
    buffer = (char*)malloc(sizeof(char) * MAXBUFFER);
    
    // Obrim el fitxer de ranquing
    f_ranking = fopen ("ranquing.txt","r");
    printf ("#####################################\n");
    printf ("# NOM - TAULELL - PUNTS #\n");
    printf ("#####################################\n");   
    if (f_ranking == NULL) {
        printf ("---- ---- ----\n");
    }
    else {
        fgets (buffer, MAXBUFFER, f_ranking);
        while (!feof(f_ranking)) {
            jugador = sacarPlayer(buffer);
            printf ("%s - %s - %d\n", jugador.nom_player, jugador.nom_taulell, jugador.temps);
            fgets (buffer, MAXBUFFER, f_ranking);
        }
        fclose (f_ranking);
    }
}

/*********************************************************
*
* @Finalitat: Treure les dades d'un jugador
* @Parametres: in: cad = un punter que apunta a la cadena que
*       conté les dades d'un jugador
* @Retorn: Retorna un registre de tipus Player on s'han guardat
*       la informació
*
*********************************************************/
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

/*********************************************************
*
* @Finalitat: Treure cada informació fins a trobar el delimitador
* @Parametres: in: cad = un puntero que apunta a una cadena que
*                   conté tota la informacio
*               in: index = l'index de la casella en la cadena
*                   passar per referencia
*               in: delim = el caracter que separa la informacio
* @Retorn: Retorna la cadena on hem guardat la informacio
*
*********************************************************/
char *sacarInfo (char *cad, int *index, char delim) {
    char *info = (char*)malloc(sizeof(char) * MAXNOM);
    int i_info = 0;
    info = (char*)malloc(sizeof(char) * MAXNOM);
    while (cad[*index] != delim) {
        info[i_info++] = cad[(*index)++];
    }
    info[i_info] ='\0';
    ++(*index);
    return info;
}

/*********************************************************
*
* @Finalitat: Afegir les dades del jugador que ha guanyat la partida
*       en el fitxer de text del ranquing
* @Parametres: in: jugador = el registre que conte les dades del jugador
* @Retorn: No retorna res
*
*********************************************************/
void addRanking (Player jugador) {
    FILE *f_ranking;
    
    f_ranking = fopen ("ranquing.txt","a");
    if (f_ranking == NULL) {
        printf ("Error, no es pot obrir el fitxer ranquing.txt\n");
    }
    else {
        fprintf (f_ranking, "%s#%s#%d\n", jugador.nom_player, jugador.nom_taulell, jugador.temps);
        fclose (f_ranking);
    }
}
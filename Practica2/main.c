#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "LS_allegro.h"
#include "game.h"
#include "ranking.h"


int main () {
    FILE *f_taulell;
    Player player;
    Taulell taulell;
    char opcio;
    int gameover;
    
	while (opcio != '3') {
		
		printf ("\nMenu:\n");
		printf ("1- Nova partida\n");
		printf ("2- Mostrar ranquing\n");
		printf ("3- Sortir\n");
        printf ("Opcio: ");
        scanf ("%c", &opcio);
        
        // Netegem el buffer perquè no ens agafi la \n
        fflushnou ();
		
		switch (opcio) {
			case '1': // Nova partida
			
                player.nom_player = (char*)malloc(sizeof(char) * MAXNOM);
                player.nom_taulell = (char*)malloc(sizeof(char) * MAXNOM);
                if (player.nom_player == NULL) {
                    printf ("Error en guardar memoria per el nom del jugador.\n");
                }
                else {
                    do {
                        printf ("Introdueix nom del jugador: ");
                        gets (player.nom_player);
                        if (strlen(player.nom_player) > MAXNOM) {
                            printf ("Error, el nom del jugador ha de tenir com a maxim 30 caracters.\n");
                        }
                    } while (strlen(player.nom_player) > MAXNOM);
                    do {
                        printf ("Introdueix nom del fitxer: ");
                        gets (player.nom_taulell);
                        printf ("txt: %s\n", player.nom_taulell);
                        f_taulell = fopen (player.nom_taulell, "r");
                        if (!f_taulell) {
                            printf ("\nError, no es troba el fitxer %s!\n\n", player.nom_taulell);
                        }
                    } while (!f_taulell);
                    
                    printf ("Informacio correcte.\n");
                    printf ("Processant informacio...\n");
                    taulell = sacarTaulell (f_taulell);
                    printf ("%d - %d - %d\n", taulell.col, taulell.fila, taulell.num_mines);
                    printf ("Partida iniciada correctament.\n");
                    // De moment, posem 269 com a temps per el jugador
                    player.temps = 0;
                    gameover = startGame (&taulell, &player);
                    if (gameover) {
                        printf ("\nEl jugador: %s\n", player.nom_player);
                        printf ("Puntuacio: %d\n\n", player.temps);
                        printf ("Partida finalitzada correctament!\n");
                    }
                    else {
                        printf ("\nPartida finalitzada per jugador!\n");
                    }
                }

                break;
            case '2': // Mostrar ranquing
                mostrarRanking ();
                break;
    
            case '3': // Sortir
                printf ("\nGracies per jugar!\n");
                break;
                
            default: // En cas d'error en l'opcio
                if (opcio < '0' || opcio > '9' ) {
                    printf ("Error, opcio incorrecta. La opcio ha de ser un nombre.\n");
                }
                else {
                    printf ("Error, opcio incorrecta. Ha de ser un numero d'1 a 3.\n");
                }
                break;
		}
	}
	return 0;
}

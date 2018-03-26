#include <stdio.h>
#include <stdlib.h>
#include "LS_allegro.h"
#include "game.h"

int main () {
    FILE *f_taulell;
    FILE *f_ranking;
	char opcio;
	int nSortir = 0;
    Player player;
    
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
                    printf ("Introdueix nom del jugador: ");
                    gets (player.nom_player);
                    do {
                        printf ("Introdueix nom del fitxer: ");
                        gets (player.nom_taulell);
                        //printf ("%s - %s\n", player.nom_player, player.nom_taulell);
                        f_taulell = fopen (player.nom_taulell, "r");
                        if (!f_taulell) {
                            printf ("Error, no es troba el fitxer %s!\n", player.nom_taulell);
                        }
                    } while (!f_taulell);
                }
				//Inicialitzem Allegro
				LS_allegro_init(1280,720,"PGM1 - PRS 2");
	
	
				//Bucle infinit del joc
				while(!nSortir){
		
					//Escoltem el teclat esperant la tecla ESC
					if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
						nSortir = 1;
					}
					
					//Donem l'ordre d'escriure el text de benvinguda
					al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),140,100,0,"%s","Benvingut a Allegro! Prem ESC per sortir...");
				
					//Pintem la pantalla de la finestra gràfica
					LS_allegro_clear_and_paint(BLACK);
				}
				
				
				//Tanquem la finestra gràfica
				LS_allegro_exit();
				break;
			case '2': // Mostrar ranquing
			
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

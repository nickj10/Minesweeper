#include <stdio.h>
#include "LS_allegro.h"

int main () {
	char opcio = ' ';
	int nSortir = 0;
	
	while (opcio != '3') {
		
		printf ("Menu:\n");
		printf ("1- Nova partida\n");
		printf ("2- Mostrar ranquing\n");
		printf ("3- Sortir\n");
        printf ("Opcio: ");
        scanf ("%c", &opcio);
		
		switch (opcio) {
			case '1': // Nova partida
			
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
				printf ("Error, opcio incorrecta. Ha de ser un numero d'1 a 3.\n");
				break;
		}
	}
	return 0;
}

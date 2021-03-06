/*********************************************************
 *
 * @Proposit: Aquest fixter conté la implementació de les
 *      funcions del mòdul DRAW. Aquestes funcions són per
 *      pintar les diferents parts del joc a la pantalla.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 27/03/2018
 * @Data ultima modificacio: 09/05/2018
 * 
 ********************************************************/

#include "draw.h"

/*********************************************************
*
* @Finalitat: Dibuixar la capçalera de la finestra del joc
* @Parametres:  in: player = el registre que conte les dades del jugador
*               in: width = l'amplada de la finestra
* @Retorn: No retorna res
*
*********************************************************/
void drawHeader (Player player, int width) {
    al_draw_textf (LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), 5, 5, 0, "%s", "NOM:");
    al_draw_textf (LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), width/2, 5, 0, "%s", "TEMPS:");
    if (strlen(player.nom_player) <= 10) {
        al_draw_textf (LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(WHITE), width/15, 20, 0, "%s", player.nom_player);
        al_draw_textf (LS_allegro_get_font(EXTRA_LARGE), LS_allegro_get_color(WHITE), width/2 + width/15, 20, 0, "%d", player.temps);
    }
    else {
        if (strlen(player.nom_player) <= 15) {
            al_draw_textf (LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), width/15, 20, 0, "%s", player.nom_player);
            al_draw_textf (LS_allegro_get_font(LARGE), LS_allegro_get_color(WHITE), width/2 + width/15, 20, 0, "%d", player.temps);
        }
        else {
            al_draw_textf (LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), width/15, 20, 0, "%s", player.nom_player);
            al_draw_textf (LS_allegro_get_font(NORMAL), LS_allegro_get_color(WHITE), width/2 + 20, 20,0, "%d", player.temps);
        }
    }
}

/*********************************************************
*
* @Finalitat: Dibuixar les caselles del taulell
* @Parametres:  in: taulell = el registre que conte totes les 
*       dades del taulell
* @Retorn: No retorna res
*
*********************************************************/
void drawSquares (Taulell taulell) {
    int i_fil, j_col;
    int x1 = 1;
    int y1 = HEADER_SIZE + 1;
    int x2 = x1 + SQUARE_SIZE;
    int y2 = y1 + SQUARE_SIZE;
    
    // Mirar cada casella si esta girada
    for (i_fil = 0; i_fil < taulell.fila; i_fil++) {
        for (j_col = 0; j_col < taulell.col; j_col++) {
            // En cas de que no estigui girada, la dibuixem en gris
            if (taulell.turned[i_fil][j_col] == 0) {
                al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(GRAY));
            }
            else {
                // En cas contrari, el color depen del contingut
                if (taulell.turned[i_fil][j_col] == 1) {
                    if (taulell.mines[i_fil][j_col] == 'M') {
                            al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(RED));
                    }
                    else {
                        al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(WHITE));
                    }
                }
            }
            x1 += (SQUARE_SIZE + 1);
            x2 += (SQUARE_SIZE + 1);
        }
        x1 = 1;
        x2 = x1 + SQUARE_SIZE;
        y1 += (SQUARE_SIZE + 1);
        y2 += (SQUARE_SIZE + 1);
    }
}

/*********************************************************
*
* @Finalitat: Dibuixar lel cursor
* @Parametres:  in: cur = el registre que conte les coordenades
*       del cursor
* @Retorn: No retorna res
*
*********************************************************/
void drawCursor (Cursor cur) {
    al_draw_rectangle (cur.coord1.x, cur.coord1.y, cur.coord2.x, cur.coord2.y,LS_allegro_get_color(LIGHT_GREEN),1);
}

/*********************************************************
*
* @Finalitat: Dibuixar el contingut de cada casella girada
* @Parametres:  in: taulell = el registre que conte totes les 
*       dades del taulell 
* @Retorn: No retorna res
*
*********************************************************/
void drawContent (Taulell taulell) {
    int i, j;
    Coordenada coord;
    for (i = 0; i < taulell.fila; i++) {
        for (j = 0; j < taulell.col; j++) {
            coord.x = (SQUARE_SIZE / 3) + j * (SQUARE_SIZE + 1);
            coord.y = (SQUARE_SIZE / 3) + HEADER_SIZE + i * (SQUARE_SIZE + 1);
            if (taulell.turned[i][j]) {
                if (taulell.mines[i][j] != 'M') {
                    al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(BLACK),coord.x,coord.y,0,"%c", taulell.mines[i][j]);
                }
            }
        }
    }
}

/*********************************************************
*
* @Finalitat: Dibuixar les banderes en el taulell
* @Parametres:  in: taulell = el registre que conte totes les 
*       dades del taulell 
* @Retorn: No retorna res
*
*********************************************************/
void drawFlags (Taulell taulell) {
    int i, j;
    Flagcoord aux;
    Elemento e;
    for (i = 0; i < taulell.fila; i++) {
        for (j = 0; j < taulell.col; j++) {
            e.col = j;
            e.fila = i;
            aux.coord1.x = (SQUARE_SIZE / 4) + j * (SQUARE_SIZE + 1);
            aux.coord1.y = (SQUARE_SIZE / 4) + HEADER_SIZE + i * (SQUARE_SIZE + 1);
            aux.coord2.x = aux.coord1.x;
            aux.coord2.y = aux.coord1.y + (SQUARE_SIZE / 2);
            aux.coord3.x = (SQUARE_SIZE - (SQUARE_SIZE / 4)) + j * (SQUARE_SIZE + 1);
            aux.coord3.y = (SQUARE_SIZE / 2) + HEADER_SIZE + i * (SQUARE_SIZE + 1);
            if (taulell.turned[i][j] == 0) {
                if (FLAG_existeElemento(&taulell.lista, e)) {
                    // Dibuixar la bandera
                    al_draw_filled_triangle (aux.coord1.x, aux.coord1.y, aux.coord2.x, aux.coord2.y, aux.coord3.x, aux.coord3.y,LS_allegro_get_color(DARK_GREEN));
                }
                else {
                    al_draw_filled_triangle (aux.coord1.x, aux.coord1.y, aux.coord2.x, aux.coord2.y, aux.coord3.x, aux.coord3.y,LS_allegro_get_color(GRAY));
                }
            }
        }
    }
}

/*********************************************************
*
* @Finalitat: Dibuixar el missatge de GameOver quan s'ha acabat
*       la partida correctament
* @Parametres:  in: taulell = el registre que conte totes les 
*                       dades del taulell 
*               in: player = el registre que conte les dades del jugador
*               in: width = l'amplada de la finestra
*               in: height = l'altura de la finestra
*               in: win = un enter que indica si s'ha guanyat la partida o no
* @Retorn: No retorna res
*
*********************************************************/
void drawGameover (Player player, Taulell taulell, int width, int height, int win) {
    Coordenada rect1;
    Coordenada rect2;
    int size_title, size_text;
    int gameover, nom, puntuacio;
    int height_taulell;
    
    // Calculem l'altura del taulell nomes
    height_taulell = height + HEADER_SIZE;
    
    // Calculem les coordenades del rectangle
    rect1.x = width / 5;
    rect1.y = height_taulell / 4;
    rect2.x = width - (width / 5);
    rect2.y = height_taulell - (height_taulell / 4);
    
    // Dibuixem els rectangles
    al_draw_filled_rectangle (rect1.x, rect1.y, rect2.x, rect2.y, LS_allegro_get_color(BLACK));
    al_draw_rectangle (rect1.x - 2, rect1.y - 2, rect2.x + 2, rect2.y + 2, LS_allegro_get_color(BLUE),2);
    
    // Determinem el tamany de les lletres dependent de les dimensions del taulell
    if (width < 250) {
        size_title = SMALL;
        size_text = SMALL;
    }
    else {
        if (width < 450) {
            size_title = NORMAL;
            size_text = SMALL;
        }
        else {
            size_title = LARGE;
            size_text = NORMAL;
        }
    }
    gameover = height_taulell / 3;
    nom = height_taulell / 2;
    puntuacio = nom + height_taulell * (1/8.0);
  
    // Dibuixem per pantalla les dades del jugador i el missatge de finalització de la partida
    if (win) {
        al_draw_textf (LS_allegro_get_font(size_title), LS_allegro_get_color(RED), width/3.5, gameover, 0, "%s", "HAS GUANYAT!");
    }
    else {
        al_draw_textf (LS_allegro_get_font(size_title), LS_allegro_get_color(RED), width/2.8, gameover, 0, "%s", "GAMEOVER!");
    }
    al_draw_textf (LS_allegro_get_font(size_text), LS_allegro_get_color(WHITE), width/3.5, nom, 0, "Nom del jugador: %s", player.nom_player);
    al_draw_textf (LS_allegro_get_font(size_text), LS_allegro_get_color(WHITE), width/3.5, puntuacio, 0, "Puntuacio: %d", player.temps * taulell.num_mines);
}
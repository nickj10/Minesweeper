/*********************************************************
 *
 * @Proposit: Aquest fixter conté la implementació de les
 *      funcions del mòdul DRAW. Aquestes funcions són per
 *      pintar les diferents parts del joc a la pantalla.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 27/03/2018
 * @Data ultima modificacio: 03/04/2018
 * 
 ********************************************************/

#include "draw.h"

void drawHeader (Player player, int width) {
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),5,5,0,"%s","NOM:");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),width/2,5,0,"%s","TEMPS:");
    if (strlen(player.nom_player) <= 10) {
        al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),width/15,20,0,"%s", player.nom_player);
        al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(WHITE),width/2 + width/15, 20,0,"%d", player.temps);
    }
    else {
        if (strlen(player.nom_player) <= 15) {
            al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),width/15,20,0,"%s", player.nom_player);
            al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),width/2 + width/15, 20,0,"%d", player.temps);
        }
        else {
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),width/15,20,0,"%s", player.nom_player);
            al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),width/2 + 20, 20,0,"%d", player.temps);
        }
    }
}

void drawSquares (Taulell taulell) {
    int i_fil, j_col;
    int x1 = 1;
    int y1 = HEADER_SIZE + 1;
    int x2 = x1 + SQUARE_SIZE;
    int y2 = y1 + SQUARE_SIZE;
    
    //al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(GRAY));
    //printf ("F %d C %d\n", taulell.fila, taulell.col);
    for (i_fil = 0; i_fil < taulell.fila; i_fil++) {
        for (j_col = 0; j_col < taulell.col; j_col++) {
            if (taulell.turned[i_fil][j_col] == 0) {
                al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(GRAY));
            }
            else {
                if (taulell.turned[i_fil][j_col] == 1) {
                    if (taulell.mines[i_fil][j_col] == 'M') {
                        //if (!taulell.flags[i_fil][j_col].activada) {
                            al_draw_filled_rectangle (x1, y1, x2, y2,LS_allegro_get_color(RED));
                        //}
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

void drawCursor (Cursor cur) {
    al_draw_rectangle (cur.coord1.x, cur.coord1.y, cur.coord2.x, cur.coord2.y,LS_allegro_get_color(LIGHT_GREEN),1);
}

void drawContent (Taulell taulell) {
    int i, j;
    Coordenada coord;
    for (i = 0; i < taulell.fila; i++) {
        for (j = 0; j < taulell.col; j++) {
            coord.x = (SQUARE_SIZE / 3) + j * (SQUARE_SIZE + 1);
            coord.y = (SQUARE_SIZE / 3) + HEADER_SIZE + i * (SQUARE_SIZE + 1);
            if (taulell.turned[i][j]) {
                if (taulell.mines[i][j] != 'M' && taulell.mines[i][j] != '0') {
                    al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(BLACK),coord.x,coord.y,0,"%c", taulell.mines[i][j]);
                }
            }
        }
    }
}

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
/*void drawFlags (Taulell taulell) {
    Flagcoord aux;
    Elemento e;
    int i, j, k;
    if (FLAG_vacia(taulell.lista)) {
        printf ("\nNo hay flags to draw.\n");
    }
    else {
        FLAG_irInicio(&taulell.lista);
        printf ("bruh\n");
        while (!FLAG_final(taulell.lista)) {
            e = FLAG_consultar(taulell.lista);
            i = e.fila;
            j = e.col;
            printf ("umabot\n");
            // Calculem les coordenades dels triangles
            aux.coord1.x = (SQUARE_SIZE / 4) + j * (SQUARE_SIZE + 1);
            aux.coord1.y = (SQUARE_SIZE / 4) + HEADER_SIZE + i * (SQUARE_SIZE + 1);
            aux.coord2.x = aux.coord1.x;
            aux.coord2.y = aux.coord1.y + (SQUARE_SIZE / 2);
            aux.coord3.x = (SQUARE_SIZE - (SQUARE_SIZE / 4)) + j * (SQUARE_SIZE + 1);
            aux.coord3.y = (SQUARE_SIZE / 2) + HEADER_SIZE + i * (SQUARE_SIZE + 1);  
            
            // Dibuixar la bandera
            al_draw_filled_triangle (aux.coord1.x, aux.coord1.y, aux.coord2.x, aux.coord2.y, aux.coord3.x, aux.coord3.y,LS_allegro_get_color(DARK_GREEN));
        }
    }

}*/

void drawGameover (int width, int height) {
    Coordenada rect1;
    Coordenada rect2;
    int size;
    rect1.x = width / 5.0;
    rect1.y = height / 3.0;
    rect2.x = width - (width / 5.0);
    rect2.y = height - (height / 3.0);
    //printf ("w: %d, h: %d\n", width, height);
    //printf ("dim rect: %d %d %d %d\n", rect1.x, rect1.y, rect2.x, rect2.y);
    al_draw_filled_rectangle (rect1.x, rect1.y, rect2.x, rect2.y,LS_allegro_get_color(BLACK));
    al_draw_rectangle (rect1.x - 2, rect1.y - 2, rect2.x + 2, rect2.y + 2,LS_allegro_get_color(BLUE),2);
    if (width < 200) {
        size = NORMAL;
    }
    else {
        if (width < 500) {
            size = LARGE;
        }
        else {
            size = EXTRA_LARGE;
            
        }
    }
    al_draw_textf(LS_allegro_get_font(size),LS_allegro_get_color(RED),width/3,height/2 - 20,0,"%s","GAMEOVER");
}
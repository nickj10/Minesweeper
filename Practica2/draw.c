#include "draw.h"

void draw_header (Player player, int width) {
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),5,5,0,"%s","NOM:");
    al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),width/2,5,0,"%s","TEMPS:");
    al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),25,20,0,"%s", player.nom_player);
    al_draw_textf(LS_allegro_get_font(LARGE),LS_allegro_get_color(WHITE),width/2 + 20, 20,0,"%d", player.temps);
}

void draw_squares (Taulell taulell) {
    
}
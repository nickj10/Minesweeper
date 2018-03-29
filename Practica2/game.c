#include "game.h"
#include "draw.h"

void fflushnou () {
    char buffer[20];   
    fgets (buffer,20,stdin);
    //while((getchar()) != '\n);
}

int sacarNumero (char *aux) {
    int num = 0;
    int i_aux = 2, i_cad = 0;
    char *cad = (char*)malloc(sizeof(char) * 5);
    printf ("AUX: %s\n", aux);
    printf ("AUX NUM: %c\n", aux[i_aux]);
    while (aux[i_aux] != '\n') {
        cad[i_cad++] = aux[i_aux++];
    }
    cad[i_cad] = '\0';
    num = myAtoi(cad);
    printf ("num: %d\n", num);
    return num;
}

Taulell sacarTaulell (FILE *f_taulell) {
    Taulell taulell;
    int i, j;
    int i_aux;
    char *aux = (char*)malloc(sizeof(char) * MAXAUX);

    fgets (aux, MAXAUX, f_taulell);
    taulell.col = sacarNumero (aux);
    fgets (aux, MAXAUX, f_taulell);
    taulell.fila = sacarNumero (aux);
    fgets (aux, MAXAUX, f_taulell);
    taulell.num_mines = sacarNumero (aux);
    
    // Calculem quantes n'hi ha en total
    taulell.total_squares = taulell.col * taulell.fila;
    
    // Guardem memoria per al taulell
    taulell.mines = (char**)malloc(sizeof(char*) * taulell.fila);
    for (i = 0; i < taulell.fila; i++) {
        taulell.mines[i] = (char*)malloc(sizeof(char) * taulell.col);
    }
    
    // Llegir cada fila del fitxer per construir el taulell
    for (i = 0; i < taulell.fila; i++) {
        i_aux = 0;
        fgets (aux, MAXAUX, f_taulell);
        for (j = 0; j < taulell.col; j++) {
            taulell.mines[i][j] = aux[i_aux++];
        }
        aux[i_aux] = '\0';
        printf ("F%d: %s\n",i, taulell.mines[i]);
    }
    
    // Inicialitzar que totes les caselles no estan girades
    // 0: no girada; 1: girada
    taulell.turned = (int**)malloc(sizeof(int*) * taulell.fila);
    for (i = 0; i < taulell.fila; i++) {
        taulell.turned[i] = (int*)calloc(taulell.col, sizeof(int));
    }
    
    printf ("GIR:\n");
    for (i = 0; i < taulell.fila; i++) {
        for (j = 0; j < taulell.col; j++)
            printf ("%d", taulell.turned[i][j]);
        printf ("\n");
    }
    
    // Inicialitzar les banderes
    //taulell.flags = (Flag*)malloc(sizeof(Flag) * total_squares);
    taulell.flags = (Flag**)malloc(sizeof(Flag*) * taulell.fila);
    for (i = 0; i < taulell.fila; i++) {
        taulell.flags[i] = (Flag*)malloc(taulell.col * sizeof(Flag));
        for (j = 0; j < taulell.col; j++) {
            taulell.flags[i][j].activada = 0;
        }
    }
    
    return taulell;
}

void initCursor (Cursor *cur) {
    cur->coord1.x = 1;
    cur->coord1.y = HEADER_SIZE + 1;
    cur->coord2.x = cur->coord1.x + SQUARE_SIZE + 1;
    cur->coord2.y = cur->coord1.y + SQUARE_SIZE + 1;
    cur->row = 0;
    cur->column = 0;
}

void moveCursor (Cursor *cursor, int direction, int height, int width) {
    Cursor aux;
    switch (direction) {
        case UP: // UP
            aux.coord1.y = cursor->coord1.y - (SQUARE_SIZE + 1);
            aux.coord2.y = cursor->coord2.y - (SQUARE_SIZE + 1);
            if (aux.coord1.y > HEADER_SIZE) {
                cursor->coord1.y = aux.coord1.y;
                cursor->coord2.y = aux.coord2.y;
                cursor->row -= 1;
            }
            break;
        case DOWN: // DOWN
            aux.coord1.y = cursor->coord1.y + (SQUARE_SIZE + 1);
            aux.coord2.y = cursor->coord2.y + (SQUARE_SIZE + 1);
            if (aux.coord2.y <= height) {
                cursor->coord1.y = aux.coord1.y;
                cursor->coord2.y = aux.coord2.y;
                cursor->row += 1;
            }
            break;
        case LEFT: // LEFT
            aux.coord1.x = cursor->coord1.x - (SQUARE_SIZE + 1);
            aux.coord2.x = cursor->coord2.x - (SQUARE_SIZE + 1);
            if (aux.coord1.x > 0) {
                cursor->coord1.x = aux.coord1.x;
                cursor->coord2.x = aux.coord2.x;
                cursor->column -= 1;
            }
            break;
        case RIGHT: // RIGHT
            aux.coord1.x = cursor->coord1.x + (SQUARE_SIZE + 1);
            aux.coord2.x = cursor->coord2.x + (SQUARE_SIZE + 1);
            if (aux.coord1.x < width) {
                cursor->coord1.x = aux.coord1.x;
                cursor->coord2.x = aux.coord2.x;
                cursor->column += 1;
            }
            break;
    }
    
}

void turnAllSquares (Taulell *taulell) {
    int i, j;
    for (i = 0; i < taulell->fila; i++) {
        for (j = 0; j < taulell->col; j++) {
            taulell->turned[i][j] = 1;
        }
    }
}

int turnSquare (Cursor cursor, Taulell *taulell) {
    int gameover = 0;
    // Indiquem que la casella esta girada
    taulell->turned[cursor.row][cursor.column] = 1;
    if (taulell->mines[cursor.row][cursor.column] == 'M') {
        turnAllSquares (taulell);
        gameover = 1;
    }
    return gameover;
}

void putFlag (Cursor cursor, Taulell *taulell, int *total) {
    if (taulell->flags[cursor.row][cursor.column].activada == 0) {
        taulell->flags[cursor.row][cursor.column].activada = 1;
        (*total)++;
    }
    else {
        taulell->flags[cursor.row][cursor.column].activada = 1;
        (*total)--;
    }
}

int startGame (Taulell *taulell, Player *player) {
    int nSortir = 0;
    //int header_size = 100;
    int width, height;
    Cursor cursor;
    //Flag *flags;
    int gameover = 0;
    int total_flags = 0;
    
    // Calcular les dimensions de la pantalla
    width = 81 * taulell->col + 1;
    height = 1 + HEADER_SIZE + 81 * taulell->fila;
  
    // Inicialitzem el cursor i els flags
    initCursor (&cursor);
    //flags = (Flag*)malloc(sizeof(Flag) * taulell->total_squares); //L'usuari pot posar tantes banderes com caselles en el taulell pero no vol dir que guanya
    
    printf ("c:%d f:%d m:%d\n", taulell->col, taulell->fila, taulell->num_mines);
    printf ("w: %d h: %d\n", width, height);
    
    float t1, t0;
    t0 = (float) clock();
    
    //Inicialitzem Allegro
    LS_allegro_init(width, height, "Buscamines");
    //LS_allegro_init(1280,720, "hello");
    
    //Bucle infinit del joc
    while(!nSortir){
        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }
        t1 = (float) clock();
        
        if (((t1 - t0) / (float)CLOCKS_PER_SEC >= 1) && !gameover) {
            ++(player->temps);
            t0 = (float) clock();
        }
        //Donem l'ordre d'escriure el text de benvinguda
        //al_draw_textf(LS_allegro_get_font(NORMAL),LS_allegro_get_color(WHITE),200,300,0,"%s","Benvingut a Allegro! Prem ESC per sortir...");

        drawHeader (*player, width);
        drawSquares (*taulell);
        drawCursor (cursor);
        drawContent (*taulell);
        
        // Mou el cursor segons el key
        if (LS_allegro_key_pressed(ALLEGRO_KEY_UP)) {
            moveCursor(&cursor, UP, height, width);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_DOWN)) {
            moveCursor(&cursor, DOWN, height, width);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_LEFT)) {
            moveCursor(&cursor, LEFT, height, width);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_RIGHT)) {
            moveCursor(&cursor, RIGHT, height, width);
        }
        if (LS_allegro_key_pressed(ALLEGRO_KEY_SPACE)) {
            gameover = turnSquare(cursor, taulell);
        }
        
        // Posem la bandera en la casella corresponent
        if (LS_allegro_key_pressed(ALLEGRO_KEY_F)) {
            putFlag(cursor, taulell, &total_flags);
        }
        if (gameover) {
            al_draw_textf(LS_allegro_get_font(EXTRA_LARGE),LS_allegro_get_color(BLACK),width/3,height/2,0,"%s","GAMEOVER");
        }
        //Pintem la pantalla de la finestra gràfica
        LS_allegro_clear_and_paint(BLACK);
    }

    //Tanquem la finestra gràfica
    LS_allegro_exit();
    return gameover;
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

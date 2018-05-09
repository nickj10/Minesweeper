/*********************************************************
 *
 * @Proposit: Aquest fitxer conté la implementació de totes
 *      les funcions del mòdule GAME. Aquestes funcions 
 *      tenen a veure amb la lògica del joc.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 26/03/2018
 * @Data ultima modificacio: 08/05/2018
 * 
 ********************************************************/
 
#include "game.h"
#include "draw.h"

int sacarNumero (char *aux) {
    int num = 0;
    int i_aux = 2, i_cad = 0;
    char *cad = (char*)malloc(sizeof(char) * 5);
    while (aux[i_aux] != '\n') {
        cad[i_cad++] = aux[i_aux++];
    }
    cad[i_cad] = '\0';
    num = myAtoi(cad);
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
    if (taulell.mines == NULL) {
        printf ("Error, no s'ha creat la memoria per al contingut del taulell.\n");
    }
    else {
        for (i = 0; i < taulell.fila; i++) {
            taulell.mines[i] = (char*)malloc(sizeof(char) * taulell.col);
            if (taulell.mines[i] == NULL) {
                printf ("Error, no s'ha creat la memoria per al contingut del taulell.\n");
            }
        }
    }
    
    // Llegir cada fila del fitxer per construir el taulell
    for (i = 0; i < taulell.fila; i++) {
        i_aux = 0;
        fgets (aux, MAXAUX, f_taulell);
        for (j = 0; j < taulell.col; j++) {
            taulell.mines[i][j] = aux[i_aux++];
        }
        aux[i_aux] = '\0';
    }
    
    // Inicialitzar que totes les caselles no estan girades
    // 0: no girada; 1: girada
    taulell.turned = (int**)malloc(sizeof(int*) * taulell.fila);
    for (i = 0; i < taulell.fila; i++) {
        taulell.turned[i] = (int*)calloc(taulell.col, sizeof(int));
    }
    
    taulell.lista = FLAG_crea();
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
    
    // Calculem les noves coordenades dependent de la direccio a on volem moure el cursor
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
    Elemento aux;
    for (i = 0; i < taulell->fila; i++) {
        for (j = 0; j < taulell->col; j++) {
            aux.fila = i;
            aux.col = j;
            
            // Si hi ha una bandera en la casella, no la podem girar
            if (!FLAG_existeElemento(&taulell->lista, aux)) {
                taulell->turned[i][j] = 1;
            }
        }
    }
}

int turnSquare (Cursor cursor, Taulell *taulell, int *girada) {
    int gameover = 0;
    Elemento aux;
    aux.col = cursor.column;
    aux.fila = cursor.row;
    // Indiquem que la casella esta girada
    if (!FLAG_existeElemento(&taulell->lista, aux)) {
        // Si ja esta girada, no es realitzara cap accio
        if (!taulell->turned[cursor.row][cursor.column]) {
            taulell->turned[cursor.row][cursor.column] = 1;
            (*girada)++;
        }
        
        // Si s'ha girat una casella amb una mina, es giraran totes les caselles
        if (taulell->mines[cursor.row][cursor.column] == 'M') {
            turnAllSquares (taulell);
            gameover = 1;
        }
    }
    return gameover;
}

void putFlag (Cursor cursor, Taulell *taulell, int *total) {
    Elemento e;
    e.col = cursor.column;
    e.fila = cursor.row;

    // Mirem si ja existeix la bandera en el taulell
    if (FLAG_existeElemento(&(taulell->lista), e)) {
        // Eliminem la bandera si existeix
        FLAG_borrar(&taulell->lista);
        (*total)--;
    }
    else {
        // Afegim la bandera a la llista si no existeix
        FLAG_inserir(&taulell->lista, e);
        (*total)++;
    }
}

int startGame (Taulell *taulell, Player *player) {
    int nSortir = 0;
    int width, height;
    Cursor cursor;
    int gameover = 0;
    int total_flags = 0;
    int girades = 0;
    int win = 0;
    
    // Calcular les dimensions de la pantalla
    width = 81 * taulell->col + 1;
    height = 1 + HEADER_SIZE + 81 * taulell->fila;
  
    // Inicialitzem el cursor i els flags
    initCursor (&cursor);
    
    float t1, t0;
    t0 = (float) clock();
    
    //Inicialitzem Allegro
    LS_allegro_init(width, height, "Buscamines");
    
    //Bucle infinit del joc
    while(!nSortir){
        //Escoltem el teclat esperant la tecla ESC
        if(LS_allegro_key_pressed(ALLEGRO_KEY_ESCAPE)){
            nSortir = 1;
        }
        t1 = (float) clock();
        
        if (((girades + total_flags) == taulell->total_squares) && (total_flags == taulell->num_mines)) {
            gameover = 1;
            win = 1;
        }
        
        if (((t1 - t0) / (float)CLOCKS_PER_SEC >= 1) && !gameover) {
            ++(player->temps);
            t0 = (float) clock();
        }

        // Dibuixa per pantalla les diferents parts del joc
        drawHeader (*player, width);
        drawSquares (*taulell);
        drawCursor (cursor);
        drawContent (*taulell);
        drawFlags(*taulell);

        if (gameover) {
                // Si ja s'ha acabat la partida, es mostra un missatge depenent si s'ha guanyat o no
                drawGameover(*player, *taulell, width, height, win);
        }
        else {
            // No es pot fer res més si ja s'ha acabat la partida
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
                gameover = turnSquare(cursor, taulell, &girades);
            }
            
            // Posem la bandera en la casella corresponent
            if (LS_allegro_key_pressed(ALLEGRO_KEY_B)) {
                putFlag(cursor, taulell, &total_flags);
            }
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

void freeMemoria (Taulell *taulell, Player *player) {
    int i;
    for (i = 0; i < taulell->fila; i++) {
        free(taulell->mines[i]);
        taulell->mines[i] = NULL;
    }
    free (taulell->mines);
    
    for (i = 0; i < taulell->fila; i++) {
        free(taulell->turned[i]);
        taulell->turned[i] = NULL;
    }
    free (taulell->turned);
    free (player->nom_player);
    free (player->nom_taulell);
    FLAG_destruye(&taulell->lista);
}
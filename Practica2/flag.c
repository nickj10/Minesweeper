/*********************************************************
 *
 * @Proposit: Aquest fixter conté la implementació de les
 *      funcions del mòdul FLAG, basat en l'estructura
 *      de dades lineals Llista PDI. Aquestes funcions són 
 *      per crear una llista de banderes, guardant la columna
 *      i la fila on està cadascuna d'elles.
 * @Autor: Nicole Marie Jimenez Burayag
 * @Data creacio: 16/04/2018
 * @Data ultima modificacio: 24/04/2018
 * 
 ********************************************************/

#include "flag.h"

Flags FLAG_crea () {
	Flags f;
	f.pri = (Nodo*)malloc(sizeof(Nodo));
	if (f.pri == NULL) {
		printf ("Error en crear la llista de les banderes.\n");
	}
	else {
		f.pri->e.fila = -2;
        f.pri->e.col = -2;
        f.ant = f.pri;
		f.pri->sig = NULL;
	}
	return f;
}

void FLAG_inserir (Flags *f, Elemento e) {
	Nodo *aux;
	aux = (Nodo*)malloc(sizeof(Nodo));
	if (aux == NULL) {
		printf ("Error en afegir la bandera a la llista.\n");
	}
	else {
		aux->e.fila = e.fila;
		aux->e.col = e.col;
		aux->sig = f->ant->sig;
		f->ant->sig = aux;
		f->ant = aux;
	}
}

void FLAG_borrar (Flags *f) {
    Nodo *aux;
    if (f->ant->sig != NULL) {
        aux = f->ant->sig;
        f->ant->sig = aux->sig;
        free(aux);
    }
}

Elemento FLAG_consultar (Flags f) {
    Elemento e;
    if (f.ant->sig == NULL) {
        printf ("Error al consultar, PDI fora de la llista.\n");
        e.col = -1;
        e.fila = -1;
    }
    else {
        e.col = f.ant->sig->e.col;
        e.fila = f.ant->sig->e.fila;
    }
    return e;
}

int FLAG_vacia (Flags f) {
    return f.pri->sig == NULL;
}

void FLAG_irInicio (Flags *f) {
    f->ant = f->pri;
}

void FLAG_avanzar (Flags *f) {
    if (f->ant->sig == NULL) {
        printf ("Error en avancar en la llista.\n");
    }
    else {
        f->ant = f->ant->sig;
    }
}

int FLAG_final (Flags f) {
    return f.ant->sig == NULL;
}

int FLAG_existeElemento(Flags *f, Elemento e) {
    Elemento aux;
    int trobat = 0;
    // nomes ho executa si la llista no esta buida
    if (!FLAG_vacia(*f)) {
        FLAG_irInicio(f);
        while (!FLAG_final(*f) && !trobat) {
            aux = FLAG_consultar(*f);
            if (aux.col == e.col && aux.fila == e.fila) {
                trobat = 1;
            }
            if (!trobat) {
                FLAG_avanzar(f);
            }
        }
    }
    return trobat;
}

void FLAG_destruye (Flags *f) {
    FLAG_irInicio(f);
    while (!FLAG_vacia(*f)) {
        FLAG_borrar(f);
    }
    free (f->pri);
    f->pri = NULL;
    f->ant = NULL;
}
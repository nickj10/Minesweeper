#include "flag.h"

Flags FLAG_crea () {
	Flags f;
	f.pri = (Nodo*)malloc(sizeof(Nodo));
	if (f.pri == NULL) {
		printf ("Error en crear la llista de les banderes.\n");
	}
	else {
		f.ant = f.pri;
		f.pri->sig = NULL;
	}
	return f;
}

void FLAG_inserir (Flags *f, Elemento e) {
	Nodo *aux;
	aux = (Nodo*)malloc(sizeof(Nodo));
	if (aux == NULL) {
		printf ("Error en crear una bandera.\n");
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

}

Elemento FLAG_consultar (Flags f) {

}

int FLAG_vacia (Flags f) {

}

void FLAG_irInicio (Flags *f) {

}

void FLAG_avanzar (Flags *f) {

}

int FLAG_final (Flags f) {

}

void FLAG_destruye (Flags *f) {

}
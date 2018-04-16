#ifndef _FLAG_H
#define _FLAG_H

#include <stdio.h>

typedef struct {
	int fila;
	int col;
} Elemento;

typedef struct _Nodo {
	Elemento e;
	struct _Nodo *sig;
} Nodo;

typedef struct {
	Nodo *pri;
	Nodo *ant;
} Flags;

Flags FLAG_crea ();
void FLAG_inserir (Flags *f, Elemento e);
void FLAG_borrar (Flags *f);
Elemento FLAG_consultar (Flags f);
int FLAG_vacia (Flags f);
void FLAG_irInicio (Flags *f);
void FLAG_avanzar (Flags *f);
int FLAG_final (Flags f);
void FLAG_destruye (Flags *f);

#endif
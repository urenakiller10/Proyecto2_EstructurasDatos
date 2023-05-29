#pragma once
#include "Splay.h"

class nodoListaSplay {
public:
	SplayTree* data;
	nodoListaSplay* siguiente;

	nodoListaSplay(SplayTree* puntero) {
		data = puntero;
		siguiente = NULL;
	}		
};

class ListaSimpleSplay {
public:
	nodoListaSplay* primero;
public:
	ListaSimpleSplay() {
		primero = NULL;
	}

	void agregarElemento(SplayTree* puntero) {
		nodoListaSplay* nodo = new nodoListaSplay(puntero);
		if (primero == NULL) {
			primero = nodo;
		}
		else {
			nodoListaSplay* tmp = primero;
			while (tmp->siguiente != NULL) {
				tmp = tmp->siguiente;
			}
			tmp->siguiente = nodo;
		}

	}
};
#pragma once
#include "ArbolBinario.h"
#include "Avl.h"

class NodoListaAvl {
public:
    ArbolAvl* dato;
    NodoListaAvl* siguiente;

    NodoListaAvl(ArbolAvl* puntero) {
        dato = puntero;
        siguiente = NULL;
    }
};

class ListaSimpleAvl {
public:
    NodoListaAvl* primerNodo;

public:
    ListaSimpleAvl() {
        primerNodo = NULL;
    }

    void agregarElemento(ArbolAvl* puntero) {
        NodoListaAvl* nodo = new NodoListaAvl(puntero);

        if (primerNodo == NULL) {
            primerNodo = nodo;
        }
        else {
            NodoListaAvl* tmp = primerNodo;
            while (tmp->siguiente != NULL) {
                tmp = tmp->siguiente;
            }
            tmp->siguiente = nodo;
        }
    }
};

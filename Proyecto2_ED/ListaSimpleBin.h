#pragma once
#include "ArbolBinario.h"
#include "Heap.h"
class NodoListaBin {
public:
    ArbolBinario* dato;
    NodoListaBin* siguiente;

    NodoListaBin(ArbolBinario* puntero) {
        dato = puntero;
        siguiente = NULL;
    }
};

class ListaSimpleBin {
public:
    NodoListaBin* primerNodo;

public:
    ListaSimpleBin() {
        primerNodo = NULL;
    }

    void agregarElemento(ArbolBinario* puntero) {
        NodoListaBin* nodo = new NodoListaBin(puntero);

        if (primerNodo == NULL) {
            primerNodo = nodo;
        }
        else {
            NodoListaBin* tmp = primerNodo;
            while (tmp->siguiente != NULL) {
                tmp = tmp->siguiente;
            }
            tmp->siguiente = nodo;
        }
    }
};

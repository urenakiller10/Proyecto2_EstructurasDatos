#pragma once
#include "Heap.h"
class NodoListaHeap {
public:
    Heap* dato;
    NodoListaHeap* siguiente;

    NodoListaHeap(Heap* puntero) {
        dato = puntero;
        siguiente = NULL;
    }
};

class ListaSimpleHeap {
public:
    NodoListaHeap* primerNodo;

public:
    ListaSimpleHeap() {
        primerNodo = NULL;
    }

    void agregarElemento(Heap* puntero) {
        NodoListaHeap* nodo = new NodoListaHeap(puntero);

        if (primerNodo == NULL) {
            primerNodo = nodo;
        }
        else {
            NodoListaHeap* tmp = primerNodo;
            while (tmp->siguiente != NULL) {
                tmp = tmp->siguiente;
            }
            tmp->siguiente = nodo;
        }
    }
};
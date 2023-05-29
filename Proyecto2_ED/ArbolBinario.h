#pragma once
#include "Confi.h"


#include <iostream>

class Nodo {
public:
    float dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(float _dato) {
        dato = _dato;
        izquierdo = derecho = NULL;
    }
};

class ArbolBinario {
public:
    int x;
    int y;
    bool listo = false;
    Nodo* raiz;
private:
    

    Nodo* insertarNodoRecursivo(Nodo* nodo, float dato) {
        if (nodo == NULL) {
            return new Nodo(dato);
        }

        if (dato <= nodo->dato)
            nodo->izquierdo = insertarNodoRecursivo(nodo->izquierdo, dato);
        else
            nodo->derecho = insertarNodoRecursivo(nodo->derecho, dato);

        return nodo;
    }

    void eliminarMayorNodoRecursivo(Nodo* nodo) {
        if (nodo == NULL)
            return;

        Nodo* nodoActual = nodo;
        Nodo* padre = NULL;

        while (nodoActual->derecho != NULL) {
            padre = nodoActual;
            nodoActual = nodoActual->derecho;
        }

        if (padre != NULL)
            padre->derecho = nodoActual->izquierdo;
        else
            raiz = nodoActual->izquierdo;

        delete nodoActual;
    }

    void calcularSumaValoresRecursivo(Nodo* nodo, float& sumaValores) {
        if (nodo == NULL)
            return;

        sumaValores += nodo->dato;
        calcularSumaValoresRecursivo(nodo->izquierdo, sumaValores);
        calcularSumaValoresRecursivo(nodo->derecho, sumaValores);
    }

    void calcularTotalNodosRecursivo(Nodo* nodo, int& totalNodos) {
        if (nodo == nullptr)
            return;

        totalNodos++;
        calcularTotalNodosRecursivo(nodo->izquierdo, totalNodos);
        calcularTotalNodosRecursivo(nodo->derecho, totalNodos);
    }

    void liberarMemoriaRecursivo(Nodo* nodo) {
        if (nodo == nullptr)
            return;

        liberarMemoriaRecursivo(nodo->izquierdo);
        liberarMemoriaRecursivo(nodo->derecho);
        delete nodo;
    }

public:
    ArbolBinario(int _x, int _y) { 
        raiz = NULL;
        x = _x, y = _y;
    }

    void insertar(float dato) {
        raiz = insertarNodoRecursivo(raiz, dato);
    }

    void eliminarMayorNodo() {
        eliminarMayorNodoRecursivo(raiz);
    }

    float calcularSumaValores() {
        float sumaValores = 0;
        calcularSumaValoresRecursivo(raiz, sumaValores);
        return sumaValores;
    }

    int calcularTotalNodos() {
        int totalNodos = 0;
        calcularTotalNodosRecursivo(raiz, totalNodos);
        return totalNodos;
    }

    ~ArbolBinario() {
        liberarMemoriaRecursivo(raiz);
    }
};
#pragma once
#include "Confi.h"


#include <iostream>

class Nodo {
public:
    float dato;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(float dato)
        : dato(dato), izquierdo(nullptr), derecho(nullptr) {}
};

class ArbolBinario {
public:
    float x;
    float y;
    bool listo = false;

private:
    Nodo* raiz;

    Nodo* insertarNodoRecursivo(Nodo* nodo, float dato) {
        if (nodo == nullptr) {
            return new Nodo(dato);
        }

        if (dato <= nodo->dato)
            nodo->izquierdo = insertarNodoRecursivo(nodo->izquierdo, dato);
        else
            nodo->derecho = insertarNodoRecursivo(nodo->derecho, dato);

        return nodo;
    }

    void eliminarMayorNodoRecursivo(Nodo* nodo) {
        if (nodo == nullptr)
            return;

        Nodo* nodoActual = nodo;
        Nodo* padre = nullptr;

        while (nodoActual->derecho != nullptr) {
            padre = nodoActual;
            nodoActual = nodoActual->derecho;
        }

        if (padre != nullptr)
            padre->derecho = nodoActual->izquierdo;
        else
            raiz = nodoActual->izquierdo;

        delete nodoActual;
    }

    void calcularSumaValoresRecursivo(Nodo* nodo, float& sumaValores) {
        if (nodo == nullptr)
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
    ArbolBinario() : raiz(nullptr) {}
    ArbolBinario(int _x, int _y) { 
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
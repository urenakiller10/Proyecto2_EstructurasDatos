#pragma once
#include "Confi.h"


#include <iostream>

class NodoA {
public:
    float datoA;
    NodoA* izquierdo;
    NodoA* derecho;

    NodoA(float _dato) {
        datoA = _dato;
        izquierdo = derecho = NULL;
    }
};

class ArbolAvl {
public:
    int x;
    int y;
    bool listo = false;
    NodoA* raiz;
private:


    NodoA* insertarNodoRecursivo(NodoA* nodo, float datoA) {
        if (nodo == NULL) {
            return new NodoA (datoA);
        }

        if (datoA <= nodo->datoA)
            nodo->izquierdo = insertarNodoRecursivo(nodo->izquierdo, datoA);
        else
            nodo->derecho = insertarNodoRecursivo(nodo->derecho, datoA);

        return nodo;
    }

    void eliminarMayorNodoRecursivo(NodoA* nodo) {
        if (nodo == NULL)
            return;

        NodoA* nodoActual = nodo;
        NodoA* padre = NULL;

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

    void calcularSumaValoresRecursivo(NodoA* nodo, float& sumaValores) {
        if (nodo == NULL)
            return;

        sumaValores += nodo->datoA;
        calcularSumaValoresRecursivo(nodo->izquierdo, sumaValores);
        calcularSumaValoresRecursivo(nodo->derecho, sumaValores);
    }

    void calcularTotalNodosRecursivo(NodoA* nodo, int& totalNodos) {
        if (nodo == nullptr)
            return;

        totalNodos++;
        calcularTotalNodosRecursivo(nodo->izquierdo, totalNodos);
        calcularTotalNodosRecursivo(nodo->derecho, totalNodos);
    }

    void liberarMemoriaRecursivo(NodoA* nodo) {
        if (nodo == nullptr)
            return;

        liberarMemoriaRecursivo(nodo->izquierdo);
        liberarMemoriaRecursivo(nodo->derecho);
        delete nodo;
    }

public:
    ArbolAvl(int _x, int _y) {
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

    ~ArbolAvl() {
        liberarMemoriaRecursivo(raiz);
    }
};
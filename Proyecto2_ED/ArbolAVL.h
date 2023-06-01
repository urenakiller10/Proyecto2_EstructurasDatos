#pragma once

#include <iostream>

class Nodo {
public:
    float dato;
    int altura;
    Nodo* izquierdo;
    Nodo* derecho;

    Nodo(float _dato) {
        dato = _dato;
        altura = 1;
        izquierdo = derecho = nullptr;
    }
};

class AVL {
private:
    Nodo* raiz;

    int obtenerAltura(Nodo* nodo) {
        if (nodo == nullptr)
            return 0;
        return nodo->altura;
    }

    int obtenerBalance(Nodo* nodo) {
        if (nodo == nullptr)
            return 0;
        return obtenerAltura(nodo->izquierdo) - obtenerAltura(nodo->derecho);
    }

    Nodo* rotacionDerecha(Nodo* nodo) {
        Nodo* nodoIzquierdo = nodo->izquierdo;
        Nodo* nodoIzquierdoDerecho = nodoIzquierdo->derecho;

        nodoIzquierdo->derecho = nodo;
        nodo->izquierdo = nodoIzquierdoDerecho;

        nodo->altura = std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho)) + 1;
        nodoIzquierdo->altura = std::max(obtenerAltura(nodoIzquierdo->izquierdo), obtenerAltura(nodoIzquierdo->derecho)) + 1;

        return nodoIzquierdo;
    }

    Nodo* rotacionIzquierda(Nodo* nodo) {
        Nodo* nodoDerecho = nodo->derecho;
        Nodo* nodoDerechoIzquierdo = nodoDerecho->izquierdo;

        nodoDerecho->izquierdo = nodo;
        nodo->derecho = nodoDerechoIzquierdo;

        nodo->altura = std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho)) + 1;
        nodoDerecho->altura = std::max(obtenerAltura(nodoDerecho->izquierdo), obtenerAltura(nodoDerecho->derecho)) + 1;

        return nodoDerecho;
    }

    Nodo* insertarNodoRecursivo(Nodo* nodo, float dato) {
        if (nodo == nullptr) {
            return new Nodo(dato);
        }

        if (dato <= nodo->dato)
            nodo->izquierdo = insertarNodoRecursivo(nodo->izquierdo, dato);
        else
            nodo->derecho = insertarNodoRecursivo(nodo->derecho, dato);

        nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

        int balance = obtenerBalance(nodo);

        if (balance > 1 && dato < nodo->izquierdo->dato)
            return rotacionDerecha(nodo);

        if (balance < -1 && dato > nodo->derecho->dato)
            return rotacionIzquierda(nodo);

        if (balance > 1 && dato > nodo->izquierdo->dato) {
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
            return rotacionDerecha(nodo);
        }

        if (balance < -1 && dato < nodo->derecho->dato) {
            nodo->derecho = rotacionDerecha(nodo->derecho);
            return rotacionIzquierda(nodo);
        }

        return nodo;
    }

    Nodo* eliminarMayorNodoRecursivo(Nodo* nodo) {
        if (nodo == nullptr)
            return nodo;

        if (nodo->derecho == nullptr) {
            Nodo* temp = nodo->izquierdo;
            delete nodo;
            return temp;
        }

        nodo->derecho = eliminarMayorNodoRecursivo(nodo->derecho);

        nodo->altura = 1 + std::max(obtenerAltura(nodo->izquierdo), obtenerAltura(nodo->derecho));

        int balance = obtenerBalance(nodo);

        if (balance > 1 && obtenerBalance(nodo->izquierdo) >= 0)
            return rotacionDerecha(nodo);

        if (balance > 1 && obtenerBalance(nodo->izquierdo) < 0) {
            nodo->izquierdo = rotacionIzquierda(nodo->izquierdo);
            return rotacionDerecha(nodo);
        }

        return nodo;
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
    AVL() {
        raiz = nullptr;
    }

    void insertar(float dato) {
        raiz = insertarNodoRecursivo(raiz, dato);
    }

    void eliminarMayorNodo() {
        raiz = eliminarMayorNodoRecursivo(raiz);
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

    ~AVL() {
        liberarMemoriaRecursivo(raiz);
    }
};
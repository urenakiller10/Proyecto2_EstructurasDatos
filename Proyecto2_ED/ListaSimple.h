#pragma once
template<typename T>
class NodoLista {
public:
    T dato;
    NodoLista<T>* siguiente;

    NodoLista(const T& valor) : dato(valor), siguiente(nullptr) {}
};

template<typename T>
class Lista {
public:
    NodoLista<T>* cabeza;

public:
    Lista() : cabeza(nullptr) {}

    void agregarElemento(const T& valor) {
        NodoLista<T>* nuevoNodo = new NodoLista<T>(valor);

        if (cabeza == nullptr) {
            cabeza = nuevoNodo;
        }
        else {
            Nodo<T>* actual = cabeza;
            while (actual->siguiente != nullptr) {
                actual = actual->siguiente;
            }
            actual->siguiente = nuevoNodo;
        }
    }
};

#pragma once
#include <thread>

using namespace std;
struct nodo {
	nodo* sig;
	thread* hilo;

	nodo(thread* _hilo) {
		this->hilo = _hilo;
		sig = NULL;
	}
};

struct listaSimple {
	nodo* primerNodo;

	listaSimple() {
		primerNodo = NULL;
	}

	void insertar(thread* hilo) {
		nodo* nuevo = new nodo(hilo);
		if (primerNodo == NULL) {
			primerNodo = nuevo;
		}
		else {
			nodo* tmp = primerNodo;
			while (tmp->sig != NULL) {
				tmp = tmp->sig;
			}
			tmp->sig = nuevo;
		}
	}

};
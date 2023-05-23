#pragma once
#include <iostream>

using namespace std;

struct Heap {
    float* arr; // arreglo que representa el heap
    int capacity; // capacidad m�xima del heap
    int size; // cantidad de elementos del heap
    string tipo = "HEAP";
    bool listo = false;

    // Constructor
    Heap(int n) {
        capacity = n;
        size = 0;
        arr = new float[n];
    }

    // Destructor
    ~Heap() {
        delete[] arr;
    }

    // Funci�n para obtener el �ndice del padre
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Funci�n para obtener el �ndice del hijo izquierdo
    int left(int i) {
        return 2 * i + 1;
    }

    // Funci�n para obtener el �ndice del hijo derecho
    int right(int i) {
        return 2 * i + 2;
    }

    // Funci�n para insertar un elemento al heap
    void insert(float value) {
        if (size == capacity) {
            cout << "El heap est� lleno" << endl;
            return;
        }

        int i = size; // �ndice del nuevo elemento
        arr[i] = value; // agregar el nuevo elemento al final del arreglo
        size++; // aumentar la cantidad de elementos

        // mantener la propiedad del heap (max-heap)
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // Funci�n para eliminar el elemento m�ximo del heap
    void eliminar() {
        if (size == 0) {
            cout << "El heap est� vac�o" << endl;
            return;
        }

        // el elemento m�ximo siempre est� en la ra�z (�ndice 0)
        int maximo = arr[0];

        // reemplazar la ra�z con el �ltimo elemento del arreglo
        arr[0] = arr[size - 1];
        size--;

        // mantener la propiedad del heap (max-heap)
        int i = 0;
        while (true) {
            int l = left(i);
            int r = right(i);
            int maximoIndex = i;

            if (l < size && arr[l] > arr[maximoIndex]) {
                maximoIndex = l;
            }

            if (r < size && arr[r] > arr[maximoIndex]) {
                maximoIndex = r;
            }

            if (maximoIndex != i) {
                swap(arr[i], arr[maximoIndex]);
                i = maximoIndex;
            }
            else {
                break;
            }
        }

        //cout << "El elemento maximo (" << maximo << ") ha sido eliminado" << endl;
    }

    // Funci�n para imprimir el heap por niveles
    void imprimir() {
        int nivelActual = 0;
        int elementosNivelActual = 1;

        for (int i = 0; i < size; i++) {
            if (i == elementosNivelActual - 1) {
                cout << endl << "Nivel " << nivelActual << ": ";
                elementosNivelActual *= 2;
                nivelActual++;
            }
            cout << arr[i] << " ";
        }
        cout << endl;
    }
};
#pragma once
#include <iostream>

using namespace std;

struct Heap {
    float* arr; // arreglo que representa el heap
    int capacity; // capacidad máxima del heap
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

    // Función para obtener el índice del padre
    int parent(int i) {
        return (i - 1) / 2;
    }

    // Función para obtener el índice del hijo izquierdo
    int left(int i) {
        return 2 * i + 1;
    }

    // Función para obtener el índice del hijo derecho
    int right(int i) {
        return 2 * i + 2;
    }

    // Función para insertar un elemento al heap
    void insert(float value) {
        if (size == capacity) {
            cout << "El heap está lleno" << endl;
            return;
        }

        int i = size; // índice del nuevo elemento
        arr[i] = value; // agregar el nuevo elemento al final del arreglo
        size++; // aumentar la cantidad de elementos

        // mantener la propiedad del heap (max-heap)
        while (i != 0 && arr[parent(i)] < arr[i]) {
            swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // Función para eliminar el elemento máximo del heap
    void eliminar() {
        if (size == 0) {
            cout << "El heap está vacío" << endl;
            return;
        }

        // el elemento máximo siempre está en la raíz (índice 0)
        int maximo = arr[0];

        // reemplazar la raíz con el último elemento del arreglo
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

    // Función para imprimir el heap por niveles
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
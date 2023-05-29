#pragma once
#include <iostream>


struct Heap {
    float* arr; // arreglo que representa el heap
    int capacity; // capacidad máxima del heap
    int size; // cantidad de elementos del heap
    bool listo = false;
    int x; int y;

    // Constructor
    Heap(int n, int _x, int _y) {
        capacity = n;
        size = 0;
        arr = new float[n];
        x = _x;
        y = _y;
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
            return;
        }

        int i = size; // índice del nuevo elemento
        arr[i] = value; // agregar el nuevo elemento al final del arreglo
        size++; // aumentar la cantidad de elementos

        // mantener la propiedad del heap (max-heap)
        while (i != 0 && arr[parent(i)] < arr[i]) {
            std::swap(arr[parent(i)], arr[i]);
            i = parent(i);
        }
    }

    // Función para eliminar el elemento máximo del heap
    void eliminar() {
        if (size == 0) {
            return;
        }

        // el elemento máximo siempre está en la raíz (índice 0)
        float maximo = arr[0];

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
                std::swap(arr[i], arr[maximoIndex]);
                i = maximoIndex;
            }
            else {
                break;
            }
        }
    }

    // Método para obtener la sumatoria del valor de los nodos
    float sumatoriaValorNodos() {
        float sumatoria = 0.0;
        for (int i = 0; i < size; i++) {
            sumatoria += arr[i];
        }
        return sumatoria;
    }

    int sumatoriaTotalNodos() {
        return size;
    }

    void eliminarTodos() {
        delete[] arr;
        capacity = 0;
        size = 0;
        arr = new float[capacity];
    }
};
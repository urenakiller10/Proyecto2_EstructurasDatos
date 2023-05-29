#pragma once

class Confi{
private:
    int precioBinario = 250;
    int creceBinario = 10;
    int cosechaBinario = 1;
    float precioFrutosBinario = 10.0f;

    int precioSplay = 250;
    int creceSplay = 60;
    int cosechaSplay = 15;
    float precioFrutosSplay = 10.0f;

    int precioHeap = 250;
    int creceHeap = 60;
    int cosechaHeap = 15;
    float precioFrutosHeap = 10.0f;

    int precioAvl = 250;
    int creceAvl = 60;
    int cosechaAvl = 15;
    float precioFrutosAvl = 10.0f;


    int ovejaAparicion = 90;
    int ovejaComeFruto = 60;

    int cuervoAparicion = 90;
    int cuervoComeFruto = 60;

    int plagaAparicion = 90;
    int plagaComeArbol = 60;

    float valorMinimo = 0.1f;


public:
    Confi() : precioBinario(250),creceBinario(60),cosechaBinario(15), precioFrutosBinario(10.0f)
        ,precioSplay(250),creceSplay(60),cosechaSplay(15), precioFrutosSplay(10.0f)
        , precioHeap (250), creceHeap(60),cosechaHeap(15), precioFrutosHeap(10.0f)
        ,precioAvl(250),creceAvl(60),cosechaAvl(15),precioFrutosAvl(10.0f)
        ,ovejaAparicion(90), ovejaComeFruto(60),cuervoAparicion(90),cuervoComeFruto(60),plagaAparicion(90),plagaComeArbol(60) {}
                
    float getMinValue() {
        return valorMinimo;
    }


    //Binario

   // Precio de un arbol binario en tienda
    void setPrecioBinario(int cantidad) {
        precioBinario = cantidad;
    }

    // Tiempo de crecimiento de un arbol binario antes de dar frutos
    void setCreceBinario(int cantidad) {
        creceBinario = cantidad;
    }

    // Tiempo de crecimiento de un fruto en un arbol binario
    void setCosechaBinario(int cantidad) {
        cosechaBinario = cantidad;
    }

    // Precio maximo de un fruto de un arbol binario
    void setPrecioFrutosBinario(float cantidad) {
        precioFrutosBinario = cantidad;
    }

    // Precio de un árbol Splay en tienda
    void setPrecioSplay(int cantidad) {
        precioSplay = cantidad;
    }

    // Tiempo de crecimiento de un árbol Splay antes de dar frutos
    void setCreceSplay(int cantidad) {
        creceSplay = cantidad;
    }

    void setCosechaSplay(int cantidad) {
        cosechaSplay = cantidad;
    }

    void setPrecioFrutosSplay(float cantidad) {
        precioFrutosSplay = cantidad;
    }

    // Precio de un árbol Heap en tienda
    void setPrecioHeap(int cantidad) {
        precioHeap = cantidad;
    }

    void setCreceHeap(int cantidad) {
        creceHeap = cantidad;
    }

    void setCosechaHeap(int cantidad) {
        cosechaHeap = cantidad;
    }

    void setPrecioFrutosHeap(float cantidad) {
        precioFrutosHeap = cantidad;
    }

    // Precio de un árbol AVL en tienda
    void setPrecioAvl(int cantidad) {
        precioAvl = cantidad;
    }

    void setCreceAvl(int cantidad) {
        creceAvl = cantidad;
    }

    void setCosechaAvl(int cantidad) {
        cosechaAvl = cantidad;
    }

    void setPrecioFrutosAvl(float cantidad) {
        precioFrutosAvl = cantidad;
    }
    //Oveja

    void setOvejaAparicion(int cantidad) {
        ovejaAparicion = cantidad;
    }

    void setOvejaComeFrutos(int cantidad) {
        ovejaComeFruto = cantidad;
    }

    //Cuervo

    void setCuervoAparicion(int cantidad) {
        cuervoAparicion = cantidad;
    }

    void setCuervoComeFrutos(int cantidad) {
        cuervoComeFruto = cantidad;
    }

    //Plagas

    void setPlagasAparicion(int cantidad) {
        cuervoAparicion = cantidad;
    }

    void setPlagasComeArbol(int cantidad) {
        plagaComeArbol = cantidad;
    }

    //-----------------------------------------------------

// Precio de un arbol binario en tienda
    int getPrecioBinario() {
        return precioBinario;
    }

    // Tiempo de crecimiento de un arbol binario antes de dar frutos
    int getCreceBinario() {
        return creceBinario;
    }

    // Tiempo de crecimiento de un fruto en un arbol binario
    int getCosechaBinario() {
        return cosechaBinario;
    }

    // Precio maximo de un fruto de un arbol binario
    float getPrecioFrutosBinario() {
        return precioFrutosBinario;
    }

    // Precio de un árbol Splay en tienda
    int getPrecioSplay() {
        return precioSplay;
    }

    // Tiempo de crecimiento de un árbol Splay antes de dar frutos
    int getCreceSplay() {
        return creceSplay;
    }

    // Tiempo de crecimiento de un fruto en un árbol Splay
    int getCosechaSplay() {
        return cosechaSplay;
    }

    // Precio máximo de un fruto de un árbol Splay
    float getPrecioFrutosSplay() {
        return precioFrutosSplay;
    }

    // Precio de un árbol Heap en tienda
    int getPrecioHeap() {
        return precioHeap;
    }

    // Tiempo de crecimiento de un árbol Heap antes de dar frutos
    int getCreceHeap() {
        return creceHeap;
    }

    // Tiempo de crecimiento de un fruto en un árbol Heap
    int getCosechaHeap() {
        return cosechaHeap;
    }

    // Precio máximo de un fruto de un árbol Heap
    float getPrecioFrutosHeap() {
        return precioFrutosHeap;
    }

    // Precio de un árbol AVL en tienda
    int getPrecioAvl() {
        return precioAvl;
    }

    // Tiempo de crecimiento de un árbol AVL antes de dar frutos
    int getCreceAvl() {
        return creceAvl;
    }

    // Tiempo de crecimiento de un fruto en un árbol AVL
    int getCosechaAvl() {
        return cosechaAvl;
    }

    // Precio máximo de un fruto de un árbol AVL
    float getPrecioFrutosAvl() {
        return precioFrutosAvl;
    }

    int getOvejaAparicion() const {
        return ovejaAparicion;
    }


    int getOvejaComeFruto() const {
        return ovejaComeFruto;
    }


    int getCuervoAparicion() const {
        return cuervoAparicion;
    }


    int getCuervoComeFruto() const {
        return cuervoComeFruto;
    }


    int getPlagaAparicion() const {
        return plagaAparicion;
    }


    int getPlagaComeArbol() const {
        return plagaComeArbol;
    }
};



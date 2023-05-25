#pragma once

class Confi{
private:
    const float valorMinimo = 0.1f;
    //Los tiempos son en segundos
    int precioBinario = 250;
    int creceBinario = 60;
    int cosechaBinario = 15;
    float precioFrutosBinario = 500.0f;

    int precioSplay = 250;
    int creceSplay = 90;
    int cosechaSplay = 8;
    float precioFrutosSplay = 500.0f;

    int precioHeap = 250;
    int creceHeap = 120;
    int cosechaHeap = 4;
    float precioFrutosHeap = 500.0f;

    int precioAvl = 250;
    int creceAvl = 15;
    int cosechaAvl = 30;
    float precioFrutosAvl = 500.0f;

    int ovejaAparicion = 180;
    int ovejaComeFruto = 90;

    int cuervoAparicion = 120;
    int cuervoComeFruto = 90;

    int plagaAparicion = 69;
    int plagaComeArbol = 100;


public:
    Confi() : precioBinario(250),creceBinario(60),cosechaBinario(15), precioFrutosBinario(500.0f)
        ,precioSplay(250),creceSplay(90),cosechaSplay(8), precioFrutosSplay(500.0f)
        ,precioHeap (250), creceHeap(120),cosechaHeap(4), precioFrutosHeap(500.0f)
        ,precioAvl(250),creceAvl(15),cosechaAvl(30),precioFrutosAvl(500.0f)
        ,ovejaAparicion(180), ovejaComeFruto(90),cuervoAparicion(120),cuervoComeFruto(90),plagaAparicion(69),plagaComeArbol(100) {}
                                                                                                                                                                                                            
    //Binario

    void setPrecioBinario(int cantidad) {
        precioBinario = cantidad;
    }

    void setCreceBinario(int cantidad) {
        creceBinario = cantidad;
    }

    void setCosechaBinario(int cantidad) {
        cosechaBinario = cantidad;
    }

    void setPrecioFrutosBinario(float cantidad) {
        precioFrutosBinario = cantidad;
    }

    //Splay

    void setPrecioSplay(int cantidad) {
        precioSplay = cantidad;
    }

    void setCreceSplay(int cantidad) {
        creceSplay = cantidad;
    }
    void setCosechaSplay(int cantidad) {
        cosechaSplay = cantidad;
    }
    void setPrecioFrutosSplay(float cantidad) {
        precioFrutosSplay = cantidad;

    //Heap

    }
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

    //Avl
    }
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

    int getPrecioBinario() const {
        return precioBinario;
    }

    int getCreceBinario() const {
        return creceBinario;
    }

    int getCosechaBinario() const {
        return cosechaBinario;
    }

    float getPrecioFrutosBinario() const {
        return precioFrutosBinario;
    }

    int getPrecioSplay() const {
        return precioSplay;
    }

    int getCreceSplay() const {
        return creceSplay;
    }

    int getCosechaSplay() const {
        return cosechaSplay;
    }

    float getPrecioFrutosSplay() const {
        return precioFrutosSplay;
    }


    int getPrecioHeap() const {
        return precioHeap;
    }


    int getCreceHeap() const {
        return creceHeap;
    }


    int getCosechaHeap() const {
        return cosechaHeap;
    }


    float getPrecioFrutosHeap() const {
        return precioFrutosHeap;
    }

    int getPrecioAvl() const {
        return precioAvl;
    }


    int getCreceAvl() const {
        return creceAvl;
    }


    int getCosechaAvl() const {
        return cosechaAvl;
    }


    float getPrecioFrutosAvl() const {
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



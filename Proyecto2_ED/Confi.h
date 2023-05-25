#pragma once

class Confi{
private:
    int precioBinario = 250;
    int creceBinario = 30000;
    int cosechaBinario = 30000;
    int precioFrutosBinario = 500;

    int precioSplay = 250;
    int creceSplay = 30000;
    int cosechaSplay = 30000;
    int precioFrutosSplay = 500;

    int precioHeap = 250;
    int creceHeap = 30000;
    int cosechaHeap = 30000;
    int precioFrutosHeap = 500;

    int precioAvl = 250;
    int creceAvl = 30000;
    int cosechaAvl = 30000;
    int precioFrutosAvl = 500;

    int ovejaAparicion = 30000;
    int ovejaComeFruto = 30000;

    int cuervoAparicion = 30000;
    int cuervoComeFruto = 30000;

    int plagaAparicion = 30000;
    int plagaComeArbol = 30000;


public:
    Confi() : precioBinario(250),creceBinario(30000),cosechaBinario(30000), precioFrutosBinario(500),precioSplay(250),creceSplay(30000),cosechaSplay(30000), precioFrutosSplay(500), precioHeap (250), creceHeap(30000),cosechaHeap(30000), precioFrutosHeap(500),precioAvl(250),creceAvl(30000),cosechaAvl(30000),precioFrutosAvl(500),ovejaAparicion(3000), ovejaComeFruto(3000),cuervoAparicion(3000),cuervoComeFruto(3000),plagaAparicion(3000),plagaComeArbol(3000) {}
                                                                                                                                                                                                            
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

    void setPrecioFrutosBinario(int cantidad) {
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
    void setPrecioFrutosSplay(int cantidad) {
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
    void setPrecioFrutosHeap(int cantidad) {
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

    void setPrecioFrutosAvl(int cantidad) {
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

    int getPrecioFrutosBinario() const {
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

    int getPrecioFrutosSplay() const {
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


    int getPrecioFrutosHeap() const {
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


    int getPrecioFrutosAvl() const {
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



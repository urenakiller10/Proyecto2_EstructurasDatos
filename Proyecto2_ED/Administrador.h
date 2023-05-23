#pragma once

ref class Administrador {
 public:
    static int canBinario;
    static int canAVL;
    static int canSPLAY;
    static int canHEAP;
    static int canEspanta;


public:
    static void GuardarCantidades(int binario, int avl, int splay, int heap, int espanta) {
        canBinario = binario;
        canAVL = avl;
        canSPLAY = splay;
        canHEAP = heap;
        canEspanta = espanta;
    }

    static int ObtenerCantidadBinario() {
        return canBinario;
    }

    static int ObtenerCantidadAVL() {
        return canAVL;
    }

    static int ObtenerCantidadSPLAY() {
        return canSPLAY;
    }

    static int ObtenerCantidadHEAP() {
        return canHEAP;
    }

    static int ObtenerCantidadEspanta() {
        return canEspanta;
    }
};


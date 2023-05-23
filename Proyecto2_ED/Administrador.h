#pragma once
class Administrador {
private:
    int cantBinario = 0;
    int cantHEAP = 0;
    int cantAVL = 0;
    int cantSPLAY = 0;
    int cantEspanta = 0;
    int espantaPlantados = 0;

public:
    Administrador() : cantBinario(0), cantHEAP(0), cantAVL(0), cantSPLAY(0), cantEspanta(0), espantaPlantados(0) {}

    void setCantidadBinario(int cantidad) {
        cantBinario += cantidad;
    }

    void setCantidadHEAP(int cantidad) {
        cantHEAP += cantidad;
    }

    void setCantidadAVL(int cantidad) {
        cantAVL += cantidad;
    }

    void setCantidadSPLAY(int cantidad) {
        cantSPLAY += cantidad;
    }

    void setCantidadEspanta(int cantidad) {
        cantEspanta += cantidad;
    }

    void setCantidadEspantaPlantados(int cantidad) {
        espantaPlantados += cantidad;
    }

    int getCantidadBinario() const {
        return cantBinario;
    }

    int getCantidadHEAP() const {
        return cantHEAP;
    }

    int getCantidadAVL() const {
        return cantAVL;
    }

    int getCantidadSPLAY() const {
        return cantSPLAY;
    }

    int getCantidadEspanta() const {
        return cantEspanta;
    }

    int getCantidadEspantaPlantados() const {
        return espantaPlantados;
    }
};



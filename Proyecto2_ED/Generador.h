#pragma once


#ifndef Generador_H
#define Generador_H
#include <stdlib.h>
#include <time.h>
#include<iostream>

float generarNumeroAleatorio(float limiteInferior, float limiteSuperior) {

	//srand(time(NULL));
	static float r = limiteInferior + static_cast<float>(rand()) * static_cast<float>(limiteSuperior - limiteInferior) / RAND_MAX;
	return r;
}
#endif
/*

    bool running = true; //Variable que controla si los hilos corren o no

    listaSimple* listaBinarios = new listaSimple(); //Lista de los hilos de cada arbol binario
    listaSimple* listaHeaps = new listaSimple(); //Lista de los hilos de cada heap

    //crear 5 arboles de cada tipo
    for (int i = 0; i < 5; i++) {
        thread* tB = new thread(hiloBinario, 30, 2+i*2, ref(running), 2.0f, 5.0f);
        listaBinarios->insertar(tB);
        this_thread::sleep_for(std::chrono::seconds(1));
        thread* tH = new thread(hiloHeap, 10, 5 + i * 2, ref(running), 1.0f, 3.0f);
        listaHeaps->insertar(tH);
        this_thread::sleep_for(std::chrono::seconds(5));
    }
    */
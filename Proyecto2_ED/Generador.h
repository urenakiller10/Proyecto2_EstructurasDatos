#pragma once


#include <stdlib.h>
#include <time.h>
#include<iostream>

float generarNumeroAleatorio(float limiteInferior, float limiteSuperior) {

	//srand(time(NULL));
	static float r = limiteInferior + static_cast<float>(rand()) * static_cast<float>(limiteSuperior - limiteInferior) / RAND_MAX;
	return r;
}

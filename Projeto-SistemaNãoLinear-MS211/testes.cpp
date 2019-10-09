#include <iostream>
#include <stdlib.h>

#include "sistemaLinear.h"


void testaSistemaLinear()
{
	SistemaLinear sistema(3);

	sistema.setParadaIteracao(50);

	double** coeficiente = (double**)malloc(3 * sizeof(double*));

	for (int i = 0; i < 3; i++)
	{
		coeficiente[i] = (double*)malloc(3 * sizeof(double));
	}

	coeficiente[0][0] = 10;
	coeficiente[0][1] = 2;
	coeficiente[0][2] = 1;

	coeficiente[1][0] = 1;
	coeficiente[1][1] = 5;
	coeficiente[1][2] = 1;

	coeficiente[2][0] = 2;
	coeficiente[2][1] = 3;
	coeficiente[2][2] = 10;

	double* independente = (double*)malloc(3 * sizeof(double));

	independente[0] = 7;
	independente[1] = -8;
	independente[2] = 6;

	sistema.inserirMatriz(coeficiente);

	sistema.inserirTermoFonte(independente);

	double* solucao = sistema.calcular();

	std::cout << "x = " << solucao[0] << "\ny = " << solucao[1];
	std::cout << "\nz = " << solucao[2];
}
#include <iostream>
#include <stdlib.h>

#include "pch.h"
#include "sistemaLinear.h"

/*
void testaJacobiana()
{
	Jacobiana jacobiana(2,2);

	jacobiana.inserirFuncao(0, &f1Teste);
	jacobiana.inserirFuncao(1, &f2Teste);

	jacobiana.setH(0.2);

	double xTeste[2];

	xTeste[0] = 5;
	xTeste[1] = 8;

	double **resultadoTeste = jacobiana.avaliar(xTeste);

	std::cout << resultadoTeste[0][0] << " " << resultadoTeste[0][1] << "\n";
	std::cout << resultadoTeste[1][0] << " " << resultadoTeste[1][1] << "\n";
}

double f1Teste(double *x)
{
	return pow(x[0], 2) + (3 * pow(x[1], 2));
}

double f2Teste(double *x)
{
	return (5*pow(x[0], 3)) + (2 * x[1]);
}


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
}*/
//Elton Cardoso do Nascimento - 233840
//Unicamp - Eng Computação - 019
//IMECC - MS211 - Maicon - 2sem2019

// Projeto-SistemaNãoLinear-MS211.cpp : Este arquivo contém a função 'main'. A execução do programa começa e termina ali.

#include "pch.h"
#include <iostream>
#include "sistemaNaoLinear.h"
#include <math.h>

double f1(double *x)
{
	return 10 * (x[1] - pow(x[0],2));
}

double f2(double *x)
{
	return 1 - x[0];
}


double f1Teste(double* x)
{
	return x[0] + x[1] - 3;
}

double f2Teste(double* x)
{
	return pow(x[0],2) + pow(x[1],2) - 9;
}

int main()
{	
	SistemaNaoLinear sistema(2, 2);

	sistema.inserirFuncao(1, &f1);
	sistema.inserirFuncao(0, &f2);

	sistema.setParadaIteracao(50);

	sistema.setPrint(true);

	sistema.setJacobiana(0.00001);
	sistema.setLinear(50, 0);

	double *resultado;

	double x0[2];

	x0[1] = -1.2;
	x0[0] = 1;

	resultado = sistema.calcular(x0);

	std::cout << resultado[0] << " " << resultado[1];
}
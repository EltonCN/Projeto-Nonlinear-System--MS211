#include "pch.h"
#include "jacobiana.h"



Jacobiana::Jacobiana(int nFuncao, int nIncognita)
{
	this->nFuncao = nFuncao;
	this->nIncognita = nIncognita;

	funcao = (Funcao*) malloc(nFuncao * sizeof(Funcao));
}


Jacobiana::~Jacobiana()
{
}

void Jacobiana::inserirFuncao(int indice, Funcao funcao)
{
	this->funcao[indice] = funcao;
}

double Jacobiana::calculaDerivada(int indiceFuncao, int indiceX, double* x)
{
	double* xh = (double*) malloc(sizeof(double)*nIncognita);

	for (int i = 0; i < nIncognita; i++)
	{
		xh[i] = x[i];

		if (i == indiceX)
		{
			xh[i] += h;
		}
	}

	return (funcao[indiceFuncao](xh) - funcao[indiceFuncao](x)) / h;
}

void Jacobiana::setH(double h)
{
	this->h = h;
}

double** Jacobiana::avaliar(double *x)
{
	double** resultado = (double**)malloc(nFuncao * sizeof(double*));

	for (int i = 0; i < nFuncao; i++)
	{
		resultado[i] = (double*)malloc(nIncognita * sizeof(double*));

		for (int j = 0; j < nIncognita; j++)
		{
			resultado[i][j] = calculaDerivada(i, j, x);
		}
	}

	return resultado;
}
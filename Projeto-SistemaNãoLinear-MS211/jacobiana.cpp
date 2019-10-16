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
			xh[i] += this->h;
		}
	}

	double f1 = funcao[indiceFuncao](xh);
	double f2 = funcao[indiceFuncao](x);
	double resultado = ( f1 - f2) / this->h;

	return resultado;
}

void Jacobiana::setH(double h)
{
	this->h = h;
}

double** Jacobiana::avaliar(double *x)
{
	double** resultado = (double**)malloc(nIncognita * sizeof(double*));

	for (int i = 0; i < nIncognita; i++)
	{
		resultado[i] = (double*) malloc(nFuncao * sizeof(double));
	}

	for (int i = 0; i < nIncognita; i++)
	{
		for (int j = 0; j < nFuncao; j++)
		{
			resultado[j][i] = calculaDerivada(j, i, x);
		}
	}

	return resultado;
}
#include "pch.h"
#include "sistemaLinear.h"

#include <stdlib.h>

SistemaLinear::SistemaLinear(int nEquacao)
{
	this->nEquacao = nEquacao;

	this->nIteracao = 0;

	this->erroMaximo = 0;
	this->nMaxIteracao = 10;

	this->xAnt = (double*) malloc(sizeof(double));
}


SistemaLinear::~SistemaLinear()
{
}

void SistemaLinear::setParadaIteracao(int nMaxInteracao)
{
	this->nMaxIteracao = nMaxInteracao;
}

void SistemaLinear::setParadaErro(double erroMaximo)
{
	this->erroMaximo = erroMaximo;
}

void SistemaLinear::inserirMatriz(double** matrizCoeficientes)
{
	this->m = matrizCoeficientes;
}

void SistemaLinear::inserirTermoFonte(double* fonte)
{
	this->b = fonte;
}

double* SistemaLinear::calcular()
{
	this->xAtual = (double*)malloc(nEquacao * sizeof(double));

	for (int i = 0; i < nEquacao; i++)
	{
		xAtual[i] = 0;
	}

	for (int i = 0; i < nMaxIteracao; i++)
	{
		iterar();

		if (erroMaximo > 0)
		{
			if (this->erro() < erroMaximo)
			{
				break;
			}
		}
	}

	return xAtual;
}

double* SistemaLinear::calcular(double* inicial)
{
	this->xAtual = (double*)malloc(nEquacao * sizeof(double));

	for (int i = 0; i < nEquacao; i++)
	{
		xAtual[i] = inicial[i];
	}

	for (int i = 0; i < nMaxIteracao; i++)
	{
		iterar();

		if (erroMaximo > 0)
		{
			if (this->erro() < erroMaximo)
			{
				break;
			}
		}
	}

	return xAtual;
}

void SistemaLinear::iterar()
{
	free(xAnt);

	xAnt = xAtual;

	this->xAtual = (double*) malloc(nEquacao * sizeof(double));

	for (int i = 0; i < nEquacao; i++)
	{
		xAtual[i] = b[i];

		for (int j = 0; j < nEquacao; j++)
		{
			if (j != i)
			{
				xAtual[i] -= m[i][j] * xAnt[j];
			}
		}
		xAtual[i] /= m[i][i];
	}

	this->nIteracao += 1;
}

double SistemaLinear::erro()
{
	double erro = 0;

	for (int i = 0; i < this->nEquacao; i++)
	{


	}

	return erro;
}
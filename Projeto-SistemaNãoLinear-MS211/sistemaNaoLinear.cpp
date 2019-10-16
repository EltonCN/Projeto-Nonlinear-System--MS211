#include "pch.h"
#include "sistemaNaoLinear.h"

///<summary> Calcula o valor absoluto de um número </summary>
///<param name="x"> Número </param>
///<returns> Valor absoluto do número </returns>
double abs(double x)
{
	if (x < 0.0)
	{
		return -x;
	}
	else
	{
		return x;
	}
}

//////////


SistemaNaoLinear::SistemaNaoLinear(int nFuncao, int nIncognita):jacobiana(nFuncao,nIncognita), sistemaLinear(nFuncao)
{
	this->nFuncao = nFuncao;
	this->nIncognita = nIncognita;

	this->funcao = (Funcao*) malloc(nFuncao * sizeof(Funcao));

	this->funcaoPontoN = (double*) malloc(nFuncao * sizeof(double));
	this->xAnterior = (double*) malloc(nIncognita * sizeof(double));
	this->xAtual = (double*)malloc(nIncognita * sizeof(double));

	this->erroMaximo = 0;
	this->nIteracao = 0;
}


SistemaNaoLinear::~SistemaNaoLinear()
{
}

void SistemaNaoLinear::inserirFuncao(int indice, Funcao funcao)
{
	this->funcao[indice] = funcao;

	jacobiana.inserirFuncao(indice, funcao);
}

void SistemaNaoLinear::setParadaIteracao(int nMaxInteracao)
{
	this->nMaxIteracao = nMaxInteracao;
}

void SistemaNaoLinear::setParadaErro(double erroMaximo)
{
	this->erroMaximo = erroMaximo;
}

double* SistemaNaoLinear::calcular(double* inicial)
{
	for (int i = 0; i < nIncognita; i++)
	{
		this->xAtual[i] = inicial[i];

		this->xAnterior[i] = inicial[i];
	}

	

	for (int i = 0; i < this->nMaxIteracao; i++)
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

	return this->xAtual;
}

void SistemaNaoLinear::setJacobiana(double h)
{
	this->jacobiana.setH(h);
}

void SistemaNaoLinear::setLinear(int nIteracaoMax, double erroMax)
{
	this->sistemaLinear.setParadaErro(erroMax);
	this->sistemaLinear.setParadaIteracao(nIteracaoMax);
}

void SistemaNaoLinear::iterar()
{
	//this->atualizaDelta();
	this->atualizaJacobiana();
	this->avaliaFuncoes();

	this->sistemaLinear.inserirMatriz(matrizJacobiana);
	this->sistemaLinear.inserirTermoFonte(this->funcaoPontoN);
	this->delta = this->sistemaLinear.calcular();

	atualizaX();

	this->nIteracao += 1;
}

double SistemaNaoLinear::erro()
{
	double erro = 0;

	for (int i = 0; i < nFuncao; i++)
	{
		if (abs(funcaoPontoN[i]) > erro)
		{
			erro = abs(funcaoPontoN[i]);
		}
	}

	return erro;
}

void  SistemaNaoLinear::avaliaFuncoes()
{

	for (int i = 0; i < nFuncao; i++)
	{
		funcaoPontoN[i] = - this->funcao[i](xAtual);
	}
}

void SistemaNaoLinear::atualizaX()
{
	for (int i = 0; i < nIncognita; i++)
	{
		xAnterior[i] = xAtual[i];
		xAtual[i] = delta[i] + xAnterior[i];
	}
}

void SistemaNaoLinear::atualizaJacobiana()
{
	this->matrizJacobiana = this->jacobiana.avaliar(xAtual);
}
#pragma once

#include "sistemaLinear.h"
#include "jacobiana.h"


#ifndef tipoFuncao
#define tipoFuncao
typedef double(*Funcao)(double*);
#endif 


class SistemaNaoLinear
{
	private:
		double* xAtual;
		double* xAnterior;

		Funcao* funcoes;

		int nMaxInteracao;
		double erroMaximo;

		SistemaLinear sistemaLinear;
		Jacobiana jacobiana;


		void iterar();
	public:
		SistemaNaoLinear();
		~SistemaNaoLinear();

		void inserirFuncao(int indice, Funcao funcao);
		void setIteracaoMaxima(int nMaxInteracao);
		void setParada(double erroMaximo);

		void calcular();
};


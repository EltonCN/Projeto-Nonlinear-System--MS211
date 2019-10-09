#pragma once

#include "sistemaLinear.h"
#include "jacobiana.h"


#ifndef tipoFuncao
#define tipoFuncao
typedef double(*Funcao)(double*);
#endif 

///<summary> Resolve um sistema n�o linear </summary>
class SistemaNaoLinear
{
	private:
		double* xAtual; ///<value> Solu��o atual do sistema </value>
		double* xAnterior; ///<value> Solu��o anterior do sistema </value>
		double* funcaoPontoN; ///<value> Valor da fun��o no ponto atual </value>
		double* delta; ///<value> Diferen�a entre xAtual e xAnterior </value>

		int nFuncao, ///<value> N�mero de fun��es do sistema </value>
			nIncognita; ///<value> N�mero de inc�gnitas do sistema </value>

		///<value> Vetor de fun��es </value>
		///<remarks> Devem retorna "0" no vetor solu��o </remarks>
		Funcao* funcao;

		int nIteracao; ///<value> �ndice da itera��o atual </value>
		int nMaxIteracao; ///<value> N�mero m�ximo de itera��es </value>
		double erroMaximo; ///<value> Erro m�ximo nas fun��es </value>
		double** matrizJacobiana;

		SistemaLinear sistemaLinear; ///<value> Resolve o sistema linear </value>
		Jacobiana jacobiana; ///<value> Calcula a matriz Jacobiana </value>

		///<summary> Realiza uma itera��o </summary>
		void iterar();

		///<summary> Calcula o erro m�ximo nas fun��es </summary>
		///<returns> O erro m�ximo </return>
		double erro();

		///<summary> Avalia as fun��es no ponto atual </summary>
		void avaliaFuncoes();

		///<summary> Atualiza o vetor xAtual </summary>
		void atualizaX();

		///<summary> Atualiza a matriz Jacobiana </summary>
		void atualizaJacobiana();
	public:
		///<summary> Construtor </summary>
		///<param name="nFuncao"> N�mero de fun��es do sistema </param>
		///<param name="nIncognita"> N�mero de inc�gnitas do sistema </param>
		SistemaNaoLinear(int nFuncao, int nIncognita);
		~SistemaNaoLinear();

		///<summary> Define uma das fun��es do sistema </summary>
		///<remarks> A fun��o deve retornar "0" no vetor solu��o </remarks>
		///<param name="indice"> �ndice da fun��o </param>
		///<p�ram name="funcao"> Ponteiro para a fun��o </param>
		void inserirFuncao(int indice, Funcao funcao);

		///<summary> Define o n�mero m�ximo de itera��es </summary>
		///<param name="nMaxIteracao"> O n�mero m�ximo de itera��es </param>
		void setParadaIteracao(int nMaxInteracao);

		///<summary> Define o erro m�ximo para parada </summary>
		///<remarks> Tamb�m determina que o algor�tmo utilizar� esse crit�rio </remarks>
		///<param name="erroMaximo"> O erro m�ximo a ser definido </param>
		///<remaks> "0" para n�o utilizar esse crit�rio </remarks>
		void setParadaErro(double erroMaximo);

		///<summary> Calcula a solu��o do sistema </summary>
		///<param name="inicial"> O valor inicial para o sistema </param>
		///<returns> O vetor solu��o </returns>
		double* calcular(double* inicial);

		///<summary> Define a diferen�a h para c�lculo das derivadas </summary>
		///<param name="h"> Diferen�a </param>
		void setJacobiana(double h);

		///<summary> Define os par�metros para c�lculo do sistema linear </summary>
		///<param name="nIteracaoMax"> O n�mero m�ximo de itera��es </param>
		void setLinear(int nIteracaoMax, double erroMax);
};


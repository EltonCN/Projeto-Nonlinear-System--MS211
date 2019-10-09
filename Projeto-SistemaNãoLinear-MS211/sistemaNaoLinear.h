#pragma once

#include "sistemaLinear.h"
#include "jacobiana.h"


#ifndef tipoFuncao
#define tipoFuncao
typedef double(*Funcao)(double*);
#endif 

///<summary> Resolve um sistema não linear </summary>
class SistemaNaoLinear
{
	private:
		double* xAtual; ///<value> Solução atual do sistema </value>
		double* xAnterior; ///<value> Solução anterior do sistema </value>
		double* funcaoPontoN; ///<value> Valor da função no ponto atual </value>
		double* delta; ///<value> Diferença entre xAtual e xAnterior </value>

		int nFuncao, ///<value> Número de funções do sistema </value>
			nIncognita; ///<value> Número de incógnitas do sistema </value>

		///<value> Vetor de funções </value>
		///<remarks> Devem retorna "0" no vetor solução </remarks>
		Funcao* funcao;

		int nIteracao; ///<value> Índice da iteração atual </value>
		int nMaxIteracao; ///<value> Número máximo de iterações </value>
		double erroMaximo; ///<value> Erro máximo nas funções </value>
		double** matrizJacobiana;

		SistemaLinear sistemaLinear; ///<value> Resolve o sistema linear </value>
		Jacobiana jacobiana; ///<value> Calcula a matriz Jacobiana </value>

		///<summary> Realiza uma iteração </summary>
		void iterar();

		///<summary> Calcula o erro máximo nas funções </summary>
		///<returns> O erro máximo </return>
		double erro();

		///<summary> Avalia as funções no ponto atual </summary>
		void avaliaFuncoes();

		///<summary> Atualiza o vetor xAtual </summary>
		void atualizaX();

		///<summary> Atualiza a matriz Jacobiana </summary>
		void atualizaJacobiana();
	public:
		///<summary> Construtor </summary>
		///<param name="nFuncao"> Número de funções do sistema </param>
		///<param name="nIncognita"> Número de incógnitas do sistema </param>
		SistemaNaoLinear(int nFuncao, int nIncognita);
		~SistemaNaoLinear();

		///<summary> Define uma das funções do sistema </summary>
		///<remarks> A função deve retornar "0" no vetor solução </remarks>
		///<param name="indice"> Índice da função </param>
		///<páram name="funcao"> Ponteiro para a função </param>
		void inserirFuncao(int indice, Funcao funcao);

		///<summary> Define o número máximo de iterações </summary>
		///<param name="nMaxIteracao"> O número máximo de iterações </param>
		void setParadaIteracao(int nMaxInteracao);

		///<summary> Define o erro máximo para parada </summary>
		///<remarks> Também determina que o algorítmo utilizará esse critério </remarks>
		///<param name="erroMaximo"> O erro máximo a ser definido </param>
		///<remaks> "0" para não utilizar esse critério </remarks>
		void setParadaErro(double erroMaximo);

		///<summary> Calcula a solução do sistema </summary>
		///<param name="inicial"> O valor inicial para o sistema </param>
		///<returns> O vetor solução </returns>
		double* calcular(double* inicial);

		///<summary> Define a diferença h para cálculo das derivadas </summary>
		///<param name="h"> Diferença </param>
		void setJacobiana(double h);

		///<summary> Define os parâmetros para cálculo do sistema linear </summary>
		///<param name="nIteracaoMax"> O número máximo de iterações </param>
		void setLinear(int nIteracaoMax, double erroMax);
};


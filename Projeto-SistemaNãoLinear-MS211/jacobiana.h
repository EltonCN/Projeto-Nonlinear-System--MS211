#pragma once
#include <stdlib.h>

#ifndef tipoFuncao
#define tipoFuncao
typedef double(*Funcao)(double*);
#endif 

///<summary> Implementa o cálculo de uma matriz Jacobiana, aproximando as derivadas </summary>
///<remarks> Aproxima a derivada considerando uma diferença h </remarks>
class Jacobiana
{
	private:
		
		Funcao *funcao;///<value> Vetor de funções </value>
		
		///<value> Diferença a ser utilizada </value>
		int h; 
		int nFuncao, ///<value> Número de funções no vetor </value>
			nIncognita; ///<value> Número de variáveis das funções </value>

		///<summary> Calcula um valor de derivada </summary>
		///<param name="indiceFuncao"> Índice da função a ser avaliada </param>
		///<param name="indiceX"> Índice da variável em análise </param>
		///<param name="x"> Vetor das variáveis </param>
		double calculaDerivada(int indiceFuncao, int indiceX, double* x);
		

	public:
		///<summary> Construtor </summary>
		///<param name="nFuncao"> Número de funções </param>
		///<param name="nIncognita> Número de incognitas </param>
		Jacobiana(int nFuncao, int nIncognita);
		~Jacobiana();

		///<summary> Insere uma função para cálculo </summary>
		///<param name="indice"> Índice da função sendo analisada </param>
		///<param name="funcao"> Ponteiro para a função </param>
		void inserirFuncao(int indice, Funcao funcao);

		///<summary> Define a diferença h para cálculo das derivadas </summary>
		///<param name="h"> Diferença h sendo inserida </param>
		void setH(double h);

		///<summary> Avalia a matriz em um ponto </summary>
		///<param name="x"> Vetor em análise </param>
		///<return> A matriz calculada </return>
		double** avaliar(double *x);
};


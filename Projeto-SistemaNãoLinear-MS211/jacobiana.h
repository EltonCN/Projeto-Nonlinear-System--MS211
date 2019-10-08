#pragma once
#include <stdlib.h>

#ifndef tipoFuncao
#define tipoFuncao
typedef double(*Funcao)(double*);
#endif 

///<summary> Implementa o c�lculo de uma matriz Jacobiana, aproximando as derivadas </summary>
///<remarks> Aproxima a derivada considerando uma diferen�a h </remarks>
class Jacobiana
{
	private:
		
		Funcao *funcao;///<value> Vetor de fun��es </value>
		
		///<value> Diferen�a a ser utilizada </value>
		int h; 
		int nFuncao, ///<value> N�mero de fun��es no vetor </value>
			nIncognita; ///<value> N�mero de vari�veis das fun��es </value>

		///<summary> Calcula um valor de derivada </summary>
		///<param name="indiceFuncao"> �ndice da fun��o a ser avaliada </param>
		///<param name="indiceX"> �ndice da vari�vel em an�lise </param>
		///<param name="x"> Vetor das vari�veis </param>
		double calculaDerivada(int indiceFuncao, int indiceX, double* x);
		

	public:
		///<summary> Construtor </summary>
		///<param name="nFuncao"> N�mero de fun��es </param>
		///<param name="nIncognita> N�mero de incognitas </param>
		Jacobiana(int nFuncao, int nIncognita);
		~Jacobiana();

		///<summary> Insere uma fun��o para c�lculo </summary>
		///<param name="indice"> �ndice da fun��o sendo analisada </param>
		///<param name="funcao"> Ponteiro para a fun��o </param>
		void inserirFuncao(int indice, Funcao funcao);

		///<summary> Define a diferen�a h para c�lculo das derivadas </summary>
		///<param name="h"> Diferen�a h sendo inserida </param>
		void setH(double h);

		///<summary> Avalia a matriz em um ponto </summary>
		///<param name="x"> Vetor em an�lise </param>
		///<return> A matriz calculada </return>
		double** avaliar(double *x);
};


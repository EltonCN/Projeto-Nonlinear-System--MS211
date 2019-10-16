#pragma once

//LUx = b, Ux = Y, LY= b 
//

///<summary> Implementa a resolu��o de sistemas lineares </summary>
///<remarks> <para> Utiliza o m�tode de Gauss-Jacobi </para>
///<para> Quando n�o poss�vel, utiliza fatora��o LU </para></remarks>
class SistemaLinear
{
	private:
		int nIteracao; ///<value> �ndice da itera��o atual </value>
		int nMaxIteracao; ///<value> N�mero m�ximo de itera��es </value>
		double erroMaximo; ///<value> Erro m�ximo nas fun��es </value>

		int nEquacao;///<value> O n�mero de equa��es do sistema </value>
		int *permutado;

		double** m; ///<value> A matriz de coeficientes </value>
		double* b; ///<value> O vetor dos termos independentes </value>
		
		double* xAnt; ///<value> Solu��o anterior </value>
		double* xAtual; ///<value> Solu�a� atual </value>

		///<summary> Realiza uma itera��o </summary>
		void iterar();

		///<summary> Calcula o erro m�ximo nas fun��es </summary>
		///<returns> O erro m�ximo </return>
		double erro();

	public:
		SistemaLinear(int nEquacao);
		~SistemaLinear();

		///<summary> Define o n�mero m�ximo de itera��es </summary>
		///<param name="nMaxIteracao"> O n�mero m�ximo de itera��es </param>
		void setParadaIteracao(int nMaxIteracao);

		///<summary> Define o erro m�ximo para parada </summary>
		///<remarks> Tamb�m determina que o algor�tmo utilizar� esse crit�rio </remarks>
		///<param name="erroMaximo"> O erro m�ximo a ser definido </param>
		///<remaks> "0" para n�o utilizar esse crit�rio </remarks>
		void setParadaErro(double erroMaximo);

		///<summary> Insere a matriz de coeficientes </summary>
		///<param name="matrizCoeficientes"> A matriz de coeficientes </param>
		void inserirMatriz(double** matrizCoeficientes);

		///<summary> Insere o vetor de termos independentes </summary>
		///<param name="fonte"> Vetor </param>
		void inserirTermoFonte(double* fonte);

		///<summary> Calcula a solu��o do sistema </summary>
		///<returns> O vetor solu��o </returns>
		double* calcular();

		///<summary> Calcula a solu��o do sistema </summary>
		///<param name="inicial"> Valor inicial </param>
		///<returns> O vetor solu��o </returns>
		double* calcular(double* inicial);
};


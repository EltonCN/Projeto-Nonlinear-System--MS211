#pragma once

/// <summary> Implementa a resolução de sistemas lineares </summary>
/// <remarks> Utiliza o método de de Gauss-Jacobi </remarks> 
class SistemaLinear
{
	private:
		int nIteracao; /// <value> Índice da iteração atual </value>
		int nMaxIteracao; /// <value> Número máximo de iterações </value>
		double erroMaximo; /// <value> Erro máximo nas funções </value>

		int nEquacao;/// <value> O número de equações do sistema </value>

		double** m; /// <value> A matriz de coeficientes </value>
		double* b; /// <value> O vetor dos termos independentes </value>
		
		double* xAnt; /// <value> Solução anterior </value>
		double* xAtual; /// <value> Soluçaõ atual </value>

		/// <summary> Realiza uma iteração </summary>
		void iterar();

		/// <summary> Calcula o erro máximo nas funções </summary>
		/// <returns> O erro máximo </returns>
		double erro();

	public:
		/// <summary> Construtor da classe </summary>
		/// <param name="nEquacao"> O número de equações do sistema </param>
		SistemaLinear(int nEquacao);
		~SistemaLinear();

		/// <summary> Define o número máximo de iterações </summary>
		/// <param name="nMaxIteracao"> O número máximo de iterações </param>
		void setParadaIteracao(int nMaxIteracao);

		/// <summary> Define o erro máximo para parada </summary>
		/// <remarks> Também determina que o algorítmo utilizará esse critério </remarks>
		/// <param name="erroMaximo"> O erro máximo a ser definido </param>
		/// <remarks> "0" para não utilizar esse critério </remarks>
		void setParadaErro(double erroMaximo);

		/// <summary> Insere a matriz de coeficientes </summary>
		/// <param name="matrizCoeficientes"> A matriz de coeficientes </param>
		void inserirMatriz(double** matrizCoeficientes);

		/// <summary> Insere o vetor de termos independentes </summary>
		/// <param name="fonte"> Vetor </param>
		void inserirTermoFonte(double* fonte);

		/// <summary> Calcula a solução do sistema </summary>
		/// <returns> O vetor solução </returns>
		double* calcular();

		/// <summary> Calcula a solução do sistema </summary>
		/// <param name="inicial"> Valor inicial </param>
		/// <returns> O vetor solução </returns>
		double* calcular(double* inicial);
};


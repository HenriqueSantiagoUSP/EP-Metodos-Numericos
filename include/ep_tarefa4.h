/*
FUNÇÕES DA TAREFA EP_TAREFA4
*/
#ifndef EP_TAREFA4_H
#define EP_TAREFA4_H

//===========================================================================
/* Gera fatoração QR da matriz A

Parametros:
- M: Número de linhas de A e de Q
- N: Número de colunas de A e de Q e dimensão da matriz R
- A: Matriz a ser fatorada
- Q: Matriz de colunas ortonormais com base na matriz A
- R: Matriz triangular superior

*/
void gram_schmidt(int M, int N, double A[M][N], double Q[M][N], double R[N][N]);


//===========================================================================
//                      FUNÇÃO PARA TESTAR A FATORAÇÃO QR
//===========================================================================
/* Multriplica as matrizes QR

Parametros:
- M: Número de linhas de Q e do resultado
- N: Número de colunas de Q e do resultado, e dimensão da matriz R
- Q: Matriz de colunas ortonormais
- R: Matriz triangular superior
- resultado: Matriz resultante do produto QR

*/
void multiplicar_QR(int M, int N, double Q[M][N], double R[N][N], double resultado[M][N]);

#endif
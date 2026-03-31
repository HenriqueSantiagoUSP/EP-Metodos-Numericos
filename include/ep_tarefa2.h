/*
FUNÇÕES DA TAREFA EP_TAREFA2
*/
#ifndef EP_TAREFA2_H
#define EP_TAREFA2_H

//===========================================================================
/* Extrai coluna j da matriz A para um vetor v

Parametros:
- M: Numero de linhas da matriz A e tamanho do vetor v
- N: Numero de colunas da matriz A
- j: Coluna a ser extraida
- A: Matriz A
- v: Vetor v

*/
void extrair_coluna(int M, int N, int j, double A[M][N], double v[M]);

//===========================================================================
/* Copia a coluna j da matriz A e cola na coluna j da matriz B

Parametros:
- M: Numero de linhas das matrizes
- N: Numero de coluna das matrizes
- j: Coluna a ser copiada
- A: Matriz A
- B: Matriz B

*/
void copiar_coluna(int M, int N, int j, double A[M][N], double B[M][N]);

//===========================================================================
/* Multriplica a transporta da matriz A pelo vetor x, e guarda em y o resulto
    A^T * x = y

Parametros:
- M: Numero de linhas da matriz A e tamanho do vetor x
- N: Numero de colunas da matriz A e tamanho do vetor y
- A: Matriz A
- x: Vetor x
- y: Vetor y

*/
void multiplicacao_transposta_vetor(int M, int N, double A[M][N], double x[M], double y[N]);

//===========================================================================

#endif
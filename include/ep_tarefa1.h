/*
FUNÇÕES DA TAREFA EP_TAREFA1
*/
#ifndef EP_TAREFA1
#define EP_TAREFA1

//===========================================================================
/* Imprime a matriz

Parametros:
- M: Numero de linhas
- N: Numero de coluans
- A[M][N]: Matrix A
- nome: Nome da matriz

*/
void imprimir_matriz(int M, int N, double A[M][N], char *nome);

//===========================================================================
/* Imprime o vetor

Parametros:
- M: Tamanho do vetor
- v: Vetor v
- nome: Nome do vetor

*/
void imprimir_vetor(int M, double v[M], char *nome);

//===========================================================================
/* Produto interno de dois vetores

Parametros:
- M: Tamanho dos vetores
- u: Vetor u
- v: Vetor v

Retorna: O produto interno entre u e v

*/
double produto_interno(int M, double u[M], double v[M]);

//===========================================================================
/* Norma de um vetor

Paramtros:
- M: tamanho do vetor
- v: Vetor v

Retorna: A norma de v

*/
double norma(int M, double v[M]);

//===========================================================================

#endif
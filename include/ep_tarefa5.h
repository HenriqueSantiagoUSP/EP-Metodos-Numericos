/*
FUNÇÕES DA TAREFA EP_TAREFA5
*/
#ifndef EP_TAREFA5_H
#define EP_TAREFA5_H

//===========================================================================
/* Enum para operação de soma/diferença de matrizes

Valores:
- SUM: Soma (A + B)
- DIFF: Diferença (A - B)

*/
typedef enum{
    SUM = 0,
    DIFF = 1,
} soma;

//===========================================================================
/* Lê o arquivo de dados dos satélites GPS

Parametros:
- nusp: Número USP do aluno (usado para selecionar o arquivo)
- M: Número de satélites (linhas do arquivo)
- N: Número de dados por satélite (colunas: x, y, z, w)
- A: Matriz de saída contendo os dados do satélite

*/
void ler_dados(int nusp, int M, int N, double A[M][N]);

//===========================================================================
/* Converte coordenadas cartesianas (x, y, z) em latitude e longitude

Parametros:
- x: Vetor com as coordenadas (x, y, z, w) do receptor
- lat: Ponteiro para a latitude calculada (em graus)
- lon: Ponteiro para a longitude calculada (em graus)

*/
void geo_cords(double x[], double* lat, double* lon);

//===========================================================================
/* Multiplica duas matrizes: ret = A * B

Parametros:
- M: Número de linhas de A e de ret
- N: Número de colunas de A e número de linhas de B
- J: Número de colunas de B e de ret
- A: Matriz A (M x N)
- B: Matriz B (N x J)
- ret: Matriz resultado (M x J)

*/
void multiplicar_matriz(int M, int N, int J, double A[M][N], double B[N][J], double ret[M][J]);

//===========================================================================
/* Soma ou subtrai duas matrizes: ret = A ± B

Parametros:
- op: Operação a ser realizada (SUM ou DIFF)
- M: Número de linhas das matrizes
- N: Número de colunas das matrizes
- A: Matriz A
- B: Matriz B
- ret: Matriz resultado

*/
void soma_matriz(soma op, int M, int N, double A[M][N], double B[M][N], double ret[M][N]);

//===========================================================================

#endif
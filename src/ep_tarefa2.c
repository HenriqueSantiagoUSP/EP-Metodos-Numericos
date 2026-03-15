#include "ep_tarefa1.h" // chamada das funcoes ja criadas
#include "ep_tarefa2.h"

void extrair_coluna(int M, int N, int j, double A[M][N], double v[M]){
  /*
   * Dada uma matriz de tamanho MxN, retorna um vetor de tamanho M contendo
   * a j-ésima coluna da matriz
   *
   * Entradas:
   * - M (int): número de linhas da matriz
   * - N (int): número de colunas da matriz
   * - j (int): índice da coluna a ser extraída
   * - A (double[M][N]): matriz
   *
   * Saída:
   * - v (double[M]): j-ésima coluna de A
   */

  // COMPLETAR
  
  for (int i = 0; i < M; i++){
    v[i] = A[i][j];
  }

}

void copiar_coluna(int M, int N, int j, double A[M][N], double B[M][N]){
  /*
   * Dadas duas matrizes A e B de tamanho MxN, copia a j-ésima coluna de A
   * na j-ésima coluna de B
   *
   * Entradas:
   * - M (int): número de linhas das matrizes
   * - N (int): número de colunas das matrizes
   * - j (int): índice da coluna a ser copiada
   * - A (double[M][N]): matriz
   * - B (double[M][N]): matriz
   *
   * Saída:
   * - B (double[M][N]): matriz com a coluna j modificada
   */

  // COMPLETAR

  for (int i = 0; i < M; i++){
    B[i][j] = A[i][j];
  }
}

void multiplicacao_transposta_vetor(int M, int N, double A[M][N], double x[M], double y[N]){
  /*
   * Dadas uma matriz A tamanho MxN e um vetor x de tamanho N, calcula o produto de A^T com v
   *
   *
   * Entradas:
   * - M (int): número de linhas da matriz e de elementos do vetor
   * - N (int): número de colunas da matriz
   * - A (double[M][N]): matriz 
   * - x (double[M][N]): vetor
   *
   * Saída:
   * - y (double[M][N]): vetor = A^Tx
   */

  // COMPLETAR


  double buffer[M];

  for (int i = 0; i < N; i++){
    extrair_coluna(M, N, i, A, buffer);
    y[i] = produto_interno(N, buffer, x);
  }
}
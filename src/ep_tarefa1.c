#include <stdio.h> //printf
#include <math.h> //sqrt

#include "ep_tarefa1.h"

void imprimir_matriz(int M, int N, double A[M][N], char *nome) {
  /*
   * Imprime uma matriz na forma
   *
   * nome =
   * a11 a12 ... a1N
   * a21 a22 ... a2N
   * ...............
   * aM1 aM2 ... aMN
   *
   * Entradas:
   * - M (int): número de linhas da matriz
   * - N (int): número de colunas da matriz
   * - A (double[M][N]): matriz a ser impressa
   * - nome (char*): nome da matriz
   *
   */

  // COMPlETAR

  printf("\n%s %dx%d\n", nome, M, N);

  for (int i = 0; i < M; i++){

    for (int j = 0; j < N; j++){
      printf("%.2lf\t", A[i][j]);
    }

    printf("\n");
  }
  printf("\n");
}

void imprimir_vetor(int M, double v[M], char *nome) {
  /*
   * Imprime um vetor na forma
   *
   * nome =
   * v1
   * v2
   * ..
   * vM
   *
   * Entradas:
   * - M (int): número de elementos do vetor
   * - v (double[M]): vetor a ser impresso
   * - nome (char*): nome do vetor
   *
   */

  // COMPLETAR

  printf("\n%s =\n", nome);

  for (int i = 0; i < M; i++) {
    printf("%.2lf\n", v[i]);
  }
}

double produto_interno(int M, double u[M], double v[M]) {
  /*
   * Dados dois vetores u e v de tamanho M, calculad o produto interno usual
   *
   * <u,v> = \sum_{i=1}^M u[i]*v[i]
   *
   * Entradas:
   * - M (int): número de elementos de cada vetor
   * - u (double[M]): primeiro vetor
   * - v (double[M]): segundo vetor
   *
   * Saídas:
   * - double: produto interno entre u e v
   */

  // COMPLETAR

  double prod_int = 0;

  for (int i = 0; i < M; i++){
    prod_int += u[i]*v[i];
  }
  
  return prod_int;
}

double norma(int M, double v[M]) {
  /*
   * Dado um vetor de tamanho M, calcula sua norma Euclidiana
   *
   * Entradas:
   * - M (int): número de elementos do vetor
   * - v (double[M]): vetor
   *
   * Saída:
   * - double: norma Euclidiana de v
   */

  // COMPLETAR

  return sqrt(produto_interno(M, v, v));
}
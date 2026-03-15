/*
TESTES DAS FUNÇOES DO EP_TAREFA2
*/
#include <stdio.h>
#include <stdlib.h>

#include "random.h"
#include "ep_tarefa1.h"
#include "ep_tarefa2.h"

// Definição do intervalo de geração aleatória dos elementos
#define MATRIX_MAX (double)20
#define MATRIX_MIN (double)0
#define VECTOR_MAX (double)20
#define VECTOR_MIN (double)0

int main(){

  // COMPLETAR
  // Teste e valide as funções implementadas

  init_rand();

  //===========================================================================
  // Gera Matrizes A e B; e Vetores u, x e y
  int M = (int)rand_range(2, 6); // Numero de linhas de A e B; tamanho de v e x
  int N = (int)rand_range(2, 6); // Numero de colunas de A e B; tamanho de y

  // Matriz A
  double *ptr1 = gera_rand_matrix(M, N, MATRIX_MIN, MATRIX_MAX);
  double (*A)[N] = (double (*)[N]) ptr1;

  // Matriz B
  double *ptr2 = gera_rand_matrix(M, N, MATRIX_MIN, MATRIX_MAX);
  double (*B)[N] = (double (*)[N]) ptr2;

  // Vetor v
  double *v = gera_rand_vet(M, VECTOR_MIN, VECTOR_MAX);

  // Vetor x
  double *x = gera_rand_vet(M, VECTOR_MIN, VECTOR_MAX);

  // Vetor y
  double *y = gera_rand_vet(N, VECTOR_MIN, VECTOR_MAX);
  
  //===========================================================================
  // Teste extrair coluna de uma matrix A para o vetor v: (A, v)

  printf("\n===========================================================================\n");
  printf("1. Teste: Extrair coluna de uma matrix A para um vetor v\n");
  
  imprimir_matriz(M, N, A, "A");

  int colum = rand_range(0, N-1); // coluna a ser extraida
  printf("Extraindo coluna %d\n", colum + 1);
  
  extrair_coluna(M, N, colum, A, v);

  imprimir_vetor(M, v, "v");

  free(v); //Libera v

  //===========================================================================
  // Teste copiar coluna j de A para a coluna j de B: (A, B)

    printf("\n===========================================================================\n");
    printf("2. Teste: Copiar coluna de A para B\n");

    printf("Matrizes antes da copia:\n");

    imprimir_matriz(M, N, A, "A");

    imprimir_matriz(M, N, B, "B");

    int j = rand_range(0, N);

    printf("Copiada a coluna %d da matriz A para matriz B\n", j + 1);

    copiar_coluna(M, N, j, A, B);

    imprimir_matriz(M, N, B, "B");

    free(B); // Libera B

  //===========================================================================
  // Teste multiplicação da transsposta de A com o vetor x

    printf("\n===========================================================================\n");
    printf("3. Teste: Multiplicação da transposta de A com o vetor x\n");

    imprimir_matriz(M, N, A, "A");

    imprimir_vetor(M, x, "x");

    printf("\nA^T * x = y\n");

    multiplicacao_transposta_vetor(M, N, A, x, y);

    imprimir_vetor(N, y, "y");

    // Libera os pointers
    free(A);
    free(x);
    free(y);

    //===========================================================================
    printf("\n===========================================================================\n");

  return 0;
}
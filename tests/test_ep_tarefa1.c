/*
TESTES DAS FUNÇOES DO EP_TAREFA1
*/
#include <stdio.h>
#include <stdlib.h> //free

#include "random.h"
#include "ep_tarefa1.h"

// Definição do intervalo de geração aleatória dos elementos
#define MATRIX_MAX (double)20
#define MATRIX_MIN (double)0
#define VECTOR_MAX (double)20
#define VECTOR_MIN (double)0

int main() {

  // COMPLETAR
  // Teste e valide as funções implementadas

  init_rand();

  //===========================================================================
  // Gera matiz A e vetores u e v

  int M = (int)rand_range(2, 8); // Numero de linhas de A e  tamanho dos vetores
  int N = (int)rand_range(2, 8); // Numero de colunas de A

  // Matriz A
  double *ptr1 = gera_rand_matrix(M, N, MATRIX_MIN, MATRIX_MAX);
  double (*A)[N] = (double (*)[N])(ptr1);

  // Vetor v
  double *v = gera_rand_vet(M, VECTOR_MIN, VECTOR_MAX);

  // Vetor u
  double *u = gera_rand_vet(M, VECTOR_MIN, VECTOR_MAX);

  //===========================================================================
  // Teste imprimir matriz A: (A)

  printf("\n===========================================================================\n");
  printf("1. Teste: Imprimir matriz A\n");

  imprimir_matriz(M, N, A, "A");

  free(A); // Libera A

  //===========================================================================
  // Teste imprimir vetor v: (v)

  printf("\n===========================================================================\n");
  printf("2. Teste: Imprimir vetor v\n");

  imprimir_vetor(M, v, "v");

  //===========================================================================
  // Teste produto interno entre v e u: (v, u)

  printf("\n===========================================================================\n");
  printf("3. Teste: Produto interno entre v e u: <v, u>\n");

  imprimir_vetor(M, v, "v");
  imprimir_vetor(M, u, "u");

  printf("\n<v, u> = %.2lf\n", produto_interno(M, v, u));

  free(u); // Libera u

  //===========================================================================
  // Teste norma de v: (v)

  printf("\n===========================================================================\n");
  printf("4. Teste: Norma de v: |v|\n");

  imprimir_vetor(M, v, "v");

  printf("\n|v| = %.2lf\n", norma(M, v));

  free(v); // Libera v

  //===========================================================================
  printf("\n===========================================================================\n");

  return 0;
}
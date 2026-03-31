/*
TESTES DAS FUNÇOES DO EP_TAREFA4
*/
#include <stdio.h>
#include <stdlib.h>

#include "random.h"
#include "ep_tarefa1.h"
#include "ep_tarefa2.h"
#include "ep_tarefa4.h"

// Definição do intervalo de geração aleatória dos elementos
#define MATRIX_MAX (double)20
#define MATRIX_MIN (double)0

int main(){

  // COMPLETAR
    // Teste e valide as funções implementadas

    init_rand();

    //===========================================================================
    // Gera Matriz A, Q e R 

    int M = (int)rand_range(2, 6); // linhas
    int N = (int)rand_range(2, 6); // colunas

    // Matriz A
    double *ptr1 = gera_rand_matrix(M, N, MATRIX_MIN, MATRIX_MAX);
    double (*A)[N] = (double (*)[N]) ptr1;

    // Matriz Q
    double Q[M][N];

    // Matriz R
    double R[N][N];

    // Matriz QR
    double QR[M][N];

    //===========================================================================
    // Teste fatora a matriz A em QR: (A, R, Q, QR)

    printf("\n===========================================================================\n");
    printf("1. Teste: Fatorar a matriz A em QR\n");

    imprimir_matriz(M, N, A, "A");

    gram_schmidt(M, N, A, Q, R);

    printf("\nA fatoração QR de A é dada por:\n");

    imprimir_matriz(M, N, Q, "Q");

    imprimir_matriz(N, N, R, "R");

    printf("\nAo multiplicar Q x R podemos verificar que de fato QR = A\n");
    // Imprime QR para verificar se QR = A
    multiplicar_QR(M, N, Q, R, QR);

    imprimir_matriz(M, N, QR, "QR");

    // Libera a matriz A
    free(A);

    //===========================================================================
    printf("\n===========================================================================\n");

  return 0;
}
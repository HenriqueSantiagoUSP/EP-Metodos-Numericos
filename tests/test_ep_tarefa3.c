/*
TESTES DAS FUNÇOES DO EP_TAREFA3
*/
#include <stdio.h>
#include <stdlib.h>

#include "random.h"
#include "ep_tarefa1.h"
#include "ep_tarefa2.h"
#include "ep_tarefa3.h"

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
    // Gera Matriz R, vetor b e vetor 

    int N = (int)rand_range(2, 6);

    // Gera Matriz R
    double *ptr1 = gera_rand_mat_triangular(N, MATRIX_MIN, MATRIX_MAX);
    double (*R)[N] = (double (*)[N]) ptr1;

    // Gera vetor b
    double* b = gera_rand_vet(N, VECTOR_MIN, VECTOR_MAX);

    // Gera vetor x
    double* x = calloc(N, sizeof(double));

    //===========================================================================
    // Teste resolve sistema triangular superior: (R, b, x)

    printf("\n===========================================================================\n");
    printf("1. Teste: Resolver sistema triangular superior\n");

    printf("Resolvendo Rx = b, com R e b iguais a:\n");
    imprimir_matriz(N, N, R, "R");
    imprimir_vetor(N, b, "b");

    // Resolve sistema
    resolver_sistema_triangular_superior(N, R, b, x);

    printf("\nResultado:\n");
    imprimir_vetor(N, x, "x");

    // Libera pointers
    free(R);
    free(b);
    free(x);

    //===========================================================================
    printf("\n===========================================================================\n");

    return 0;
}
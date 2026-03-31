#include "ep_tarefa1.h"
#include "ep_tarefa2.h"
#include "ep_tarefa4.h"
#include <stdio.h>
#include <stdlib.h>
#include<math.h>

void gram_schmidt(int M, int N, double A[M][N], double Q[M][N], double R[N][N]){

  for (int j = 0; j < N; j++)
    for (int i = 0; i < N; i++)
      R[i][j] = 0;

  for (int j = 0; j < N; j++)
    copiar_coluna(M, N, j, A, Q);

  double* sum      = calloc(M, sizeof(double));
  double* col_atual = calloc(M, sizeof(double));
  double* col_ortg  = calloc(M, sizeof(double));

  //============================ RESOLVE Q ==================================

  for (int j = 0; j < N; j++){
    for (int i = 0; i < M; i++) sum[i] = 0;

    extrair_coluna(M, N, j, Q, col_atual);

    for (int i = 0; i < j; i++){
      extrair_coluna(M, N, i, Q, col_ortg);

      double norma_sq = produto_interno(M, col_ortg, col_ortg);
      if (norma_sq < 1e-10){ printf("\nMatriz LD!\tColuna %d\n", j); continue; }

      double coef = produto_interno(M, col_ortg, col_atual) / norma_sq;
      for (int k = 0; k < M; k++) sum[k] += coef * col_ortg[k];
    }

    for (int i = 0; i < M; i++) Q[i][j] -= sum[i];
  }

  // Normaliza colunas de Q
  for (int j = 0; j < N; j++){
    extrair_coluna(M, N, j, Q, col_atual);
    double norm = norma(M, col_atual);
    if (norm < 1e-10) continue;
    for (int i = 0; i < M; i++) Q[i][j] /= norm;
  }

  //============================ RESOLVE R ==================================
  // R[i][j] = <q_i, a_j>, R é triangular superior então i <= j

  double* col_q = calloc(M, sizeof(double));
  double* col_a = calloc(M, sizeof(double));

  for (int j = 0; j < N; j++){
    extrair_coluna(M, N, j, A, col_a);
    for (int i = 0; i <= j; i++){
      extrair_coluna(M, N, i, Q, col_q);
      R[i][j] = produto_interno(M, col_q, col_a);
    }
  }

  free(sum); free(col_atual); free(col_ortg); free(col_q); free(col_a);
}

void multiplicar_QR(int M, int N, double Q[M][N], double R[N][N], double resultado[M][N]) {
    for (int i = 0; i < M; i++) {
        for (int j = 0; j < N; j++) {
            resultado[i][j] = 0;
            for (int k = 0; k < N; k++) {
                resultado[i][j] += Q[i][k] * R[k][j];
            }
        }
    }
}
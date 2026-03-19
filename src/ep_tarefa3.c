#include "ep_tarefa3.h"

void resolver_sistema_triangular_superior(int N, double R[N][N], double b[N], double x[N]){
  /*
   * Dadas uma matriz R de tamanho NxN, triangular superior, e um vetor b de tamanho N
   * resolve o sistema linear Rx = b
   *
   * Entradas:
   * - N (int): tamanho do sistema linear
   * - R (double[N][N]): matriz triangular superior
   * - b (double[N]): vetor
   *
   * Saída:
   * - x (double[N]): vetor solução
   */

  // COMPlETAR
    for (int i = N - 1; i >= 0; i--){
        double sum = 0;
        for (int j = i + 1; j < N; j++){
            sum += R[i][j]*x[j];
        }
        x[i] = (b[i] - sum)/R[i][i];
    }
}
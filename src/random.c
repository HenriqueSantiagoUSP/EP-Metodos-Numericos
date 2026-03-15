#include <stdlib.h>
#include <time.h>

#include "random.h"

void init_rand(){
    srand(time(NULL));
}

double rand_range(double min, double max) {
    return (rand() / (double)RAND_MAX) * (max - min) + min;
}

double* gera_rand_vet(int N, double min, double max){
  double* vet = malloc(N*sizeof(double));
  for (int i = 0; i < N; i++){
    vet[i] = rand_range(min, max); // Elementos entre min e max
  }
  return vet;
}

double* gera_rand_matrix(int M, int N, double min, double max){
  double* mat = malloc((N)*(M)*sizeof(double));
  for (int i = 0; i < M; i++){
    for (int j = 0; j < N; j++){
      mat[N*i+j] = rand_range(min, max); // Elementos entre min e max
    }
  }
  return mat;
}
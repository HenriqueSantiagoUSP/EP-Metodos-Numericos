#include "ep_tarefa1.h"
#include "ep_tarefa2.h"
#include "ep_tarefa3.h"
#include "ep_tarefa4.h"
#include "ep_tarefa5.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#define _M_ (int)7
#define M (int)6
#define N (int)4
#define nusp (int)16872729

// Constantes
#define EARTH_RADIUS 
#define c 

double (*matriz_de_coordenadas(void))[N]{
    double (*ret)[N] = malloc(_M_ * N * sizeof(double));
    ler_dados(nusp, _M_, N, ret);
    return ret;
}

int main(){
    
    // COMPLETAR
    // Recebe os inputs
    double (*_A_)[N] = matriz_de_coordenadas();
    
    imprimir_matriz(_M_, N, _A_, "_A_");

    // Determinando matriz A
    double A[M][N];

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N-1; j++){
            A[i][j] = 2*(_A_[M][j] - _A_[i][j]);   // x, y, z
        }
    A[i][N-1] = 2*(_A_[i][N-1] - _A_[M][N-1]); // w (sinal invertido)
    }

    imprimir_matriz(M, N, A, "A");

    // Vetor b
    double b[M] = {0};

    double um = 0;

    for (int j = 0; j < N-1; j ++){
        um += _A_[M][j]*_A_[M][j];
    }
    um -= _A_[M][N-1]*_A_[M][N-1];

    printf("um = %lf\n", um);

    for (int i = 0; i < M; i++){
        double ui = 0;
        for (int j = 0; j < N-1; j++){
            ui += _A_[i][j]*_A_[i][j];
        }
        ui -= _A_[i][N-1]*_A_[i][N-1];
        printf("ui = %lf\n", ui);
        b[i] = um - ui;
    }

    imprimir_vetor(M, b, "b");

    //====================================================

    // Fatora QR
    double Q[M][N] = {0};
    double R[N][N] = {0};
    
    gram_schmidt(M, N, A, Q, R);

    imprimir_matriz(M, N, Q, "Q");
    imprimir_matriz(N, N, R, "R");

    // Resolve sistema triangular superior
    double x[N];
    double QTb[N];

    multiplicacao_transposta_vetor(M, N, Q, b, QTb);

    resolver_sistema_triangular_superior(N, R, QTb, x);

    double lat_ns, long_we;
    geo_cords(x, &lat_ns, &long_we);

    imprimir_vetor(N, QTb, "QTb");
    imprimir_vetor(N, x, "x");

    printf("\n%lf\n%lf\n", lat_ns, long_we);

    double radius = 0;

    for (int j = 0; j < N - 1; j++){
        radius += x[j]*x[j];
    }

    radius = sqrt(radius);

    printf("\n%lf\n", radius/1e3);

    free(_A_);

    return 0;
}
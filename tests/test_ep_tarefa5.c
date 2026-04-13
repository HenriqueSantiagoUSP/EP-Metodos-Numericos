/*
TESTES DAS FUNÇOES DO EP_TAREFA5
*/
#include <stdio.h>
#include <stdlib.h>
#include <math.h>

#include "ep_tarefa1.h"
#include "ep_tarefa2.h"
#include "ep_tarefa3.h"
#include "ep_tarefa4.h"
#include "ep_tarefa5.h"

// Dimensões do problema
#define _M_ (int)7          // Número total de satélites
#define M (int)6            // Número de equações do sistema linearizado (m - 1)
#define N (int)4            // Número de incógnitas (x, y, z, w)
#define nusp (int)16872729  // Número USP

// Constantes físicas
#define EARTH_RADIUS (double)6371.0   // Raio médio da Terra (km)
#define c (double)299792458.0         // Velocidade da luz no vácuo (m/s)

//===========================================================================
// Funções auxiliares

/* Lê o arquivo de coordenadas dos satélites e retorna um ponteiro
   para a matriz _M_ x N alocada dinamicamente */
double (*matriz_de_coordenadas(void))[N]{
    double (*ret)[N] = malloc(_M_ * N * sizeof(double));
    ler_dados(nusp, _M_, N, ret);
    return ret;
}

/* Calcula sqrt(x^2 + y^2 + z^2), o raio do receptor ao centro da Terra */
double radius_calc(double x[]){
    double ret = 0;

    for (int j = 0; j < N - 1; j++){
        ret += x[j]*x[j];
    }
    
    return sqrt(ret);
}

//===========================================================================

int main(){

    //===========================================================================
    // 1. Leitura dos dados dos satélites: Ã (M x N)

    printf("\n================================================================\n");
    printf("1. Leitura da matriz de input.\n");

    double (*_A_)[N] = matriz_de_coordenadas();

    imprimir_matriz(_M_, N, _A_, "_A_");

    //===========================================================================
    // 2. Construção da matriz A e do vetor b do sistema sobredeterminado Ax = b
    //    A[i][j] = 2*(Ã_m[j] - Ã_i[j]) para x,y,z
    //    A[i][3] = 2*(Ã_i[3] - Ã_m[3]) para w (sinal invertido)
    //    b[i]    = (x_m² + y_m² + z_m² - w_m²) - (x_i² + y_i² + z_i² - w_i²)

    printf("\n================================================================\n");
    printf("2. Construcao da matriz A e do vetor b do sistema: Ax = b.\n");

    // Matriz A (M x N)
    double A[M][N];

    for (int i = 0; i < M; i++){
        for (int j = 0; j < N-1; j++){
            A[i][j] = 2*(_A_[M][j] - _A_[i][j]);   // x, y, z
        }
        A[i][N-1] = 2*(_A_[i][N-1] - _A_[M][N-1]); // w (sinal invertido)
    }

    imprimir_matriz(M, N, A, "A");

    // Vetor b (M x 1)
    double b[M] = {0};

    // u_m = x_m² + y_m² + z_m² - w_m²
    double um = 0;

    for (int j = 0; j < N-1; j ++){
        um += _A_[M][j]*_A_[M][j];
    }
    um -= _A_[M][N-1]*_A_[M][N-1];

    // b[i] = u_m - u_i
    for (int i = 0; i < M; i++){
        double ui = 0;
        for (int j = 0; j < N-1; j++){
            ui += _A_[i][j]*_A_[i][j];
        }
        ui -= _A_[i][N-1]*_A_[i][N-1];
        b[i] = um - ui;
    }

    imprimir_vetor(M, b, "b");

    //===========================================================================
    // 3. Resolução do sistema por mínimos quadrados via fatoração QR
    //    A = QR => Rx = Q^T b

    printf("\n================================================================\n");
    printf("3. Resolucao do sistema por minimos quadrados (QR).\n");

    // Fatoração QR de A
    double Q[M][N] = {0};
    double R[N][N] = {0};
    
    gram_schmidt(M, N, A, Q, R);

    // Calcula Q^T * b
    double x[N];
    double QTb[N];

    multiplicacao_transposta_vetor(M, N, Q, b, QTb);

    // Resolve o sistema triangular superior Rx = Q^T b
    resolver_sistema_triangular_superior(N, R, QTb, x);

    imprimir_vetor(N, x, "x");

    //===========================================================================
    // 4. Verificação: sqrt(x² + y² + z²) ≈ raio da Terra

    printf("\n================================================================\n");
    printf("4. Constante fisica calculada: raio da Terra.\n");

    double radius = radius_calc(x);

    printf("\nsqrt(x^2 + y^2 + z^2) = %.2lf km\n", radius/1e3);
    printf("Raio da Terra esperado: %.2lf km\n", EARTH_RADIUS);

    //===========================================================================
    // 5. Resíduos do sistema linear e não-linear
    //    r̃ = b - Ax (resíduo linear)
    //    r_i = (x-x_i)² + (y-y_i)² + (z-z_i)² - (w_i-w)² (resíduo não-linear)

    printf("\n================================================================\n");
    printf("5. Residuos.\n");

    // Resíduo linear: r̃ = b - Ax
    printf("\nResiduo linear: r~ = b - Ax\n");

    double Ax[M];

    multiplicar_matriz(M, N, 1, A, (double (*)[1]) x, (double (*)[1]) Ax);

    double r[M];

    soma_matriz(DIFF, M, 1, (double (*)[1]) b, (double (*)[1]) Ax, (double (*)[1]) r);

    // max |r̃_i|, 1 <= i <= M
    double rmax = r[0];

    for (int i = 1; i < M; i ++){
        if (fabs(rmax) < fabs(r[i])){
            rmax = r[i];
        }
    }

    printf("max |r~_i| = %.2lf\n", fabs(rmax));

    // Resíduo não-linear: r_i = (x-x_i)² + (y-y_i)² + (z-z_i)² - (w_i-w)²
    printf("\nResiduo nao-linear: r_i = (x-xi)^2 + (y-yi)^2 + (z-zi)^2 - (wi-w)^2\n");

    // Monta a matriz X - Ã (diferenças entre receptor e satélites)
    double X[_M_][N];

    for (int i = 0; i < _M_; i++){
        for (int j = 0; j < N; j++){
            X[i][j] = x[j];
        }
    }

    double X_A[_M_][N];

    soma_matriz(DIFF, _M_, N, X, _A_, X_A);

    // Calcula r_i para cada satélite
    double r_[_M_];

    for (int i = 0; i < _M_; i++){
        r_[i] = 0;
        for (int j = 0; j < N-1; j++){
            r_[i] += X_A[i][j]*X_A[i][j];
        }
        r_[i] -= X_A[i][N-1]*X_A[i][N-1];
    }

    // max |r_i|, 1 <= i <= m
    double rmax_ = r_[0];

    for (int i = 1; i < _M_; i ++){
        if (fabs(rmax_) < fabs(r_[i])){
            rmax_ = r_[i];
        }
    }

    printf("max |r_i| = %.2lf\n", fabs(rmax_));

    // Justificativa
    printf("\nPor que os residuos nao sao nulos?\n");
    printf(" - Residuo linear: o sistema Ax = b e sobredeterminado (6x4),\n"
       "   logo nao existe x que satisfaca todas as equacoes exatamente.\n"
       "   O metodo dos minimos quadrados minimiza ||r||^2 mas nao o zera.\n"
       " - Residuo nao-linear: a linearizacao (subtracao da equacao m)\n"
       "   e uma aproximacao do sistema original, e os dados de GPS\n"
       "   contem erros de medicao.\n");
       
    //===========================================================================
    // 6. Erro de sincronia T = w/c

    printf("\n================================================================\n");
    printf("6. Calculo do erro de sincronia T = w/c.\n");

    double T = x[3]/c;
    printf("\nT = %.6e s\n", T);

    //===========================================================================
    // 7. Latitude, Longitude e identificação do estádio

    printf("\n================================================================\n");
    printf("7. Calculo da Latitude e Longitude, e determinacao do Estadio.\n");

    double lat_ns, long_we;
    geo_cords(x, &lat_ns, &long_we);

    printf("\nLatitude:  %.6lf graus\nLongitude: %.6lf graus\n", lat_ns, long_we);

    // Identificação do estádio com base no arquivo de entrada (nusp % 4)
    printf("\nEstadio identificado: ");
    switch (nusp % 4){
        case 0:
            printf("MorumBIS\n");
            break;

        case 1:
            printf("Mirassol\n");
            break;

        case 2:
            printf("Portuguesa\n");
            break;

        case 3:
            printf("RedBull Bragantino\n");
            break;
    }

    //===========================================================================
    printf("\n================================================================\n");

    // Libera memória alocada
    free(_A_);

    return 0;
}
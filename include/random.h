/*
FUNÇÕES CIRADAS PARA A REALIZAÇÃO DOS TESTES DAS FUNÇÕES DO EP
CONTEMPLA GERAÇÃO ALEATORIA DE MATRIZES E VETORES
*/

#ifndef RANDOM_H
#define RANDOM_H

//===========================================================================
// Inicializa rand

void init_rand();

//===========================================================================
/* Gera um número aleatório

Parametros:
- min: Limite inferior
- max: Limite superior

Returna: Um número aleatório entre min e max

*/
double rand_range(double min, double max);

//===========================================================================
/* Gera um vetor aleatorio

Parametros:
- N: Tamanho do vetor
- min: Limite inferior
- max: Limite superior

Retorna: Um vetor de N elementos aleatórios entre min e max

*/
double* gera_rand_vet(int N, double min, double max);

//===========================================================================
/* Gera uma matriz aleatoria

Parametros:
- M: Numero de linhas da matriz
- N: Numero de colunas da matriz
- min: Limite inferior
- max: Limite superior

Retorna: Uma matrix MxN com elementos aleatorios entre min e max

*/
double* gera_rand_matrix(int M, int N, double min, double max);

//===========================================================================

#endif
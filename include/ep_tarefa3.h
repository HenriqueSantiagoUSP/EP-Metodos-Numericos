/*
FUNÇÕES DA TAREFA EP_TAREFA3
*/
#ifndef EP_TAREFA3_H
#define EP_TAREFA3_H

//===========================================================================
/* Resolve Sistema trinagular superior

Parametros:
- N: Dimensão da matriz R e tamanho dos vetores b e x
- R: Matriz triangular superior
- b: Vetor independente
- x: Vetor das incógnitas

*/
void resolver_sistema_triangular_superior(int N, double R[N][N], double b[N], double x[N]);

//===========================================================================

#endif
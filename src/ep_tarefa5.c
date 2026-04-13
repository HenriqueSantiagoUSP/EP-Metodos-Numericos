#include "ep_tarefa5.h"
#include <stdio.h>
#include <math.h>

#define G (double)180/3.14159

void ler_dados(int nusp, int M, int N, double A[M][N]){
  /* 
   * Lê o arquivos com os dados dos satélites
   *
   * Entradas:
   * - nusp (int): seu número USP
   * - M (int): número de satélites
   * - N (int): número de dados por satélite
   
   * A (double[M][N]): matriz contendo os dados do satélite
  */

  // Resto da divisão do seu número USP por 4
  int id_arquivo = nusp % 4;

  // Obter nome do arquivo
  char nome_arquivo[256];
  snprintf(nome_arquivo, sizeof(nome_arquivo), RESOURCES_DIR "input_gps_%d.txt", id_arquivo);

  printf("Lendo o arquivo %s\n", nome_arquivo);

  // Testa se o arquivo foi aberto corretamente
  FILE *fp = fopen(nome_arquivo, "r");
  if (fp == NULL){
    perror("Erro ao abrir o arquivo!");
    return;
  }

  // Percorre as linhas do arquivo e guarda as entradas na matriz A
  int linha = 0;
  while (fscanf(fp, "%lf %lf %lf %lf", &A[linha][0], &A[linha][1], &A[linha][2], &A[linha][3]) == 4)
    linha++;

  fclose(fp);
}

// (x, y, z) em latitude e lommgitude

void geo_cords(double x[], double* lat, double* lon){
  *lat = G*atan2(x[2], sqrt(x[0]*x[0] + x[1]*x[1]));
  *lon = G*atan2(x[1], x[0]);
}

#include <stdio.h>

#include "libs.h"

int main (int argc, char *argv[])
{
  int seed, qtd;
  int *arr;
  char nomearquivo[30];


  printf("Da o nome do arquivo, a qtd e a semente ae:\n");
  scanf("%s%d%d", nomearquivo, &qtd, &seed);
  geraArquivo(nomearquivo, qtd, seed);

  arr = leArquivo(nomearquivo);
  arr = countingSort(arr, qtd);

  imprimeVet(arr, qtd);
  return 0;
}

#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "ordenacao.h"


/*
 * O programa itera por todos os arquivos de rand_files
 * executando seu respectivo algoritmo de ordenaçao e salva
 * os vetores ordenado em vetoresOrdenados/nomedoalgoritmo
 * */

int main(){
    char *arq[] = {"../rand_files/100.txt", "../rand_files/1_000.txt", "../rand_files/10_000.txt", "../rand_files/100_000.txt", "../rand_files/1_000_000.txt"};
    char *vets[] = {"../vetoresOrdenados/quick/100Ord.txt", "../vetoresOrdenados/quick/1_000Ord.txt", "../vetoresOrdenados/quick/10_000Ord.txt", "../vetoresOrdenados/quick/100_000Ord.txt", "../vetoresOrdenados/quick/1_000_000Ord.txt"};
    int Tamanho;
    int trc;
    int cmp;
    trc = cmp = 0;
    FILE *f = fopen("../stats/quick_stats.txt", "a+");
    if(f == NULL)
      return -1;

printf("QuickSort\n-------------------\nSorting...");
// executando quick para todos os arquivos de rand_files
    for(int i = 0; i < 5; i++){
      int *v = leArquivo(arq[i], &Tamanho);
      fprintf(f, "%d elementos\n", (int) pow(10, (2 + i)));
      quick(v, 0, Tamanho-1, Tamanho, &trc, &cmp);
      imprimeArquivo(vets[i],(int) pow(10, (2+i)), v);
      fprintf(f,"Trocas: %d\n", trc);
      fprintf(f, "Comparações: %d\n", cmp);
      trc = cmp = 0;
    }


fclose(f);
return 0;
}

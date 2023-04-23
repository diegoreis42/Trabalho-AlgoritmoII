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
    char *arq[]  = {"../rand_files/100.txt", "../rand_files/1_000.txt", "../rand_files/10_000.txt", "../rand_files/100_000.txt", "../rand_files/1_000_000.txt"};
    char *vets[] = {"../vetoresOrdenados/merge/100Ord.txt", "../vetoresOrdenados/merge/1_000Ord.txt", "../vetoresOrdenados/merge/10_000Ord.txt", "../vetoresOrdenados/merge/100_000Ord.txt", "../vetoresOrdenados/merge/1_000_000Ord.txt"};
    int Tamanho;
    int trc;
    int cmp;
    trc = cmp = 0;
    FILE *m = fopen("../stats/merge_stats.txt", "a+");
    if(m == NULL)
      return -1;

printf("MergeSort\n-------------------\nSorting...");
// executando merge para todos os arquivos de rand_files
    for(int i = 0; i < 5; i++){
      int *v = leArquivo(arq[i], &Tamanho);
      mergesort(v,0, Tamanho,&trc, &cmp);
      imprimeArquivo(vets[i],(int) pow(10, (2+i)), v);
      // pow(10, (2 + i)) eh uma gambiarra para o tam do vetor ser igual ao numero de elementos do respectivo arquivo
      fprintf(m, "%d elementos\n", (int) pow(10, (2 + i)));
      fprintf(m,"Trocas: %d\n", trc);
      fprintf(m, "Comparações: %d\n", cmp);
      trc = cmp = 0;

    }

fclose(m);
return 0;
}

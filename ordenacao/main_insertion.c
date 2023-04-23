#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "ordenacao.h"



int main(){
    char *arq[] = {"../rand_files/100.txt", "../rand_files/1_000.txt", "../rand_files/10_000.txt", "../rand_files/100_000.txt", "../rand_files/1_000_000.txt"};
    char *vets[] = {"../vetoresOrdenados/insertion/100Ord.txt", "../vetoresOrdenados/insertion/1_000Ord.txt", "../vetoresOrdenados/insertion/10_000Ord.txt", "../vetoresOrdenados/insertion/100_000Ord.txt", "../vetoresOrdenados/insertion/1_000_000Ord.txt"};
    int Tamanho;
    int trc;
    int cmp;
    trc = cmp = 0;
    FILE *f = fopen("../stats/insertion_stats.txt", "a+");
    if(f == NULL)
      return -1;

printf("InsertionSort\n-------------------\nSorting...");
// executando insertion para todos os arquivos de rand_files
    for(int i = 0; i < 5; i++){
      int *v = leArquivo(arq[i], &Tamanho);
      insertionsort(v, pow(10, (2 + i)),&trc, &cmp);
      imprimeArquivo(vets[i],(int) pow(10, (2+i)), v);
      fprintf(f, "%d elementos\n", (int) pow(10, (2 + i)));
      fprintf(f,"Trocas: %d\n", trc);
      fprintf(f, "Comparações: %d\n", cmp);
      trc = cmp = 0;
    }

return 0;
}

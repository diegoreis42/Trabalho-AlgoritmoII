#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include <math.h>
#include "ordenacao.h"



int main(){
    char *arq[] = {"../rand_files/100.txt", "../rand_files/1_000.txt", "../rand_files/10_000.txt", "../rand_files/100_000.txt", "../rand_files/1_000_000.txt"};
    int Tamanho;
    int trc;
    int cmp;
    trc = cmp = 0;
    FILE *f = fopen("quick_stats.txt", "a+");
    FILE *m = fopen("merge_stats.txt", "a+");

    for(int i = 0; i < 5; i++){
      int *v = leArquivo(arq[i], &Tamanho);
      fprintf(f, "%d elementos\n", (int) pow(10, (2 + i)));
      quick(v, 0, Tamanho-1, Tamanho, &trc, &cmp);
      fprintf(f,"Trocas: %d\n", trc);
      fprintf(f, "Comparações: %d\n", cmp);
      trc = cmp = 0;
    }

    for(int i = 0; i < 5; i++){
      int *v = leArquivo(arq[i], &Tamanho);
      mergesort(v,0, pow(10, (2 + i)),&trc, &cmp);
      fprintf(m, "%d elementos\n", (int) pow(10, (2 + i)));
      fprintf(m,"Trocas: %d\n", trc);
      fprintf(m, "Comparações: %d\n", cmp);
      trc = cmp = 0;

    }

fclose(f);
fclose(m);
return 0;
}

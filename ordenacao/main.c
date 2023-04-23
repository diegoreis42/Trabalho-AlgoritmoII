#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ordenacao.h"



int main(){
    char arq[] = "teste.txt";
    int Tamanho;
    int *v = leArquivo(arq, &Tamanho);
    int trc;
    int cmp;
    trc = cmp = 0;
    quick(v, 0, Tamanho-1, Tamanho, &trc, &cmp);
    printf("Trocas: %d\n", trc);
    printf("Comparações: %d", cmp);

}
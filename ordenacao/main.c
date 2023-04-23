#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ordenacao.h"

#define Tamanho 10000

int main(){
    int *v=randVector(Tamanho);
    int trc;
    int cmp;
    trc = cmp = 0;
    quick(v, 0, Tamanho-1, Tamanho, &trc, &cmp);
    printf("Trocas: %d\n", trc);
    printf("Comparações: %d", cmp);
}
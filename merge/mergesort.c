#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

struct tVet{
    int *vet;
    int tam;
};

void mergesort(int *v, int inicio, int fim, int *trc, int *cmp)
{
    if (inicio < fim)
    {
        int meio = (inicio + fim) / 2;
        mergesort(v, inicio, meio, trc, cmp);
        mergesort(v, meio + 1, fim, trc, cmp);
        merge(v, inicio, meio, fim,trc,cmp);
    }
}

void merge(int *v, int inicio, int meio, int fim, int *trc, int *cmp)
{
    int tam = fim - inicio + 1;
    int *vetAux = (int *) malloc(tam * sizeof(int));
    int i,j,k;
    for (i = inicio; i <= fim; i++)
        vetAux[i - inicio] = v[i];
    i = 0;
    j = meio - inicio + 1;
    k = inicio;
    while (i <= meio - inicio && j <= fim - inicio)
    {
        cmp += 1;
        if (vetAux[i] <= vetAux[j])
        {
            v[k] = vetAux[i];
            i++;
        }
        else
        {
            v[k] = vetAux[j];
            j++;
        }
        k++;
    }
    while (i <= meio - inicio)
    {
        v[k] = vetAux[i];
        i++;
        k++;
    }
    while (j <= fim - inicio)
    {
        v[k] = vetAux[j];
        j++;
        k++;
    }
    free(vetAux);
}
//Função recursiva que executa a fase de divisão do algoritmo mergesort

void imprimeVet(int *v, int tam){
    for(int i=0;i<tam;i++)printf("%d ", v[i]);
}
//Função que imprime um vetor
//printf("%d ", vet[i])

tVet * leArquivo(char *nomeArquivo){
    tVet *arquivo=(tVet*) malloc(sizeof(tVet*));
    FILE *f=fopen(nomeArquivo,"r");
    if(f!=NULL){
        int i=0;
        int tam;
        fscanf(f,"%d",&tam);
        int *v=(int*) malloc(sizeof(int)*tam);
        do{
            fscanf(f,"%d",&v[i]);
            i++;
        }while(i>0);
        arquivo->vet=v;
        arquivo->tam=tam;
        return arquivo;
    }else{
        arquivo->vet=NULL;
        arquivo->tam=0;
        return arquivo;
    }
}
//Função que lê os dados de um arquivo e carrega em um vetor de inteiros
//Retorna o tipo tVet, composto por um vetor de inteiros e o tamanho do vetor
//A primeira linha do arquivo possui o tamanho do vetor

int getVetTam(tVet *res){
    return res->tam;
}
//Função que retorna o tamanho do vetor

int *getVet(tVet *res){
    return res->vet;
}
//Função que retorna o vetor
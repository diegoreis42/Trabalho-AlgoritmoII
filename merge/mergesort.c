#include <stdlib.h>
#include <stdio.h>
#include "mergesort.h"

struct tVet{
    int *vet;
    int tam;
};

void merge(int *v, int inicio, int meio, int fim){
    int marcadorV1=inicio; // controla as posições do vetor lógico 1
    int marcadorV2=meio; // controla as posições do vetor lógico 2
    int vetAux[(fim-inicio)+1];
    int i=0; // contador do vetor auxiliar
    int k; // contador de vet para cópia final
    while(marcadorV1<=meio&&marcadorV2<=fim){
        if(v[marcadorV1]<v[marcadorV2]){
            vetAux[i]=v[marcadorV1];
            marcadorV1++;
        }else{
            vetAux[i]=v[marcadorV2];
            marcadorV2++;
        }
        i++;
    }
    // Copia o resto do vetor 1 ou o resto do vetor 2 para o vetor auxiliar
    // Copia o vetor auxiliar para o vetor original
}
//Função que faz a fusão de dois vetores pré-ordenados e os copia para o vetor original

void mergesort(int *v, int inicio, int fim){
    int meio;
    if(inicio<fim){
        meio=(inicio+fim)/2;
        mergesort(v,inicio,meio);
        mergesort(v,meio+1,fim);
        merge(v,inicio,meio,fim);
    }
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
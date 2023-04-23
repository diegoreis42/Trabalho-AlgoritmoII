#include <stdlib.h>
#include <stdio.h>
#include <time.h>
#include "ordenacao.h"

int *insertionsort(int *v, int tamanho, int *trc, int *cmp){
    int marcador;
    int aux;
    int pos;
    for(marcador=1;marcador<tamanho;marcador++){
    // percorre todo o vetor a partir da segunda posição
        pos=marcador-1;
        // a posição a ser ordenada encontra-se logo atrás do marcador
        aux=v[marcador];
        while(aux<v[pos]&&pos>=0){
        // até que o auxiliar supere 
            cmp += 1;
            v[pos+1]=v[pos];
            pos=pos-1;
        }
        v[pos+1]=aux;
    }
    return v;
}

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

int mediana(int a, int b, int c)
{
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return b;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return a;
    } else {
        return c;
    }
}

void quick(int *v, int esq, int dir, int tam, int *trc, int *cmp)
{
    //a condição de parada é o tamanho ser um, já que já está ordenado
    if(tam > 1)
    {
        int meio = (esq + dir) / 2;
        int pv = mediana(v[esq], v[meio], v[dir]);
        int i, j;  
        i = esq;
        j = dir;     
        int aux;

        while(i <= j) //os marcadores não podem se inverter, i deve ficar antes de j
        {
            while (v[i] < pv)//acha o valor de indice i que deve ter seu lado trocado em relaçãoo ao pivo
                {
                    i++;    
                    *cmp += 1;
                } 
                while (v[j] > pv)//faz o mesmo com j
                {
                    j--;
                    *cmp += 1;
                }
                    if(i <= j) //se as condições do loop mais externo ainda forem cumpridas
                    {
                        aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                        i++;
                        j--;
                        *trc += 1;
                        //troca os dois elementos de lugar e passa para o valor do proximo indice
                    }
        }

        quick(v,esq,j, j - esq + 1, trc, cmp); //chama a função recursivamente para a direita
        quick(v,i, dir, dir - i + 1, trc, cmp); //chama a função recursivamente para a esquerda
    }
}

int *leArquivo(char *nomeArquivo, int *Tamanho) {
    FILE *arq;
    int *vet = NULL; // Inicialmente, o vetor está vazio
    int num, i = 0;

    arq = fopen(nomeArquivo, "r");
    if (arq == NULL) {
        printf("Erro ao abrir o arquivo.\n");
        return NULL;
    }

    // Lê números do arquivo um a um e aloca espaço dinamicamente
    while (fscanf(arq, "%d", &num) == 1) {
        vet = (int*) realloc(vet, (i+1) * sizeof(int));
        vet[i] = num;
        i++;
    }

    fclose(arq);

    if (i == 0) { // Se não foi lido nenhum número, retorna NULL
        free(vet);
        return NULL;
    }

    // Retorna o tamanho do vetor e o vetor alocado dinamicamente
    *Tamanho = i;
    return vet;
}

int *randVector(int tamanho){
    int j;
    srand(time(NULL));
    int *v=(int*) malloc(sizeof(int)*tamanho);
    // aloca o vetor com tamanho recebido como parâmetro
    // for(int i=0;i<tamanho;i++)v[i]=rand()%tamanho;
    // para fazer repetidos, incluir a instrução acima e excluir abaixo.
    for(int i=0;i<tamanho;i++)v[i]=-1;
    // preenche o vetor com -1
    for(int i=0;i<tamanho;i++){
        j=rand()%tamanho;
        while(v[j]!=-1){
            if(j<tamanho){
                j++;
            }else{ // se alcançou o final
                j=0; // volta ao inicio
            }
        }
        v[j]=i;
    }
    return v;
}

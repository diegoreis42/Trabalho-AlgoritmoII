#include <stdlib.h>
#include <stdio.h>
#include <time.h>

#define Tamanho 10

int *randVector(int tamanho);

int *insertionsort(int *v, int tamanho, int *trc, int *cmp);

int main(){
    int *v=randVector(Tamanho);
    for(int i=0;i<Tamanho;i++)printf("%d ", v[i]);
    v=insertionsort(v,Tamanho);
    printf("\n\n");
    for(int i=0;i<Tamanho;i++)printf("%d ", v[i]);
}

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

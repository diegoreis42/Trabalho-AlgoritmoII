#include <stdio.h>
#include <stdlib.h>

int mediana(int a, int b, int c) {
    if ((a <= b && b <= c) || (c <= b && b <= a)) {
        return b;
    } else if ((b <= a && a <= c) || (c <= a && a <= b)) {
        return a;
    } else {
        return c;
    }
}

void quick(int *v, int esq, int dir, int tam)
{
    if(tam > 1)
    {
        int meio = (esq + dir) / 2;
        int pv = mediana(v[esq], v[meio], v[dir]);
        int i, j;  
        i = esq;
        j = dir;     
        int aux;

        while(i <= j)
        {
            while (v[i] < pv) i++;
                while (v[j] > pv) j--;
                    if(i <= j)
                    {
                        aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                        i++;
                        j--;
                    }
        }

        quick(v,esq,j, j - esq + 1);
        quick(v,i, dir, dir - i + 1);
    }
}

int main()
{
    FILE *arq;
    int *vet;
    int i, qtd;
    char nomeArquivo[] = "teste.txt";

    arq = fopen(nomeArquivo, "r");
    fscanf(arq, "%d", &qtd);
    vet = (int*) malloc(qtd * sizeof(int));

    for (i = 0; i < qtd; i++)
        fscanf(arq, "%d", &vet[i]);
    for (i = 0; i < qtd; i++)
        printf("%d ", vet[i]);
    printf("\n");
    fclose(arq);

    quick(vet, 0, qtd-1, qtd);

    for (i = 0; i < qtd; i++)
        printf("%d ", vet[i]);
    
    return 0;
}
#include <stdio.h>
#include <stdlib.h>
//calcula a mediana para tornar o código mais eficiente, levando a mediana para o meio
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

void quick(int *v, int esq, int dir, int tam)
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
            while (v[i] < pv) i++; //acha o valor de indice i que deve ter seu lado trocado em relaçãoo ao pivo
                while (v[j] > pv) j--; //faz o mesmo com j
                    if(i <= j) //se as condições do loop mais externo ainda forem cumpridas
                    {
                        aux = v[i];
                        v[i] = v[j];
                        v[j] = aux;
                        i++;
                        j--;
                        //troca os dois elementos de lugar e passa para o valor do proximo indice
                    }
        }

        quick(v,esq,j, j - esq + 1); //chama a função recursivamente para a direita
        quick(v,i, dir, dir - i + 1); //chama a função recursivamente para a esquerda
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
    printf("\n");
    return 0;
}
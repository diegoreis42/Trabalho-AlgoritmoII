#include <stdlib.h>
#include <stdio.h>



int geraArquivo(char *nomeSaida, int qtd, int semente){

srand(semente);
FILE *fptr;

fptr = fopen(nomeSaida, "w");
if(fptr == NULL)
  return -1;


fprintf(fptr, "%d\n", qtd);

for(int i = 0; i < qtd; i++){
  fprintf(fptr, "%d\n", rand() % qtd + 1);
}

fclose(fptr);
return 1;

}

void imprimeVet(int *vet, int tam){
  for(int i = 0; i < tam; i++){
    printf("%d-", vet[i]);
  }
  printf("\n");
}

void liberaVetor(int *vet){
  free(vet);
}


int *leArquivo(char *nomeEntrada){

  int *qtd, *aux;


  FILE *fptr = fopen(nomeEntrada, "r");

  fscanf(fptr, "%d", qtd);
  int *random_numbers = (int*) malloc(sizeof(int) * (*qtd));

  for(int i = 0; i < (*qtd); i++){
    fscanf(fptr, "%d", aux);
    random_numbers[i] = (*aux);
  }

return random_numbers;
}

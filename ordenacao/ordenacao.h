
// algortimos de ordenaçao
int *insertionsort(int *v, int tamanho, int *trc, int *cmp);
void mergesort(int *v, int inicio, int fim, int *trc, int *cmp);
void merge(int *v, int inicio, int meio, int fim, int *trc, int *cmp);
void quick(int *v, int esq, int dir, int tam, int *trc, int *cmp);
void countSort(int arr[], int n, int *trc, int *cmp);

int mediana(int a, int b, int c);
// manipulaçao de arquivos
int imprimeArquivo(char *nomeSaida, int qtd, int *vet);
int *leArquivo(char *nomeArquivo, int *Tamanho);

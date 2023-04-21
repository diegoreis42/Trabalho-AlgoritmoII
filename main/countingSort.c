#include <stdio.h>
#include <stdlib.h>

void countSort(int arr[], int n) {
    int i, j, max = arr[0], *count_arr, *sorted_arr;

    // acha o maior elemento do vetor
    for (i = 1; i < n; i++) {
        if (arr[i] > max) {
            max = arr[i];
        }
    }


    count_arr = (int *)calloc(max + 1, sizeof(int));
    sorted_arr = (int *)malloc(n * sizeof(int));

    // guarda a quantidade de cada elemento
    for (i = 0; i < n; i++) {
        count_arr[arr[i]]++;
    }

    // acha a posiçao correta de cada elemento
    for (i = 1; i <= max; i++) {
        count_arr[i] += count_arr[i-1];
    }

    // Cria o array ordenado
    for (i = n-1; i >= 0; i--) {
        sorted_arr[count_arr[arr[i]]-1] = arr[i];
        count_arr[arr[i]]--;
    }

    // Copia o array ordenado para o vetor original
    for (i = 0; i < n; i++) {
        arr[i] = sorted_arr[i];
    }


    free(count_arr);
    free(sorted_arr);
}

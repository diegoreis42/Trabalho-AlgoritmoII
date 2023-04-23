#include <stdlib.h>

void merge(int arr[], int left[], int leftSize, int right[], int rightSize) {
    int i = 0, j = 0, k = 0;

    while (i < leftSize && j < rightSize) {
        if (left[i] <= right[j]) {
            arr[k] = left[i];
            i++;
        }
        else {
            arr[k] = right[j];
            j++;
        }
        k++;
    }

    while (i < leftSize) {
        arr[k] = left[i];
        i++;
        k++;
    }

    while (j < rightSize) {
        arr[k] = right[j];
        j++;
        k++;
    }
}

void mergesort(int arr[], int size) {
    if (size < 2)
        return;

    int mid = size / 2;

    int *left = (int *) malloc(mid * sizeof(int));
    int *right = (int *) malloc((size - mid) * sizeof(int));

    for (int i = 0; i < mid; i++)
        left[i] = arr[i];

    for (int i = mid; i < size; i++)
        right[i - mid] = arr[i];

    mergesort(left, mid);
    mergesort(right, size - mid);

    merge(arr, left, mid, right, size - mid);

    free(left);
    free(right);
}

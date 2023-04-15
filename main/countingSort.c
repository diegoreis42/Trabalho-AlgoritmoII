#include <stdlib.h>



void countingSort(int arr[], int n, int k) {
    int count[k+1];     for(int i=0; i<=k; i++) {
        count[i] = 0;
    }
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }
    for(int i=1; i<=k; i++) {
        count[i] += count[i-1];
    }
    int output[n];
    for(int i=n-1; i>=0; i--) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    for(int i=0; i<n; i++) {
        arr[i] = output[i];
    }
}

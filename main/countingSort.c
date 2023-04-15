#include <stdlib.h>



void countingSort(int arr[], int n, int k) {
    int count[k+1]; // create count array with size k+1 and initialize with 0
    for(int i=0; i<=k; i++) {
        count[i] = 0;
    }
    // count the frequency of each element in the input array
    for(int i=0; i<n; i++) {
        count[arr[i]]++;
    }
    // calculate the cumulative sum of the count array
    for(int i=1; i<=k; i++) {
        count[i] += count[i-1];
    }
    // create a temporary output array and fill it with the sorted elements
    int output[n];
    for(int i=n-1; i>=0; i--) {
        output[count[arr[i]]-1] = arr[i];
        count[arr[i]]--;
    }
    // copy the sorted elements from the output array back to the input array
    for(int i=0; i<n; i++) {
        arr[i] = output[i];
    }
}

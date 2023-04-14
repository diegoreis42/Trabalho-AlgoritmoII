#include <stdlib.h>



int *countingSort(int *array, int k){
  int j;
  int *count = (int*) calloc(k + 1, sizeof(int));
  int *output = (int*) calloc(sizeof(array), sizeof(int));

  for(int i = 0; array[i]; ++i){
    ++count[array[i]];
  }

  for(int i = 1; i < k; i++){
    count[i] += count[i - 1];
  }

  for(int i = 0; array[i]; i++){
    output[count[array[i]] - 1] = array[i];
    --count[array[i]];
  }

  free(count);
  return output;
}

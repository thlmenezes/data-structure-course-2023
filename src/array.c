#include "array.h"
#include <stdlib.h>

Array* array_create(int size){
  Array* new_array = malloc(sizeof(Array));
  new_array->size = size;
  new_array->data = malloc(size*sizeof(int));
  return new_array;
}

int array_length(Array* arr){
  return arr->size;
}

void array_free(Array* arr){
  free(arr);
}

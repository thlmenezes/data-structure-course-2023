#include "array.h"
#include <stdlib.h>
#include <string.h>

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

void array_fill(Array* arr, int value){
  for(int i=0; i<arr->size; i++) {
     arr->data[i] = value;
  }
}

Array* array_clone(Array* array){
  Array* new_array = array_create(array->size);
  // Copiar conteúdo
  memcpy(
    new_array->data,
    array->data,
    new_array->size*sizeof(int)
  );
  return new_array;
}

// char* array_to_s(Array* arr){
//   
// }


#include "array.h"
#include <stdlib.h>

Array* create_array(int size){
  Array* new_array = malloc(sizeof(Array));
  new_array->size = size;
  new_array->data = malloc(size*sizeof(int));
  return new_array;
}

#include <stdio.h>
#include "array.h"

int main(){
  Array* list = array_create(5);
  printf("%d\n", array_length(list));
  Array* clone = array_clone(list);
  array_free(list);
  printf("%d\n", array_length(clone));
  array_free(clone);
  return 0;
}

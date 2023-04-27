#include <stdio.h>
#include "array.h"

int main(){
  Array* list = array_create(5);
  printf("%d\n", array_length(list));
  array_free(list);
  return 0;
}

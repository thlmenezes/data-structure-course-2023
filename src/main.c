#include <stdio.h>
#include "array.h"

int main(){
  Array* list = create_array(5);
  printf("%d\n", length(list));
  free_array(list);
  return 0;
}

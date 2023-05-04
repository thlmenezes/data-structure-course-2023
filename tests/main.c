#include <assert.h>
#include "../src/array.h"

int check_array_length(void) {
  Array *list = array_create(5);
  assert(array_length(list) == 5);
  array_free(list);
  return 0;
}

int main(void){
  check_array_length();
  return 0;
}

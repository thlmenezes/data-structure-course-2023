#include "../src/array.h"
#include "../src/list.h"
#include <assert.h>
#include <stdlib.h>

int check_array_length(void) {
  Array *list = array_create(5);
  assert(array_length(list) == 5);
  array_free(list);
  return 0;
}

int check_list_create(void) {
  List *list = list_create();
  assert(list != NULL);
  assert(list->head == NULL);
  list_free(list);
  return 0;
}

int main(void) {
  check_array_length();
  check_list_create();
  return 0;
}

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

int check_list_emplace_on_empty_list(void) {
  List *list = list_create();
  list_emplace_element(list, 10, 1);
  assert(list->head->data == 10);
  list_free(list);
  return 0;
}

int check_list_emplace_twice_on_list(void) {
  List *list = list_create();
  list_emplace_element(list, 10, 1);
  assert(list->head->data == 10);
  list_emplace_element(list, 20, 1);
  assert(list->head->data == 10);
  assert(list->head->next->data == 20);
  list_free(list);
  return 0;
}

int check_list_get_element(void) {
  List *list = list_create();
  assert(list_get_element(list, 10) == -1);
  list_emplace_element(list, 10, 1);
  assert(list_get_element(list, 0) == 10);
  list_emplace_element(list, 20, 1);
  assert(list_get_element(list, 0) == 10);
  assert(list_get_element(list, 1) == 20);
  list_free(list);
  return 0;
}

int check_list_clear_on_empty_list(void) {
  List *list = list_create();
  list_clear(list);
  list_free(list);
  return 0;
}

int check_list_clear_on_unitary_list(void) {
  List *list = list_create();
  list_emplace_element(list, 10, 1);
  list_clear(list);
  assert(list->head == NULL);
  list_free(list);
  return 0;
}

int check_list_is_empty(void) {
  List *list = list_create();
  assert(list_is_empty(list));
  list_emplace_element(list, 10, 1);
  assert(!list_is_empty(list));
  list_free(list);
  return 0;
}

int main(void) {
  check_array_length();
  check_list_create();
  check_list_emplace_on_empty_list();
  check_list_emplace_twice_on_list();
  check_list_clear_on_empty_list();
  check_list_clear_on_unitary_list();
  check_list_get_element();
  check_list_is_empty();
  return 0;
}

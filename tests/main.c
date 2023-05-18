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

int check_list_length(void) {
  List *list = list_create();
  assert(list_length(list) == 0);
  list_emplace_element(list, 10, 1);
  assert(list_length(list) == 1);
  list_emplace_element(list, 10, 1);
  list_emplace_element(list, 10, 1);
  list_emplace_element(list, 10, 1);
  list_emplace_element(list, 10, 1);
  list_emplace_element(list, 10, 1);
  assert(list_length(list) == 6);
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

int check_list_remove_element(void) {
  List *list = list_create();        // []
  list_emplace_element(list, 10, 1); // [10]
  list_emplace_element(list, 20, 1); // [10, 20]
  list_emplace_element(list, 30, 1); // [10, 30, 20]
  list_emplace_element(list, 40, 1); // [10, 40, 30, 20]
  list_emplace_element(list, 50, 1); // [10, 50, 40, 30, 20]
  list_emplace_element(list, 42, 1); // [10, 42, 50, 40, 30, 20]
  assert(list_length(list) == 6);
  list_remove_element(list, 1); // [10, 50, 40, 30, 20]
  assert(list_length(list) == 5);
  assert(list_get_element(list, 1) == 50);
  list_free(list);
  return 0;
}

int check_list_pop_element(void) {
  List *list = list_create();        // []
  list_emplace_element(list, 10, 1); // [10]
  list_emplace_element(list, 20, 1); // [10, 20]
  list_emplace_element(list, 30, 1); // [10, 30, 20]
  list_emplace_element(list, 40, 1); // [10, 40, 30, 20]
  list_emplace_element(list, 50, 1); // [10, 50, 40, 30, 20]
  list_emplace_element(list, 42, 1); // [10, 42, 50, 40, 30, 20]
  assert(list_pop_element(list, 1) == 42);
  assert(list_pop_element(list, 4) == 20);
  list_free(list);
  return 0;
}

int main(void) {
  check_array_length();
  check_list_create();
  check_list_length();
  check_list_emplace_on_empty_list();
  check_list_emplace_twice_on_list();
  check_list_clear_on_empty_list();
  check_list_clear_on_unitary_list();
  check_list_get_element();
  check_list_is_empty();
  check_list_remove_element();
  check_list_pop_element();
  return 0;
}

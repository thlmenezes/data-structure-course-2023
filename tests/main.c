#include "../src/array.h"
#include "../src/list.h"
#include "../src/queue.h"
#include "../src/stack.h"
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

int check_list_emplace_head(void) {
  List *list = list_create();         // []
  list_emplace_element(list, 100, 0); // [100]
  list_emplace_element(list, 1, 0);   // [1, 100]
  assert(list_get_element(list, 0) == 1);
  list_free(list);
  return 0;
}

int check_stack(void) {
  Stack *stack = stack_create();
  stack_push(stack, 1); // [1]
  stack_push(stack, 2); // [2,1]
  stack_push(stack, 3); // [3,2,1]
  stack_push(stack, 4); // [4,3,2,1]
  assert(stack_top(stack) == 4);
  assert(stack_pop(stack) == 4);
  assert(stack_pop(stack) == 3);
  assert(stack_pop(stack) == 2);
  assert(stack_pop(stack) == 1);
  stack_free(stack);
  return 0;
}

int check_queue(void) {
  Queue *queue = queue_create();
  enqueue(queue, 1); // [1]
  enqueue(queue, 2); // [2,1]
  enqueue(queue, 3); // [3,2,1]
  enqueue(queue, 4); // [4,3,2,1]
  assert(queue_front(queue) == 1);
  assert(queue_back(queue) == 4);
  assert(dequeue(queue) == 1);
  assert(dequeue(queue) == 2);
  assert(dequeue(queue) == 3);
  assert(dequeue(queue) == 4);
  queue_free(queue);
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
  check_list_emplace_head();
  check_stack();
  check_queue();
  return 0;
}

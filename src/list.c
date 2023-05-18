#include "list.h"
#include <stdlib.h>

List *list_create() {
  List *list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

void list_emplace_element(List *list, int data, int position) {
  Node *node = malloc(sizeof(Node));
  node->data = data;
  list->head = node;
}

void list_free(List *list) { free(list); }

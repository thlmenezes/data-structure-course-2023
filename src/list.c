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
  node->next = NULL;
  list->head = node;
}

void list_clear_node(Node *node) {
  if (node == NULL) {
    return;
  }
  list_clear_node(node->next);
  free(node);
}

void list_clear(List *list) {
  list_clear_node(list->head);
  list->head = NULL;
}

void list_free(List *list) {
  list_clear(list);
  free(list);
}

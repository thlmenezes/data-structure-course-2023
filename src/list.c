#include "list.h"
#include <stdlib.h>

List *list_create() {
  List *list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

int list_length_node(Node *node) {
  if (node == NULL) {
    return 0;
  }
  return 1 + list_length_node(node->next);
}

int list_length(List *list) { return list_length_node(list->head); }

int list_is_empty(List *list) { return list->head == NULL; }

int list_get_element(List *list, int position) {
  Node *target = list->head;
  for (; target != NULL && position > 0; position--) {
    target = target->next;
  }
  if (target != NULL) {
    return target->data;
  }
  return -1;
}

void list_emplace_element(List *list, int data, int position) {
  Node *target = list->head;
  for (; target != NULL && target->next != NULL && position > 1; position--) {
    target = target->next;
  }
  Node *node = malloc(sizeof(Node));
  node->data = data;
  if (target != NULL && position == 0) {
    node->next = list->head;
    list->head = node;
  } else if (target != NULL) {
    node->next = target->next;
    target->next = node;
  } else {
    node->next = NULL;
    list->head = node;
  }
}

int list_pop_element(List *list, int position) {
  Node *target = list->head;
  for (; target != NULL && target->next != NULL && position > 1; position--) {
    target = target->next;
  }
  Node *remove;
  if (position == 0) {
    remove = target;
    list->head = remove->next;
  } else {
    remove = target->next;
    target->next = remove->next;
  }
  int data = remove->data;
  free(remove);
  return data;
}

void list_remove_element(List *list, int position) {
  list_pop_element(list, position);
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

char *list_to_s(List *list){
  char[list_length(list) + 1] texto;
  for (int i = 0; i < list_length(list); i++) {
    texto[i] = node->data[i];
  }
  texto[list_length + 1] = '000/';
  return texto;
}

List *list_clone(List *list){
  int list_length = list_length(list);
  List* list_clone = list_create();
  for (i = 0 ;i < list_length;i++){
    list_emplace_element(list, list{list_length}, i);
  }
  return list_clone;
}

void list_fill(List *list, int value){
  int list_length = list_length(list);
  for(int i = 0;  i < list_length;i++){
    node->data[i] = value;
  }
}
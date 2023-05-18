#ifndef LIST_H_
#define LIST_H_

typedef struct Node {
  int data;
  struct Node *next;
} Node;

typedef struct {
  Node *head;
} List;
/**
 * Instantiates a new linked list
 */
List *list_create();
int list_length(List *);
void list_clear(List *);
int list_is_empty(List *);
void list_emplace_element(List *, int, int);
void list_remove_element(List *, int);
void list_free(List *);
// TODO1: implement string repr of array for printf
// char *list_to_s(List *);
// List *list_clone(List *);
// void list_fill(List *, int);
#endif

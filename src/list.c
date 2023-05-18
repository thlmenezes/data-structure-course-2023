#include "list.h"
#include <stdlib.h>

List *list_create() {
  List *list = malloc(sizeof(List));
  list->head = NULL;
  return list;
}

void list_free(List *list) {}

#ifndef STACK_H_
#define STACK_H_
#include "list.h"

typedef List Stack;
/**
 * Instantiates a new linked stack
 */
Stack *stack_create();
int stack_length(Stack *);
void stack_clear(Stack *);
int stack_is_empty(Stack *);
void stack_push(Stack *, int);
int stack_pop(Stack *);
int stack_top(Stack *);
void stack_free(Stack *);
// TODO1: implement string repr of array for printf
 char *stack_to_s(Stack *);
 Stack *stack_clone(Stack *);
 void stack_fill(Stack *, int);
#endif

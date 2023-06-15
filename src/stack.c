#include "stack.h"

Stack *stack_create() { return list_create(); }
int stack_length(Stack *stack) { return list_length(stack); }
int stack_is_empty(Stack *stack) { return list_is_empty(stack); }
void stack_push(Stack *stack, int data) {
  list_emplace_element(stack, data, 0);
}
int stack_pop(Stack *stack) { return list_pop_element(stack, 0); }
int stack_top(Stack *stack) { return list_get_element(stack, 0); }
void stack_clear(Stack *stack) { list_clear(stack); }
void stack_free(Stack *stack) { list_free(stack); }
char *stack_to_s(Stack *) {return list_to_s(stack);}
Stack *stack_clone(Stack *) {list_clone(stack);}
void stack_fill(Stack *, int) {list_fill(stack, int);}
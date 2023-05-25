#include "queue.h"

Queue *queue_create() { return list_create(); }
int queue_length(Queue *queue) { return list_length(queue); }
int queue_is_empty(Queue *queue) { return list_is_empty(queue); }
void enqueue(Queue *queue, int data) { list_emplace_element(queue, data, 0); }
int dequeue(Queue *queue) {
  return list_pop_element(queue, queue_length(queue) - 1);
}
int queue_front(Queue *queue) {
  return list_get_element(queue, queue_length(queue) - 1);
}
int queue_back(Queue *queue) { return list_get_element(queue, 0); }
void queue_clear(Queue *queue) { list_clear(queue); }
void queue_free(Queue *queue) { list_free(queue); }

#ifndef QUEUE_H_
#define QUEUE_H_
#include "list.h"

typedef List Queue;
/**
 * Instantiates a new linked queue
 */
Queue *queue_create();
int queue_length(Queue *);
void queue_clear(Queue *);
int queue_is_empty(Queue *);
void enqueue(Queue *, int);
int dequeue(Queue *);
int queue_front(Queue *);
int queue_back(Queue *);
void queue_free(Queue *);
// TODO1: implement string repr of array for printf
// char *queue_to_s(Queue *);
// Queue *queue_clone(Queue *);
// void queue_fill(Queue *, int);
#endif

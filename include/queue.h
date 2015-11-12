#ifndef DFSA_SIMULATOR_INCLUDE_QUEUE_H_
#define DFSA_SIMULATOR_INCLUDE_QUEUE_H_ 1

#include <stdlib.h>

typedef struct queue
{
	struct node *head;
	struct node *tail;
} Queue;

Queue* newQueue();

void enqueue(char *info, Queue *queue);

char* dequeue(Queue *queue);

void freeQueue(Queue *queue);

void printQueue(Queue *queue);

#endif

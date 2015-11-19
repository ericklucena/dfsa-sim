#include "queue.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Queue* newQueue ()
{
	Queue *queue = malloc(sizeof(Queue));

	if (queue != NULL)
	{
		queue->head = NULL;
		queue->tail = NULL;
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Queue: Failed malloc\n");
		#endif
	}

	return queue;
}

void enqueue (char *info, Queue *queue)
{
	Node *node = newNode(info);

	if (node != NULL)
	{
		//Empty queue
		if( (queue->head == NULL) && (queue->tail == NULL) )
		{
			queue->head = queue->tail = node;
		}
		else
		{
			queue->tail->next = node;
			queue->tail = node;
		}
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Queue: Failed enqueue\n");
		#endif
	}
}

char* dequeue (Queue *queue)
{
	Node *toDelete = NULL;
	char *info = NULL;

	if (queue->head != NULL)
	{
		toDelete = queue->head;
		info = queue->head->info;

		if (queue->head != queue->tail)
		{
			queue->head = queue->head->next;
		}
		else
		{
			queue->head = queue->tail = NULL;
		}

		freeNode(toDelete);
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Queue: Failed dequeue\n");
		#endif
	}

	return info;
}

void freeQueue (Queue* queue)
{
	if (queue != NULL)
	{
		while (queue->head != NULL)
		{
			dequeue(queue);
		}

		free(queue);
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Queue: Failed free\n");
		#endif
	}
}

bool isEmpty(Queue *queue)
{
	return queue->head == NULL;
}


void printQueue(Queue *queue)
{
	Node *node = queue->head;

	if (node != NULL)
	{
		printf("-%s\n", node->info);
		while ((node = node->next) != NULL)
		{
			if (node->next != NULL)
			{
				printf("+%s\n", node->info);
			}
			else
			{
				printf("-%s\n", node->info);
			}
		}
		printf("\n");
	}
	else
	{
		printf("-[empty]\n");
	}

}

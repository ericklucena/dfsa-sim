#include "stack.h"
#include "node.h"
#include <stdio.h>
#include <stdlib.h>

Stack* newStack ()
{
	Stack *stack = malloc(sizeof(Stack));

	if (stack != NULL)
	{
		stack->top = NULL;
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Stack: Failed malloc\n");
		#endif
	}

	return stack;
}

void push (char *info, Stack *stack)
{
	Node *node = newNode(info);

	if (node != NULL)
	{
		node->next = stack->top;
		stack->top = node;
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Stack: Failed push\n");
		#endif
	}
}

char* pop (Stack *stack)
{
	Node *toDelete = NULL;
	char *info = NULL;

	if (stack->top != NULL)
	{
		toDelete = stack->top;
		info = stack->top->info;

		stack->top = stack->top->next;

		freeNode(toDelete);
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Stack: Empty stack\n");
		#endif
	}

	return info;
}

void freeStack (Stack* stack)
{
	if (stack != NULL)
	{
		while (stack->top != NULL)
		{
			pop(stack);
		}

		free(stack);
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Stack: Failed free\n");
		#endif
	}
}

void printStack(Stack *stack)
{
	Node *node = stack->top;

	if (node != NULL)
	{
		printf("-%s\n", node->info);
		while ((node = node->next) != NULL)
		{
			printf("+%s\n", node->info);
		}
		printf("\n");
	}
	else
	{
		printf("-[empty]\n");
	}
}

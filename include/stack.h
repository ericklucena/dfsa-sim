#ifndef DFSA_SIMULATOR_INCLUDE_STACK_H_
#define DFSA_SIMULATOR_INCLUDE_STACK_H_ 1

#include <stdlib.h>

typedef struct stack
{
	struct node *top;
} Stack;

Stack* newStack();

void push(char *info, Stack *stack);

char* pop(Stack *stack);

void freeStack(Stack* stack);

void printStack(Stack *stack);


#endif

#ifndef DFSA_SIMULATOR_INCLUDE_NODE_H_
#define DFSA_SIMULATOR_INCLUDE_NODE_H_ 1

#include <stdlib.h>

typedef struct node
{
	char *info;
	struct node *next;
} Node;

Node* newNode(char* info);

void freeNode(Node* node);


#endif

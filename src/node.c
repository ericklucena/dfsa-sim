#include "node.h"


Node* newNode(char* info)
{
	Node *node = malloc(sizeof(Node));

	if (node != NULL)
	{
		node->info = info;
		node->next = NULL;
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Node: Failed malloc\n");
		#endif
	}

	return node;
}

void freeNode(Node* node)
{
	if (node != NULL)
	{
		free(node);
	}
	else
	{
		#ifdef DEBUG
		fprintf(stderr, "@Node: Failed free\n");
		#endif
	}
}



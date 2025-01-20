

#include <stddef.h>
#include "Queue.h"

#ifndef EXPRESSIONTREE_H

#define EXPRESSIONTREE_H
#define DATA_MAX_SIZE 255
/* A binary tree node has data, pointer to left child
and a pointer to right child */
typedef struct ANode{
	char data[DATA_MAX_SIZE];
	struct ANode* left;
	struct ANode* right;
	struct ANode* next;
}ANode;

extern ANode *head;


ANode* newNode(char *data);
void printInorder(ANode* node);
void pushNode(ANode* x);
ANode* popNode();
ANode* makeExpressionTree(Queue *q);
#endif // QUEUE_H
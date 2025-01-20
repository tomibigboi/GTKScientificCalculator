#include <stdio.h>
#include <stdlib.h>
#include "string.h"
#include "Checks.h"
#include "ExpressionTree.h"

ANode *head=NULL;
/* Helper function that allocates a new node with the
given data and NULL left and right pointers. */
ANode* newNode(char *data)
{
	ANode* node
		= (ANode*)malloc(sizeof(ANode));
	//node->data = data;
	strcpy(node->data,data);
	node->left = NULL;
	node->right = NULL;
	node->next = NULL;
	
	return (node); 
}
void printInorder(ANode* node)
{
	if (node == NULL)
		return;
	else{
		/* first recur on left child */
		printInorder(node->left);

		/* then print the data of node */
		printf("%s ", node->data);

		/* now recur on right child */
		printInorder(node->right);
	}
}

void pushNode(ANode* x)
{
	if(head==NULL)
	head = x;
	else
	{
		(x)->next = head;
		head = x;
	}
	// ANode* temp;
	// while(temp!=NULL)
	// {
	//	 printf("%c ", temp->data);
	//	 temp = temp->next;
	// }
}
ANode* popNode()
{
	// PopNodeping out the top most[ pointed with head] element
	ANode* p = head;
	head = head->next;
	//strcpy(head,head->next);;
	return p;
}

ANode* makeExpressionTree(Queue *q)
{
	ANode *x, *y, *z;
	for (int i = q->front + 1; i < q->rear; i++) {
		// if read character is operator then popNodeping two
		// other elements from stack and making a binary
		// tree
		if (isOperator(q->items[i])) {
			z = newNode(q->items[i]);
			x = popNode();
			y = popNode();
			z->left = y;
			z->right = x;
			pushNode(z);
		}
		else {
			z = newNode(q->items[i]);
			pushNode(z);
		}
	}
	printf("The Inorder Traversal of Expression Tree: ");	
	printInorder(z);
	return z;
}

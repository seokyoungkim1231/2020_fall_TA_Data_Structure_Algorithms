#include <stdio.h>

#include "problem1.h"

int main() {

BinarySearchTreeNode *node;

	insert(root, 10);
	insert(root, 20);
	insert(root, 5);
	insert(root, 1);
	insert(root, 15);
	insert(root, 21);
	insert(root, 30);
	insert(root, 100);
	insert(root, 40);
	insert(root, 50);

	
	node = searchNode(root,1);
  if (node != NULL)
    printf("%d \n",node->value);
  
	node = searchNode(root,13);
  if (node != NULL)
    printf("%d \n",node->value);

	node = findMaxNode(root);
	if (node != NULL)
		printf("%d \n", node->value);

	node = findMinNode(root);
	if (node != NULL)
		printf("%d \n", node->value);

	node = findSuccessorNode(root, 15);
	if (node != NULL)
		printf("%d \n", node->value);

	node = findPredecessorNode(root, 15);
	if (node != NULL)
		printf("%d \n", node->value);

	deleteNode (root, 15);

	makeEmptyNode(root);
	
	node = searchNode(root,10);
  	if (node != NULL)
    printf("%d \n",node->value);
}


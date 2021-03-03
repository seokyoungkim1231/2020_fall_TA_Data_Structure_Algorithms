#include <stdio.h>

#include "problem2.h"

int main() {
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

	printf("in-order walk:\t\t");
	inorderWalk(root);
  printf("\n");

	printf("pre-order walk:\t\t");
	preorderWalk(root);
  printf("\n");

	printf("post-order walk:\t");
	postorderWalk(root);
  printf("\n");
}

#include<stdbool.h>

//Node declare
typedef struct node {
  int val;
  struct node *prev;
  struct node *next;
} node_t;

node_t *head;

bool insert(node_t *head, int X);
bool delete(node_t *head, int X);
bool find(node_t *head, int X);
int findkth(node_t *head, int index);
void printlist(node_t *head);
bool isEmpty(node_t *head);
bool makeEmpty(node_t *head);

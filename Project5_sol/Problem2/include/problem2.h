#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>
int **adj_graph;
int num_vertex;
int *color; //0 white 1 gray 2 black

typedef struct node {
  int val;
  struct node *next;
} node_t;
typedef struct node_Q {
  node_t *head; //node_t -> node in Single_linked_list.h
  node_t *tail;
  int count;
} node_q;
node_q *Queue;

typedef struct vertex {
  int name;
  struct vertex *next;
} node_g;

node_g **list_graph;


bool Enqueue(node_q *Queue, int value);
int Dequeue(node_q *Queue);
void init();

char vertex_name(int offset);
void graph_input(FILE *fp_in);
void dfs();
void dfs_search(int start);
void bfs();
void bfs_search(int source);
bool insert(node_g *head, int X);
bool find(node_g *head, int X);
void printlist(node_g *head);

//Find


#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#include "problem1.h"
#define START 0
//#define DEBUG 
char vertex_name(int offset){
	const int base = 65;
	return (base+offset);
}

void graph_input(FILE *fp_in){
	int i,j;
	fscanf(fp_in,"%d\n",&num_vertex);

	adj_graph = (int**)malloc(sizeof(int*)*num_vertex*num_vertex);
	for(i = 0; i < num_vertex; i++)
		adj_graph[i] = (int*)malloc(sizeof(int)*num_vertex);

	for(i = 0; i < num_vertex; i++){
		for(j = 0; j < num_vertex; j++){
			fscanf(fp_in,"%d ",&adj_graph[i][j]);
		}
	}
#if DEBUG
	for(i = 0; i < num_vertex; i++){
		for(j = 0; j < num_vertex; j++){
			printf("%d ",adj_graph[i][j]);
		}
		printf("\n");
	}
#endif
}
void dfs(){
	color = (int*)malloc(sizeof(int)*num_vertex);
	int i;
	for(i = 0; i < num_vertex; i++)
		color[i] = 0;//White

	printf("%c ",vertex_name(START));
	dfs_search(START);
	printf("\n");

	for(i = 0; i < num_vertex; i++){
		if(color[i] == 0){//white
			printf("%c ",vertex_name(i));
			dfs_search(i);
			printf("\n");
		}
	}
	free(color);
}
void dfs_search(int start){
	color[start] = 1;//gray
	int i;
	for(i = 0; i < num_vertex; i++){
		if(adj_graph[start][i] && color[i] == 0){
			printf("%c ",vertex_name(i));
			dfs_search(i);
		}
	}
	color[start] = 2;
}
void bfs(){
	color = (int*)malloc(sizeof(int)*num_vertex);
	int i;
	for(i = 0; i < num_vertex; i++)
		color[i] = 0;//White

	bfs_search(START);
	printf("\n");
	for(i = 0; i < num_vertex; i++){
		if(color[i] == 0){
			bfs_search(i);
			printf("\n");
		}
	}
}
void bfs_search(int start){
	int source,sink;
	int i;
	init();
	Enqueue(Queue,start);
	color[start] = 1;
	printf("%c ",vertex_name(start));
	
	while(Queue->count!=0){
		source = Dequeue(Queue);
		for(i = 0; i < num_vertex; i++){
			if(adj_graph[source][i] && color[i] == 0){
				printf("%c ",vertex_name(i));
				color[i] = 1;
				Enqueue(Queue,i);
			}
			color[source] = 2;
		}
	}
	free(Queue);
}

bool Enqueue(node_q *Queue, int value){
  node_t *new; 
  new = (node_t*)malloc(sizeof(node_t)); 
  new->val = value;

  if(new == NULL){
    return false;
  }
  if(Queue->count == 0){
    Queue->tail = new;
    Queue->count++;
  }
  else {
    Queue->head->next = new;
    Queue->count++;
  }
  Queue->head = new;

  return true;
}
int Dequeue(node_q *Queue){
  node_t *node_deq;  
  int deq_val;
  if(Queue->count == 0){
    return NULL;
  }
  node_deq = Queue->tail;
  deq_val = node_deq->val;
  Queue->tail = node_deq->next;
  free(node_deq);
  Queue->count--;
  return deq_val;
}
void init(){
  Queue = (node_q*)malloc(sizeof(node_q));
  Queue->count = 0;
  Queue->head = NULL;
  Queue->tail = NULL;
}






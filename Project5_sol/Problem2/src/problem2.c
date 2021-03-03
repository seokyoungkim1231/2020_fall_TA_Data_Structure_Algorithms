#include <stdio.h>
#include <stdlib.h>
#include<stdbool.h>

#include "problem2.h"
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
    list_graph = (node_g **)malloc(sizeof(node_g **)*num_vertex);
    for(i = 0; i < num_vertex; i++)
         list_graph[i] = (node_g*)malloc(sizeof(node_g)); 


    for(i = 0; i < num_vertex; i++){
        for(j = 0; j < num_vertex; j++){
            if(adj_graph[i][j]){
                insert(list_graph[i],j);
            }
        }
    }
#if DEBUG
    for(i = 0; i < num_vertex; i++){
           printlist(list_graph[i]);
        printf("\n");
    }
#endif
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
		if(find(list_graph[start],i) == true && color[i] == 0){
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
			if(find(list_graph[source],i) == true && color[i] == 0){
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

bool find(node_g *head, int X){
  int error_code;
  bool exist = false;
  node_g *iter;
  if(head->next == NULL || head == NULL){
    error_code = 2;
    return exist;
  }
  else {
    iter = head->next;
    while(iter != NULL){
      if(iter->name == X){
        exist = true;
        return exist;    
      }
      iter = iter->next;
    }
    error_code = 2;
    return exist;
  }
}
void printlist(node_g *head){
  node_g *iter;
  printf("Print List\t:\t");
  if(head == NULL || head->next == NULL){
    printf("empty\n");
    return;
  }
  else {
    iter = head->next;
    while(iter != NULL){  
      printf("%c\t",vertex_name(iter->name));
      iter = iter->next;
    }
    printf("\n");
    return; 
  }
}
bool insert(node_g *head, int X){
  int error_code;
  node_g *new = (node_g*)malloc(sizeof(node_g)); 
  if(new == NULL){ //Fail to insert
    error_code = 0;
    return false;
  }
  else {
    new->next = head->next;
    head->next = new;
    new->name = X;
  }
  return true;
}





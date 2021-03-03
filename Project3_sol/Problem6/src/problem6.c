#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Dont touch
#include "problem6.h"

//Implement Function in header file
bool Enqueue(node_q *Queue, int value){
  node_t *new; 
  new = (node_t*)malloc(sizeof(node_t)); 
  new->val = value;
  if(new == NULL){
    pererror_function_queue(0);
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
    pererror_function_queue(1);
    return NULL;
  }
  node_deq = Queue->tail;
  deq_val = node_deq->val;
  Queue->tail = node_deq->next;
  free(node_deq);
  Queue->count--;
  return deq_val;

}
void pererror_function_queue(int error_code){
  switch(error_code){
   case 0: printf("Failt to enqueueu\n"); break;
   case 1: printf("Failt to dequeueu\n"); break;
    default: printf("non");
  }
}


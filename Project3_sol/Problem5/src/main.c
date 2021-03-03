#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Dont touch
#include "problem5.h"

int main(){
  int i;
  Queue = (node_q*)malloc(sizeof(node_q));
  Queue->count = 0;
  Queue->head = NULL;
  Queue->tail = NULL;

  for(i = 2; i < 12; i++)
    Enqueue(Queue,i);
  
  Enqueue(Queue,100);
  Enqueue(Queue,200);

  for(i = 0; i < 10; i++)
    printf("%d\n ",Dequeue(Queue));

  printf("%d\n ",Dequeue(Queue));
  printf("%d\n ",Dequeue(Queue));
  printf("%d\n ",Dequeue(Queue));

  Enqueue(Queue,300);
  Enqueue(Queue,500);

  printf("%d\n ",Dequeue(Queue));
  printf("%d\n ",Dequeue(Queue));
 
  return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Dont touch
#include "problem3.h"


int main(){
  int *Queue;
  Queue = (int*)malloc(sizeof(int)*NUM_QUEUE_SIZE); 
  int i;
  for(i = 2; i < 12; i++)
    Enqueue(Queue,i);
  
  Enqueue(Queue,100);
  Enqueue(Queue,200);

  for(i = 0; i < 10; i++)
    printf("%d \n",Dequeue(Queue));

  printf("%d \n",Dequeue(Queue));
  printf("%d \n",Dequeue(Queue));

  Enqueue(Queue,300);
  Enqueue(Queue,500);

  printf("%d \n",Dequeue(Queue));
  printf("%d \n",Dequeue(Queue));
 
  return 0;
}


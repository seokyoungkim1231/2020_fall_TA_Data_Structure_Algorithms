#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//Dont touch
#include "problem2.h"

//Implement Function in header file
bool Enqueue(int *Queue, int value){
  if(tail >= 10){
    pererror_function_queue(0);//Full
    return false;
  }
  Queue[tail] = value;
  tail++;
  return true;
}
int Dequeue(int *Queue){
  int deq;
  if(head == tail){
    pererror_function_queue(1);//Empty
    return NULL;
  }
  deq = Queue[head]; 
  head++;
  return deq;

}
void pererror_function_queue(int error_code){
  switch(error_code){
    case 0: printf("Fail to Enqueue\n"); break;
    case 1: printf("Fail to Dequeue\n"); break;
    default: printf("Not defined\n"); break;
  }
}


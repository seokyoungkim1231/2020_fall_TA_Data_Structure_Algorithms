#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Dont touch
#include "problem3.h"

count = 0;
head = 0;
tail = 0;
//Implement Function in header file
bool Enqueue(int *Queue, int value){
  //if((tail+1)%10 == head){
  if(count == 10){
    pererror_function_queue(0);
    return false;
  }
  Queue[tail] = value;
  tail = (tail + 1)%10;
  count++;
  return true;
}
int Dequeue(int *Queue){
  int deq;
  //if(head == tail){
  if(count == 0){
    pererror_function_queue(1);
    return NULL;
  }
  deq = Queue[head];
  head = (head+1)%10;
  count--;
  return deq;
}
void pererror_function_queue(int error_code){
   switch(error_code){
     case 0: printf("Fail to enqueue\n"); break;
     case 1: printf("Fail to dequeue\n"); break;
     default:printf("Non\n"); break;
   }
}


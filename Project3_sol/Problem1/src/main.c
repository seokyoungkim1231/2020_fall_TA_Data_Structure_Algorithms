#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Dont touch
#include "problem1.h"


int main(){
  int *Stack;
  Stack = (int*)calloc(NUM_STACK_SIZE+1,sizeof(int));
  
  int i;
  for(i = 2; i < 12; i++)
    Push(Stack,i);
  
  Push(Stack,100);
  Push(Stack,200);

  for(i = 0; i < 10; i++)
    printf("%d \n",Pop(Stack));

  printf("%d \n",Pop(Stack));
  printf("%d \n",Pop(Stack));
 
  return 0;
}


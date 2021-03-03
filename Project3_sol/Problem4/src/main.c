#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>


//Dont touch
#include "problem4.h"

int main(){
  int i;
  Stack = (node_t*)malloc(sizeof(node_t));
  for(i = 2; i < 12; i++)
    Push(Stack,i);
  
  Push(Stack,100);
  Push(Stack,200);

  for(i = 0; i < 10; i++)
    printf("%d ",Pop(Stack));

  printf("%d ",Pop(Stack));
  printf("%d ",Pop(Stack));
  printf("%d ",Pop(Stack));

 
  return 0;
}


#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Dont touch
#include "problem4.h"

count = 0;
//Implement Function in header file
bool Push(node_t *Stack, int value){
    if(insert(Stack,value) == true){
    printf("Stack %d\n",Stack->next->val);
      count++;
      return true;
    }
    else {
      pererror_function_stack(0);
      return false;
    }
}
int Pop(node_t *Stack){
  int popped;
  if(count == 0){
    pererror_function_stack(1);
    return NULL;
  }
  popped = findkth(Stack,0);
  //printf("find:%d \r\n",find(Stack,popped));
  delete(Stack,popped);
  return popped;
}
void pererror_function_stack(int error_code){
  switch(error_code){
    case 0: printf("fail to push\n"); break;
    case 1: printf("fail to push\n"); break;
    default : printf("non\n"); break;
  }
}


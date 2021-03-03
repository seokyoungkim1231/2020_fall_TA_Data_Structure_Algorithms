#include<stdio.h>
#include<stdlib.h>
#include<stdbool.h>

//Dont touch
#include "problem1.h"

//Implement Function in header file
bool Push(int *Stack, int value){
  if(Stack[0] >= 10) {
      pererror_function_stack(0);
      return false;
  }
  Stack[++Stack[0]] = value;
  return true;
}
int Pop(int *Stack){
  if(Stack[0] <= 0){
    pererror_function_stack(1);
    return NULL;
  }
  return Stack[Stack[0]--];
}
void pererror_function_stack(int error_code){
  switch(error_code){ 
    case 0: printf("Fail to push\n"); break;
    case 1: printf("Fail to pop\n"); break;
  default: printf("Not defined exception\n"); break;
  }
}


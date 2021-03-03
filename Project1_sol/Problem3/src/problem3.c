#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#include "problem3.h"

void pererror_function(int error_code){
  switch(error_code){
    case 0: printf("Fail to insert node\n"); break;
    case 1: printf("Fail to delete node\n"); break;
    case 2: printf("Fail to searching node\n"); break;
    case 3: printf("Fail to search k-th node\n"); break;
    case 4: printf("Fail to delete all the  node\n"); break;
    default : printf("Unexpected exception\n"); break;
  }
}
bool makeEmpty(node_t *head){
  int error_code;
  node_t *iter;
  node_t *victim;
  if(head == NULL || head->next == NULL){
    error_code = 4;
    pererror_function(error_code);
    return false;
  }
  else {
    iter = head->next;
    while(iter != NULL){
      victim = iter;
      iter = iter->next;
      free(victim);
    }
  head->next = NULL;
  head = NULL;
  free(head);
  return true; 
  }
}
int findkth(node_t *head, int index){
  int error_code;
  int number = 0; 
  bool exist = false;
  node_t *iter;
  
  if(head == NULL || head->next == NULL){
    error_code = 3;
    pererror_function(error_code);
    return 0;
  }
  else {
    iter = head->next;
    while(iter != NULL){
      if(number == index){
      exist = true;
       break;
      }
      iter = iter->next;
      number++;      
    }
    if(exist == true)
      return iter->val;
    else {
     error_code = 3;
     pererror_function(error_code);
     return 0;
    }
  }
}
bool isEmpty(node_t *head){
  if(head == NULL || head->next == NULL)
    return true;
  else
    return false;
}
bool delete(node_t *head, int X){
  node_t *iter;
  node_t *victim;
  node_t *prev;
  int error_code;
  if(find(head,X) == false){
    error_code = 1;
    pererror_function(error_code);
    return false;
  }
  else {
    iter = head->next;  
    while(iter != NULL){
      if(iter->val == X)
        break;
      iter = iter->next;
    }
    iter->prev->next = iter->next;
    if(iter->next != NULL)
      iter->next->prev = iter->prev; 
    free(iter);
    return true;
  }
}
bool find(node_t *head, int X){
  int error_code;
  bool exist = false;
  node_t *iter;
  if(head->next == NULL || head == NULL){
    error_code = 2;
    pererror_function(error_code);
    return exist;
  }
  else {
    iter = head->next;
    while(iter != NULL){
      if(iter->val == X){
        exist = true;
        return exist;    
      }
      iter = iter->next;
    }
    error_code = 2;
    pererror_function(error_code);
    return exist;
  }
}
void printlist(node_t *head){
  node_t *iter;
  printf("Print List\t:\t");
  if(head == NULL || head->next == NULL){
    printf("empty\n");
    return;
  }
  else {
    iter = head->next;
    while(iter != NULL){  
      printf("%d\t",iter->val);
      iter = iter->next;
    }
    printf("\n");
    return; 
  }
}
bool insert(node_t *head, int X){
  int error_code;
  node_t *new = (node_t*)malloc(sizeof(node_t)); 
  node_t  *temp;
  if(new == NULL){ //Fail to insert
    error_code = 0;
    pererror_function(error_code);
    return false;
  }
  else {
    if(head->next != NULL){
      temp = head->next;
      temp->prev = new;
      new->next = temp;
    }
    head->next = new;
    new->prev = head;
    new->val = X;
  }
  return true;
}

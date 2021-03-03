#include <stdio.h>
#include "problem1.h"


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
bool makeEmpty(int *L){
  int error_code;  
  if(L[0] == 0){
    error_code = 4;
    pererror_function(error_code);
    return false;
  }
  else {
    L[0] = 0;
    return true;
  }
}
bool isEmpty(int *L){
  if(L[0] == 0)
    return true;
  else
    return false;
}
int findkth(int *L, int index){
  int error_code;
  if(index > L[0]){
    error_code = 3;
    pererror_function(error_code);
    return 0;
  }
  else
    return L[index];
}
bool find(int *L, int X){
  int i;
  int error_code;
  bool exist = false;
  for(i = 1; i <= L[0]; i++){
    if(L[i] == X){
      exist = true;
      break;
    }
  } 
  if(exist == false){
    error_code = 2;
    pererror_function(error_code);
    return false; //Fail to delete
  }
  else 
    return true;
}
bool delete(int *L, int X){
  int error_code;
  int i;
  int index = 0;
  bool exist = false;
  //Find X's location
  for(i = 1; i <= L[0]; i++){
    if(L[i] == X){
      index = i;
      exist = true;
      break;
    }
  } 
  if(exist == false){
    error_code = 1;
    pererror_function(error_code);
    return false; //Fail to delete
  }
  else { //Delete
    if(index == L[0])
      L[0]--;
    else {
    for(i = index; i < L[0]; i++)
      L[i] = L[i+1];
    L[0]--;
    }
  }
  return true;
}
void printlist(int *L){
  int i;  
  if(L[0] == 0)
    printf("Print List\t:\tempty");
  else {
    printf("Print List\t:\t");
    for(i = 1; i <= L[0]; i++)
      printf("%d\t",L[i]);    
  }
  printf("\n");
}
bool insert(int *L, int X){
  int error_code;

  if(L[0]+1 > MAX_SIZE){
    error_code = 0;
    pererror_function(error_code);
    return false;
  }
  else {
    L[0]++;
    L[L[0]] = X;
  }
  return true;
}

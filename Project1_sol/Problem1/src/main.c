#include<stdio.h>
#include<stdlib.h>
#include"problem1.h"
int main()
{

  //Init list as array 
  List = (int*)calloc(MAX_SIZE+1,sizeof(int)); 
  
  //Call sequence 
  insert(List,1);
  insert(List,2);
  insert(List,3);
  insert(List,4);
  insert(List,5);
  insert(List,6);
  insert(List,7);  
  insert(List,8);
  insert(List,9);
  printlist(List);

  
  delete(List,3);
  delete(List,10);
  printlist(List);
  
  find(List,3);
  find(List,11);

  printf("%d\n",findkth(List,7));
  printf("%d\n",findkth(List,13));
  
  printf("%d\n",isEmpty(List));
  makeEmpty(List);
  printf("%d\n",isEmpty(List));
  
  free(List);
  
  return 0;
}

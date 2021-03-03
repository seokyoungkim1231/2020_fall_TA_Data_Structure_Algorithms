#include<stdio.h>
#include<stdlib.h>
#include"Array.h"
int main()
{
  List = (int*)calloc(MAX_SIZE+1,sizeof(int)); 
  insert(List,1);
  printlist(List);
  insert(List,2);
  printlist(List);
  insert(List,3);
  printlist(List);
  insert(List,4);
  printlist(List);
  insert(List,5);
  printlist(List);
  insert(List,6);
  printlist(List);
  insert(List,7);
  printlist(List);
  insert(List,3);
  printlist(List);
  insert(List,8);
  printlist(List);
  insert(List,9);
  printlist(List);
  delete(List,3);
  printlist(List);
  delete(List,10);
  printlist(List);
  find(List,3);
  find(List,13);
  printf("%d\n",findkth(List,7));
  printf("%d\n",findkth(List,13));
  printf("find 1st");
  printf("%d\n",findkth(List,1));
  printf("find last");
  printf("%d\n",findkth(List,List[0]));
  printf("%d\n",isEmpty(List));
  makeEmpty(List);
  printf("%d\n",isEmpty(List));
  printlist(List);
  free(List);
  return 0;
}

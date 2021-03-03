#include<stdio.h>
#include<stdlib.h>

#include"problem3.h"

int main()
{
  //Init list as singly linked list 
  head = (node_t*)malloc(sizeof(node_t)); 
  
  //Call sequence 
  insert(head,1);
  insert(head,2);
  insert(head,3);
  insert(head,4);
  insert(head,5);
  insert(head,6);
  insert(head,7);  
  insert(head,8);
  insert(head,9);
  printlist(head);

  
  delete(head,3);
  delete(head,10);
  printlist(head);
  
  find(head,3);
  find(head,11);

  printf("%d\n",findkth(head,7));
  printf("%d\n",findkth(head,13));
  
  printf("%d\n",isEmpty(head));
  makeEmpty(head);
  printf("%d\n",isEmpty(head));

  return 0;
  
}

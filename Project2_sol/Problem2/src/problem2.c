#include <stdio.h>
#include <stdlib.h>

#include "problem2.h"

void pererror_function(int error_code){
  switch(error_code){
  case InsertError             : printf("Fail to insert node\n"); break;
  case DeleteError             : printf("Fail to delete node\n"); break;
  case SearchError             : printf("Fail to searching node\n"); break;
  case SearchMaxError          : printf("Fail to search max node\n"); break;
  case SearchMinError          : printf("Fail to search min node\n"); break;
  case SearchSuccessorError    : printf("Fail to search sucessor\n"); break;
  case searchPredecessorError  : printf("Fail to search predecessor\n"); break;
  case FailDeleteAllError      : printf("Fail to delete all node\n"); break;

  default:printf("Error\n"); break;
  }
 }

void postorderWalk(BinarySearchTreeNode *Tree){
  BinarySearchTreeNode *mark;
  mark = findMinNode(Tree);
  while (mark->right != NULL)
    mark = findMinNode(mark->right);
  while (mark != NULL) {
    printf("%d\t", mark->value);
    while (mark->right != NULL)
      mark = findMinNode(mark->right);
    while (mark != NULL && mark->right == NULL) {
      while (mark->parent != NULL && mark == mark->parent->right) {
        mark = mark->parent;
        printf("%d\t", mark->value);
      }
      mark = mark->parent;
      if (mark != NULL && mark->right == NULL)
        printf("%d\t", mark->value);
    }
    if (mark != NULL){
      while (mark->right != NULL)
        mark = findMinNode(mark->right);
    }
  }
}

void preorderWalk(BinarySearchTreeNode *Tree){
  BinarySearchTreeNode *mark;
  mark = Tree;
  while(mark != NULL){
    printf("%d\t",mark->value);
    while(mark->left != NULL){
      mark=mark->left;
      printf("%d\t",mark->value);
    }
    while(mark->parent != NULL && mark->parent->left == mark && mark->right == NULL){
      mark=mark->parent;
    }
    mark=mark->right;
  }
}
void inorderWalk(BinarySearchTreeNode *Tree){
  BinarySearchTreeNode *mark;
  BinarySearchTreeNode *iter;
  mark = Tree;

   while(mark->left!=NULL)
     mark = mark->left;

  while(mark != NULL){
   printf("%d\t",mark->value);
    if(mark->right != NULL){
      iter = mark->right;
      while(iter->left != NULL)
        iter = iter->left;
      mark = iter;
    }
    else{
      while(mark->parent != NULL && mark->parent->right == mark)
        mark = mark->parent;
      mark = mark->parent;
    }
  }
}
BinarySearchTreeNode *findMinNode(BinarySearchTreeNode *Tree){
  if(Tree == NULL){
    pererror_function(SearchMinError);
    return NULL;
  }
  BinarySearchTreeNode *curr = Tree;
  while(curr->left != NULL){
    curr = curr->left;
  }
  return curr;
}


BinarySearchTreeNode *insert(BinarySearchTreeNode *Tree, int X){
  BinarySearchTreeNode *curr = Tree;
  BinarySearchTreeNode *parent = NULL;
  BinarySearchTreeNode *new;
  new = (BinarySearchTreeNode*)malloc(sizeof(BinarySearchTreeNode));
  if(new == NULL){
    pererror_function(InsertError);
    return NULL;
  }
  new->value = X;
  new->left = NULL;
  new->right = NULL;

  while (curr != NULL){
    parent = curr;
    if( X > curr->value)
      curr = curr->right;
    else
      curr = curr->left;
  }

  if(parent == NULL){
    new->parent = NULL;
    root = new;
  }
  else {
    if(parent->value < new->value)
      parent->right = new;
    else
      parent->left = new;
    new->parent = parent;
  }
  return new;
}


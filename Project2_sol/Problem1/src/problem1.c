#include <stdio.h>
#include <stdlib.h>

#include "problem1.h"


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
    root = new;
    new->parent = NULL;
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

BinarySearchTreeNode *searchNode(BinarySearchTreeNode *Tree, int X){
  BinarySearchTreeNode *curr = Tree;

  if(Tree == NULL){
    pererror_function(SearchError);
    return NULL;
  }
 
  while(curr->value != X){
    if(curr->value < X){
      if(curr->right != NULL)
      curr = curr->right;
      else
        return NULL;
    }
    else {
      if(curr->left != NULL)
      curr = curr->left;
      else
        return NULL;
    }
  }
  return curr;
}
BinarySearchTreeNode *findMaxNode(BinarySearchTreeNode *Tree){
  if(Tree == NULL){
    pererror_function(SearchMaxError);
    return NULL;
  }
  BinarySearchTreeNode *curr = Tree;
  while(curr->right != NULL){
    curr = curr->right;
  }
  return curr;
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
BinarySearchTreeNode *deleteNode(BinarySearchTreeNode *Tree, int X){

  BinarySearchTreeNode *victim_node, *child;
  victim_node = searchNode(Tree,X);

  if(victim_node == NULL){
    pererror_function(DeleteError);
    return NULL;
  }

  if(victim_node->left == NULL && victim_node->right == NULL){
    if(victim_node->parent != NULL){
      if(victim_node->parent->left == victim_node){
        victim_node->parent->left = NULL;
      }
      else
        victim_node->parent->right = NULL;
    }
    else {
      root = NULL;
    }
  }
  else if (victim_node->left == NULL || victim_node->right == NULL){

    if(victim_node->left != NULL)
      child = victim_node->left;
    else if(victim_node->right != NULL)
      child = victim_node->right;

    if(victim_node->parent != NULL){
      if(victim_node->parent->left == victim_node)
        victim_node->parent->left  = child;
      else
        victim_node->parent->right = child;
    }
    else {
      root = child;
      child->parent = NULL;
    }
  }
  else {
    child = findSuccessorNode(root,X);
    if(child->parent->left == child){
      if(child->right != NULL)
        child->parent->left = child->right;
      else
        child->parent->left = child->left;
    }
    else {
      if(child->left != NULL)
        child->parent->right = child->left;
      else
        child->parent->right = child->right;
    }
    if(child->right != NULL)
      child->right->parent = child->parent;

    victim_node->value = child->value;
    victim_node = child;
  }
  free(victim_node);

  return root;
}
BinarySearchTreeNode *findSuccessorNode(BinarySearchTreeNode *Tree, int X){
  if(Tree == NULL){
    pererror_function(SearchSuccessorError);
    return NULL;
  }
  BinarySearchTreeNode *curr;
  curr = searchNode(Tree, X);
  if(curr == NULL){
    pererror_function(SearchSuccessorError);
    return NULL;
  }
  else if(curr->right != NULL)
    return findMinNode(curr->right);
  else{
    BinarySearchTreeNode *parent = curr->parent;
    while(parent != NULL && parent->right == curr){
      curr = parent;
      parent = parent->parent;
    }
    if(parent == NULL) { 
      pererror_function(SearchSuccessorError);
      return NULL;
    }
    else 
      return parent;
  }
}
BinarySearchTreeNode *findPredecessorNode(BinarySearchTreeNode *Tree, int X){
  if(Tree == NULL){
    pererror_function(searchPredecessorError);
    return NULL;
  }
  BinarySearchTreeNode *curr;
  curr = searchNode(Tree, X);
  if(curr == NULL){
    pererror_function(searchPredecessorError);
    return NULL;
  }
  else if(curr->left != NULL)
    return findMinNode(curr->left);
  else {
    BinarySearchTreeNode *parent = curr->parent;

    while(parent != NULL && curr == parent->left){
      curr = parent;
      parent = parent->parent;
    }
    if(parent == NULL){
      pererror_function(searchPredecessorError);
      return NULL;
    }
    else return parent;
  }
}
void makeEmptyNode(BinarySearchTreeNode *Tree){
 
  BinarySearchTreeNode *curr = Tree;
  while(curr != NULL){
    printf("Delete %d \n",curr->value);
    curr = deleteNode(curr, curr->value);
  }
}



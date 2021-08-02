
#include "binarysearchtree.h"
#include "errors.h"

typedef struct s_Node {
  GenericElement value;
  struct s_Node* left;
  struct s_Node* right;
}* Node;

struct s_BSTree {
  Node root;
  FunctionCompare fcmp;
};

Node bstree_node_new(const GenericElement value, Node left, Node right){

  Node node = malloc(sizeof(struct s_Node));

  if(!node){
    perror("node_new()");
    exit(BSTREENODE_INIT);
  }
  
  node->value = value;
  node->left = left;
  node->right = right;
  
  return node;

}

BSTree bstree_new(FunctionCompare fcmp){
  
  BSTree bst = malloc(sizeof(struct s_BSTree));
  
  if(!bst){
    perror("bstree_new()");
    exit(BINARYSEARCHTREE_INIT);
  }
  
  bst->root = NULL;
  bst->fcmp = fcmp;

  return bst;
}

void bstree_destroy(BSTree bst){
  free(bst);
}

bool bstree_isEmpty(const BSTree bst){
  return !(bst->root);
}


void bstree_add(BSTree bst, const GenericElement value){
  
  Node parent = NULL;
  Node* cur = &bst->root;
  
  while(*cur != NULL){
    parent = *cur;
    cur = (bst->fcmp(value, (*cur)->value) < 0) ? &(parent->left) : &(parent->right);
  }

  *cur = bstree_node_new(value, NULL, NULL);
  parent = *cur;

}

bool bstree_search(const BSTree bst, const GenericElement value){
  
  Node cur = bst->root;
  
  while( (cur != NULL) && (bst->fcmp(value, cur->value) != 0) )
    cur = (bst->fcmp(value, cur->value) < 0) ? cur->left : cur->right;
  
  return cur;

}






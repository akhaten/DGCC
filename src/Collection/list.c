#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <stdbool.h>

#include "list.h"

#define LIST_INIT 100
#define SENTINEL_INIT 99
#define ELEMENT_INIT 98
#define LIST_ITERATOR_INIT 97

typedef struct s_Node {
  void *value;
  struct s_Node *previous;
  struct s_Node *next;
} *Node;

struct s_List {
  Node sentinel;
  int size;
};

struct s_ListIterator {
  Node begin;
  Node end;
  Node cur;
};


List list_new(void){

  List l = malloc(sizeof(struct s_List));
  
  if(!l){
    perror("list_new()");
    exit(LIST_INIT);
  }

  l->sentinel = malloc(sizeof(struct s_Node));
  
  if(!l->sentinel){
    perror("list_new");
    exit(SENTINEL_INIT);
  }

  l->sentinel->value = NULL;
  l->sentinel->previous = l->sentinel;
  l->sentinel->next = l->sentinel;
  l->size = 0;
  
  return l;

}

void list_destruct(List l){
  assert(l != NULL);

  while(!list_isEmpty(l))
    list_remove(l,0);

  free(l->sentinel);
  free(l);
  l = NULL;

}

unsigned int list_size(const List l){
  assert(l != NULL);
  return l->size;
}

int list_isEmpty(const List l){
  assert(l != NULL);
  int isEmpty = 0;
  if(l->size == 0)
    isEmpty = 1;
  return isEmpty;
}

List list_add(List l, void *e){
  assert( (l != NULL) && (e != NULL) );

  Node new = malloc(sizeof(struct s_Node));
  
  if(!new){
    perror("list_add()");
    exit(ELEMENT_INIT);
  }
  
  Node sentinel = l->sentinel;
  new->value = e;
  new->previous = l->sentinel->next;
  new->next = sentinel;
  new->previous->next = new;
  new->next->previous = new;
  ++l->size;
  
  return l;

}

List list_remove(List l, const unsigned int index){
  assert( (l != NULL) && (index < list_size(l)) );
  
  Node cur = l->sentinel->next;
  
  for(int i = 0; i < index; ++i)
    cur = cur->next;
  
  cur->next->previous = cur->previous;
  cur->previous->next = cur-> next;
  --l->size;

  free(cur);
  cur = NULL;

  return l;

}

List list_insert(List l, const unsigned int index, void *e){
  assert( (l != NULL) && (0 <= index) && (index <= list_size(l)) && (e != NULL) );
  
  Node cur = l->sentinel->next;
  
  for(int i = 0; i < index; ++i)
    cur = cur->next;

  Node new = malloc(sizeof(struct s_Node));
  
  if(!new){
    perror("list_insert");
    exit(ELEMENT_INIT);
  }
  
  new->value = e;
  new->previous = cur->previous;
  new->next = cur;
  new->previous->next = new;
  new->next->previous = new;
 
  
  ++l->size;
  
  return l;
}

void *list_get(const List l, const unsigned int index){
  assert( (l != NULL) && (!list_isEmpty(l)) && (0 <= index) && (index < list_size(l)) );

  Node cur = l->sentinel->next;
  
  for(int i = 0; i < index; ++i)
    cur = cur->next;
  
  return cur->value;

}

List list_map(List l, void* f(void *e)){
  for(Node cur = l->sentinel->next; cur != l->sentinel; cur = cur->next)
    cur->value = f(cur->value);
  return l;
}

List list_sublist(const List l, const unsigned int index1, const unsigned int index2){
  assert((l != NULL) && (0 <= index1) && (index1 <= index2) && (index2 < list_size(l)));
  
  List sublist = list_new();
  Node cur = l->sentinel->next;
  int i = 0;
  
  for(; i < index1; ++i)
    cur = cur->next;
  
  sublist->sentinel->next = cur;
  
  for(; i < index2; ++i)
    cur = cur->next;
  
  sublist->sentinel->previous = cur;
  sublist->size = index2 - index1 + 1;
  
  return sublist;

}

int list_exists(const List l, int predicate(void *e)){
  assert(l != NULL);

  Node cur = l->sentinel->next;
  int check = 0;
  
  while((check == 0) && (cur != l->sentinel)){
    check = predicate(cur->value);
    cur = cur->next;
  }
  
  return check;

}

int list_forall(const List l, int predicate(void *e)){
  
  assert(l != NULL);

  Node cur = l->sentinel->next;
  int check = 1;
  
  while((check == 1) && (cur != l->sentinel))
    check = predicate(cur->value);
  
  return check;

}

/*ListIterator list_iterator(const List l){
  assert(l != NULL);
  
  ListIterator iter = malloc(sizeof(struct s_ListIterator));

  if(!iter){
    perror("list_iterator");
    exit(LIST_ITERATOR_INIT);
  }

  iter->begin = l->sentinel;
  iter->cur = iter->begin;
  iter->end = l->sentinel->previous;

  return iter;

}

int list_iterator_hasnext(const ListIterator iter){
  assert(iter != NULL);
  return iter->cur != iter->end;
}

void *list_iterator_value(const ListIterator iter){
  return iter->cur->value;
}

ListIterator list_iterator_next(ListIterator iter){
  assert(iter != NULL);
  iter->cur = iter->cur->next;
  return iter;
}

ListIterator list_iterator_previous(ListIterator iter){
  assert(iter != NULL);
  iter->cur = iter->cur->previous;
  return iter;
}*/




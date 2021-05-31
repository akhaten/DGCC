
#include "list.h"


typedef struct s_Node {
  void *value;
  struct s_Node *previous;
  struct s_Node *next;
} *Node;

struct s_List {
  Node sentinel;
  int size;
  bool mutation;
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
  l->mutation = true;
  
  return l;

}

void list_destruct(List l){

  assert(l != NULL);

  while(!list_isEmpty(l))
    list_remove(l,0);

  free(l->sentinel);
  l->sentinel = NULL;
  
  free(l);
  l = NULL;

}

unsigned int list_size(const List l){
  
  assert(l != NULL);

  return l->size;

}

bool list_isEmpty(const List l){

  assert(l != NULL);
  
  return !l->size;

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
  l->mutation = true;
  
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
  l->mutation = true;

  free(cur);
  cur = NULL;

  return l;

}

List list_insert(List l, const unsigned int index, void *e){

  assert( (l != NULL) && (e != NULL) && (0 <= index) && (index <= list_size(l)));
  
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
  l->mutation = true;
  
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
  
  assert( (l != NULL) );

  for(Node cur = l->sentinel->next; cur != l->sentinel; cur = cur->next)
    cur->value = f(cur->value);

  l->mutation = true;
  
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

bool list_exists(const List l, bool predicate(void *e)){

  assert(l != NULL);

  Node cur = l->sentinel->next;
  int find = false;
  
  while((!find) && (cur != l->sentinel)){
    find = predicate(cur->value);
    cur = cur->next;
  }
  
  return find;

}

bool list_forall(const List l, bool predicate(void *e)){
  
  assert(l != NULL);

  Node cur = l->sentinel->next;
  int check = true;
  
  while((check) && (cur != l->sentinel)){
    check = predicate(cur->value);
    cur = cur->next;
  }
  
  return check;

}

List list_copy(List l){

  assert( (l != NULL) && (!list_isEmpty(l)) );

  List copy = list_new();
  
  for(Node cur = l->sentinel->next;  cur->next != l->sentinel; cur = cur->next)
    list_add(copy, cur->value);
  
  return copy;

}

struct s_ListIterator {
  Node sentinel; 
  Node cur;
  bool *mutation;
};

ListIterator listiterator_new(List l){
  
  assert( l != NULL );

  ListIterator iter = malloc(sizeof(struct s_ListIterator));
  
  if(!iter){
    perror("listiterator_new()");
    exit(ITERATOR_INIT);
  }
  
  iter->sentinel = l->sentinel;
  iter->cur = iter->sentinel;
  l->mutation = false;
  iter->mutation = &l->mutation;
  

  return iter;

}

void listiterator_destruct(ListIterator iter){
  assert( (iter != NULL) );
  
  free(iter);
  iter = NULL;

}

bool listiterator_mutation(ListIterator iter){
  
  assert(iter != NULL);
  
  return iter->mutation;

}

bool listiterator_isValid(ListIterator iter){

  assert(iter != NULL);
  
  return iter->sentinel != NULL;

}

ListIterator listiterator_reset(ListIterator iter){
  
  assert( (iter != NULL) && listiterator_isValid(iter) );
  
  iter->cur = iter->sentinel;
  
  return iter;

}


bool listiterator_hasnext(ListIterator iter){
  
  assert( (iter != NULL) && (listiterator_mutation(iter)) );
  
  return iter->cur->next != iter->sentinel;

}

ListIterator listiterator_next(ListIterator iter){
  
  assert( (iter != NULL) && (listiterator_mutation(iter)) );

  iter->cur = iter->cur->next;

  return iter;

}

ListIterator listiterator_previous(ListIterator iter){

  assert( (iter != NULL) && (listiterator_mutation(iter)) );

  iter->cur = iter->cur->previous;

  return iter;

}

void *listiterator_value(ListIterator iter){

  assert( (iter != NULL) && (listiterator_mutation(iter)) );

  return iter->cur->value;

}





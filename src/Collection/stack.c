
#include "stack.h"


typedef struct s_Node {
  void *value;
  struct s_Node *previous;
  struct s_Node *next;
} *Node;

struct s_Stack {
  Node sentinel;
  int size;
  bool mutation;
};


Stack stack_new(void){

  Stack s = malloc(sizeof(struct s_Stack));
  
  if(!s){
    perror("stack_new()");
    exit(QUEUE_INIT);
  }

  s->sentinel = malloc(sizeof(struct s_Node));
  
  if(!s->sentinel){
    perror("stack_new()");
    exit(SENTINEL_INIT);
  }

  s->sentinel->value = NULL;
  s->sentinel->previous = s->sentinel;
  s->sentinel->next = s->sentinel;
  s->size = 0;
  s->mutation = true;
  
  return s;

}

void stack_destruct(Stack s){
  
  assert(s != NULL);

  while(!stack_isEmpty(s))
    stack_pop(s);

  free(s->sentinel);
  s->sentinel = NULL;
  
  free(s);
  s = NULL;

}

int stack_size(const Stack s){
  
  assert(s != NULL);

  return s->size;

}

bool stack_isEmpty(const Stack s){

  assert(s != NULL);
  
  return !s->size;

}

void* stack_top(const Stack s){

  assert( (s != NULL) && (!stack_isEmpty(s)) );

  return s->sentinel->next->value;

}

Stack stack_push(Stack s, void *e){

  assert( (s != NULL) && (e != NULL) );

  Node new = malloc(sizeof(struct s_Node));
  
  if(!new){
    perror("stack_push()");
    exit(ELEMENT_INIT);
  }
  
  Node sentinel = s->sentinel;
  new->value = e;
  new->previous = sentinel;
  new->next = sentinel->next;
  sentinel->next->previous = new;
  sentinel->next = new;
  ++s->size;
  s->mutation = true;
  
  return s;

}

Stack stack_pop(Stack s){

  assert( (s != NULL) );

  Node old = s->sentinel->next;
  
  old->previous->next = old->next;
  old->next->previous = old->previous;
  
  --s->size;
  s->mutation = true;
  
  free(old);
  old = NULL;

  return s;

}

void stack_map(Stack s, void* f(void *e)){

  assert( (s != NULL) );

  for(Node cur = s->sentinel->next; cur != s->sentinel; cur = cur->next)
    cur->value = f(cur->value);
  
}

struct s_StackIterator {
  Node sentinel; 
  Node cur;
  bool *mutation;
};

StackIterator stackiterator_new(Stack s){
  
  assert( s != NULL );

  StackIterator iter = malloc(sizeof(struct s_StackIterator));
  
  if(!iter){
    perror("stackiterator_new()");
    exit(ITERATOR_INIT);
  }
  
  iter->sentinel = s->sentinel;
  iter->cur = iter->sentinel;
  s->mutation = false;
  iter->mutation = &s->mutation;
  

  return iter;

}

void stackiterator_destruct(StackIterator iter){

  assert( (iter != NULL) );
  
  free(iter);
  iter = NULL;

}

bool stackiterator_mutation(StackIterator iter){
  
  assert( (iter != NULL) );
  
  return iter->mutation;

}

bool stackiterator_isValid(StackIterator iter){

  assert( (iter != NULL) );
  
  return iter->sentinel != NULL;

}

StackIterator stackiterator_reset(StackIterator iter){
  
  assert( (iter != NULL) && (stackiterator_isValid(iter)) );
  
  iter->cur = iter->sentinel;
  
  return iter;

}


bool stackiterator_hasnext(StackIterator iter){
  
  assert( (iter != NULL) && (stackiterator_mutation(iter)) );
  
  return iter->cur->next != iter->sentinel;

}

StackIterator stackiterator_next(StackIterator iter){
  
  assert( (iter != NULL) && (stackiterator_mutation(iter)) );

  iter->cur = iter->cur->next;

  return iter;

}

StackIterator stackiterator_previous(StackIterator iter){

  assert( (iter != NULL) && (stackiterator_mutation(iter)) );

  iter->cur = iter->cur->previous;

  return iter;

}

void *stackiterator_value(StackIterator iter){

  assert( (iter != NULL) && (stackiterator_mutation(iter)) );

  return iter->cur->value;

}




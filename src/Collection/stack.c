#include "stack.h"

#define STACK_INIT 100
#define CONS_ELMT 99

typedef struct s_Node {
  void* value;
  struct s_Node *next;
} *Node;

struct s_Stack {
  Node top;
  int size;
};


Stack stack_new(void){

  Stack s = malloc(sizeof(struct s_Stack));
  
  if(!s){
    perror("stack_new()");
    exit(STACK_INIT);
  }
  
  s->top = NULL;
  s->size = 0;
  
  return s;

}

Stack stack_push(Stack s, void *e){
  assert( (s != NULL) && (e != NULL) );
  Node new = malloc(sizeof(struct s_Node));
  
  if(!new){
    perror("stack_push()");
    exit(CONS_ELMT);
  }
  
  new->value = e;
  new->next = s->top;
  s->top = new;
  ++s->size;
  
  return s;

}

Stack stack_pop(Stack s){
  assert( (s != NULL) && (stack_isEmpty(s) == 0) );
  Node old = s->top;
  
  s->top = old->next;
  --s->size;
  free(old);
  
  return s;
  
}

void* stack_top(const Stack s){
  assert( (s != NULL) && (stack_isEmpty(s) == 0) );
  return s->top->value;
}

int stack_size(const Stack s){
  assert( (s != NULL) );
  return s->size;
}

bool stack_isEmpty(const Stack s){
  assert( (s != NULL) );
  return !s->size;
}

void stack_destruct(Stack s){
  assert( (s != NULL) );
  while(!stack_isEmpty(s))
    stack_pop(s);
  free(s);
}

void stack_map(Stack s, void* f(void *e)){
  assert( (s != NULL) );
  for(Node cur = s->top; cur != NULL; cur = cur->next)
    cur->value = f(cur->value);
}



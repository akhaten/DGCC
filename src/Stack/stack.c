#include <stdio.h>
#include <stdlib.h>

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

  Node old = s->top;
  
  s->top = old->next;
  --s->size;
  free(old);
  
  return s;
  
}

void* stack_top(const Stack s){
  return s->top->value;
}

int stack_size(const Stack s){
  return s->size;
}

int stack_isEmpty(const Stack s){
  return s->top == NULL; 
}

void stack_destruct(Stack s){
  while(!stack_isEmpty(s))
    stack_pop(s);
  free(s);
}

void stack_map(Stack s, void* f(void *)){
  for(Node cur = s->top; cur != NULL; cur = cur->next)
    cur->value = f(cur->value);
}



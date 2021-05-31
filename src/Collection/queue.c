
#include "queue.h"

typedef struct s_Node {
  void *value;
  struct s_Node *previous;
  struct s_Node *next;
} *Node;

struct s_Queue {
  Node sentinel;
  int size;
  bool mutation;
};


Queue queue_new(void){

  Queue q = malloc(sizeof(struct s_Queue));
  
  if(!q){
    perror("queue_new()");
    exit(QUEUE_INIT);
  }

  q->sentinel = malloc(sizeof(struct s_Node));
  
  if(!q->sentinel){
    perror("queue_new()");
    exit(SENTINEL_INIT);
  }

  q->sentinel->value = NULL;
  q->sentinel->previous = q->sentinel;
  q->sentinel->next = q->sentinel;
  q->size = 0;
  q->mutation = true;
  
  return q;

}

void queue_destruct(Queue q){
  
  assert(q != NULL);

  while(!queue_isEmpty(q))
    queue_pop(q);

  free(q->sentinel);
  q->sentinel = NULL;
  
  free(q);
  q = NULL;

}

int queue_size(const Queue q){
  
  assert(q != NULL);

  return q->size;

}

bool queue_isEmpty(const Queue q){

  assert(q != NULL);
  
  return !q->size;

}

void* queue_top(const Queue q){

  assert( (q != NULL) && (!queue_isEmpty(q)) );

  return q->sentinel->previous;

}

Queue queue_push(Queue q, void *e){

  assert( (q != NULL) && (e != NULL) );

  Node new = malloc(sizeof(struct s_Node));
  
  if(!new){
    perror("list_add()");
    exit(ELEMENT_INIT);
  }
  
  Node sentinel = q->sentinel;
  new->value = e;
  new->previous = q->sentinel->next;
  new->next = sentinel;
  new->previous->next = new;
  new->next->previous = new;
  ++q->size;
  q->mutation = true;
  
  return q;

}

Queue queue_pop(Queue q){

  assert( (q != NULL) );

  Node old = q->sentinel->previous;
  
  Node sentinel = q->sentinel;
  
  old->previous->next = old->next;
  old->next->previous = old->previous;
  
  --q->size;
  q->mutation = true;
  
  free(old);
  old = NULL;

  return q;

}

void queue_map(Queue q, void* f(void *e)){

  assert( (q != NULL) );
  
  for(Node cur = queue_top(q); cur != NULL; cur = cur->next)
    cur->value = f(cur->value);

}
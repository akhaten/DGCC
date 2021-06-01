
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

  return q->sentinel->next->value;

}

Queue queue_push(Queue q, void *e){

  assert( (q != NULL) && (e != NULL) );

  Node new = malloc(sizeof(struct s_Node));
  
  if(!new){
    perror("queue_push()");
    exit(ELEMENT_INIT);
  }
  
  Node sentinel = q->sentinel;
  new->value = e;
  new->previous = sentinel->previous;
  new->next = sentinel;
  sentinel->previous->next = new;
  sentinel->previous = new;
  ++q->size;
  q->mutation = true;
  
  return q;

}

Queue queue_pop(Queue q){

  assert( (q != NULL) );

  Node old = q->sentinel->next;
  
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

  for(Node cur = q->sentinel->next; cur != q->sentinel; cur = cur->next)
    cur->value = f(cur->value);
  
}

struct s_QueueIterator {
  Node sentinel; 
  Node cur;
  bool *mutation;
};

QueueIterator queueiterator_new(Queue l){
  
  assert( l != NULL );

  QueueIterator iter = malloc(sizeof(struct s_QueueIterator));
  
  if(!iter){
    perror("queueiterator_new()");
    exit(ITERATOR_INIT);
  }
  
  iter->sentinel = l->sentinel;
  iter->cur = iter->sentinel;
  l->mutation = false;
  iter->mutation = &l->mutation;
  

  return iter;

}

void queueiterator_destruct(QueueIterator iter){

  assert( (iter != NULL) );
  
  free(iter);
  iter = NULL;

}

bool queueiterator_mutation(QueueIterator iter){
  
  assert( (iter != NULL) );
  
  return iter->mutation;

}

bool queueiterator_isValid(QueueIterator iter){

  assert( (iter != NULL) );
  
  return iter->sentinel != NULL;

}

QueueIterator queueiterator_reset(QueueIterator iter){
  
  assert( (iter != NULL) && (queueiterator_isValid(iter)) );
  
  iter->cur = iter->sentinel;
  
  return iter;

}


bool queueiterator_hasnext(QueueIterator iter){
  
  assert( (iter != NULL) && (queueiterator_mutation(iter)) );
  
  return iter->cur->next != iter->sentinel;

}

QueueIterator queueiterator_next(QueueIterator iter){
  
  assert( (iter != NULL) && (queueiterator_mutation(iter)) );

  iter->cur = iter->cur->next;

  return iter;

}

QueueIterator queueiterator_previous(QueueIterator iter){

  assert( (iter != NULL) && (queueiterator_mutation(iter)) );

  iter->cur = iter->cur->previous;

  return iter;

}

void *queueiterator_value(QueueIterator iter){

  assert( (iter != NULL) && (queueiterator_mutation(iter)) );

  return iter->cur->value;

}
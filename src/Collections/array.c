#include "array.h"
#include "errors.h"

#define SIZEDEFAULT 10


struct s_Array {
  GenericElement *tab;
  unsigned int size;
  unsigned int size_max;
};


Array array_new(){

  Array a = malloc(sizeof(struct s_Array));

  if(!a){
    perror("array_new()");
    exit(ARRAY_INIT);
  }

  a->tab = malloc(SIZEDEFAULT*sizeof(GenericElement));

  if(!(a->tab)){
    perror("array_new()");
    exit(ARRAY_INIT);
  }

  a->size = 0;
  a->size_max = SIZEDEFAULT;

  return a;

}


void array_destruct(Array a){
  assert( (a != NULL) );
  free(a->tab);
  a->tab = NULL;
  free(a);
  a = NULL;
}


bool array_isEmpty(const Array a){
  assert( (a != NULL) );
  return a->size == 0;
}


unsigned int array_size(const Array a){
  assert( (a != NULL) );
  return a->size;
}


Array array_add(Array a, const GenericElement e){
  
  assert( (a != NULL) && (e != NULL) );

  if(a->size_max <= a->size){
    a->size_max *= 2;
    a->tab = realloc(a->tab, a->size_max*sizeof(GenericElement));
  }

  a->tab[a->size] = e;
  ++(a->size);

  return a;

}


Array array_swap(Array a, const unsigned int index1, const unsigned int index2){

  assert( (a != NULL) && (index1 < a->size) && (index2 < a->size) );
  
  GenericElement *tmp = a->tab[index1];
  a->tab[index1] = a->tab[index2];
  a->tab[index2] = tmp;
  
  return a;

}


Array array_insert(Array a, const unsigned int index, const GenericElement e){

  assert( (a != NULL) && (index < a->size) && (e != NULL) );

  a = array_add(a, e);
  for(int cur = a->size-1; index < cur; --cur){
    a = array_swap(a, cur, cur-1);
  }

  return a;

}


Array array_remove(Array a, const unsigned int index){

  assert( (a != NULL) && (index < a->size) );

  for(int cur = index; cur < a->size-1; ++cur){
    a->tab[cur] = a->tab[cur+1];
  }

  --(a->size);

  return a;

}


GenericElement array_get(const Array a, const unsigned int index){
  assert( (a != NULL) && (index < a->size) );
  return a->tab[index]; 
}


Array array_map(Array a, FunctionMap f){

  assert( (a != NULL) );

  for(int index = 0; index < a->size; ++index){
    a->tab[index] = f(a->tab[index]);
  }

  return a;

}


GenericElement array_reduce(Array a, FunctionReduce f, GenericElement data){

  assert( (a != NULL) );

  for(int index = 0; index < a->size; ++index)
    f(a->tab[index], data);
  
  return data;

}
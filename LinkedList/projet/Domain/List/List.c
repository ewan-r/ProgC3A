#include "List.h"

void list_init(List *list, void (*destroy)(void *data)){
  list->size = 0;
  list->destroy = destroy;
  list->match = NULL;
  list->head = NULL;
  list->tail = NULL;
}

int list_ins_next(List *list, ListElmt *element, const void *data){
  ListElmt *new;
  new = malloc(sizeof(ListElmt));
  if (new==NULL)
    return -1;
  new->data=data;

  if (element == NULL){
    if(list->size==0)
      list->tail=new;
    new->next = list->head;
    list->head=new;
  }
  else{
    new->next = element->next;
    element->next = new;
    if(new->next==NULL) 
      list->tail = new;
  }
  list->size++;
  return 0;
}

int list_rem_next(List *list, ListElmt *element, void **data){
  ListElmt *old;
  if (list->size==0)
    return -1;

  if(element == NULL){
    old = list->head;
    if(list->size == 0)
      list->tail=NULL;
    list->head=old->next;
  }
  else{
    if(element == list->tail)
      return -1;
    old = element->next;
    if(old == list->tail)
      list->tail=element;
    element->next=old->next;
  }
  *data = old->data;
  free(old);
  list->size --;
  return 1;
}
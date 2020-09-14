// list/list.c
// 
// Implementation for linked list.
//
// <Author>

#include <stdio.h>
#include <stdlib.h>

#include "list.h"

list_t *list_alloc() { 
  // source: https://www.learn-c.org/en/Linked_lists & https://www.geeksforgeeks.org/how-to-pass-or-return-a-structure-to-from-a-function-in-c-c/
  printf("Allocating Memory... \n");
  
  list_t * l = malloc(sizeof(list_t));
  node_t * head = malloc(sizeof(node_t));
  
  l->head = head;
  printf("Memory Allocated \n");
  return (l);
}
void list_free(list_t *l) {
  
  printf("Freeing Memory... \n");
  
  free(l);
  
  printf("Memory Freed \n");
}

void list_print(list_t *l) {
  
  
  node_t * trav = l->head;
  printf("Printing... \n");
  if(trav != NULL) {
    
    while(trav->next != NULL) {      
      trav = trav->next;
      printf("%d\n", trav->value);
    }
    
    
      
  }else{
    printf("empty list \n"); 
  }
  printf("\n");
}

int list_length(list_t *l) { 
  node_t * trav = l->head;
  int count = 0;
  printf("Counting... \n");
  if(trav != NULL) {
    while(trav->next != NULL) {
      count++;
      trav = trav->next;
    }
  }else{
    return 0;
  }
  
  return count; 
}

void list_add_to_back(list_t *l, int value) {
  node_t * trav = l->head;
  node_t * new = malloc(sizeof(node_t));
  new->value = value;
  new->next = NULL;
  printf("Adding item to end of list... \n");
  if(trav != NULL){
    while(trav->next != NULL) {
      trav = trav->next;
    }
    trav->next = new;
    trav->next->next = NULL;
  }else{
    trav = new;
    trav->next = NULL;
  }
  
  
  printf("Done.\n");
}

void list_add_to_front(list_t *l, elem value) {
  node_t * new = malloc(sizeof(node_t));
  l->head->value = value;
  
  new->next = l->head;
  l->head = new;
}

void list_add_at_index(list_t *l, elem value, int index) {
  int count = 0;
  node_t * trav = l->head;
  node_t * new = malloc(sizeof(node_t));
  new->value = value;
  index-=1;
  while(count < index) {
    count++;
    printf("count %d\n", count);
    trav = trav->next;
  }
  new->next = trav->next;
  trav->next = new;
}

int list_remove_from_back(list_t *l) { 
  node_t * trav = l->head;
  node_t * prev;
  int removedNum;
  while(trav->next != NULL) {
    prev = trav;
    trav = trav->next;
  }
  
  removedNum = trav->value;
  prev->next = NULL;
  free(trav);
  return removedNum; 
}

int list_remove_from_front(list_t *l) { 
  node_t * old = l->head;
  
  int removedNum = old->value;
  
  l->head = l->head->next;
  free(old);
  return removedNum; 
}

int list_remove_at_index(list_t *l, int index) { 
  int count = 0;
  int removedNum;
  node_t * trav = l->head;
  node_t * prev = malloc(sizeof(node_t));
  node_t * old = malloc(sizeof(node_t));
  
  while(count < index) {
    count++;
    prev = trav;
    trav = trav->next;
  }
  
  old = trav;
  removedNum = old->value;
  prev->next = trav->next;
  free(old);
  return removedNum; 
}

bool list_is_in(list_t *l, int value) { 
  int Num;
  node_t * trav = l->head;
  while(trav->next != NULL) {
    Num = trav->value;
    trav = trav->next;
    if(Num == value) {
      return true;
    }
  }
  return false; 
}

int list_get_elem_at(list_t *l, int index) { 
  int count = 0;
  int foundNumNum;
  node_t * trav = l->head;
  
  
  while(count < index) {
    count++;
    trav = trav->next;
  }
  foundNumNum = trav->value;
  return foundNumNum; 
}

int list_get_index_of(list_t *l, int value) { 
  int count = 0;
  node_t * trav = l->head;
  while(trav->next != NULL) {
    count++;
    trav = trav->next;
    if(trav->value == value) {
      return count;
    }
  }
  printf("Failed \n");
  return 0;  
} 

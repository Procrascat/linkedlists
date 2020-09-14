#include <stdio.h>

#include "list.h"
#include <stdlib.h>

int main() {
  printf("Tests for linked list implementation\n");
  list_t *Test = list_alloc();
  
  list_print(Test);
  printf("%d\n", list_length(Test));
  list_add_to_back(Test, 5);
  list_add_to_back(Test, 5);
  list_add_to_front(Test, 6);
  list_add_to_back(Test, 9);
  list_add_to_back(Test, 23);
  list_add_to_front(Test, 43);
  
  list_print(Test);
  printf("Length: %d\n", list_length(Test));
  
  list_add_at_index(Test, 9, 3);
  list_print(Test);
  printf("Length: %d\n", list_length(Test));
  
  printf("Removed: %d\n", list_remove_from_back(Test));
  
  list_print(Test);
  printf("Length: %d\n", list_length(Test));
  
  printf("Removed: %d\n", list_remove_from_front(Test));
  
  list_print(Test);
  printf("Length: %d\n", list_length(Test));
  
  printf("Removed: %d\n", list_remove_at_index(Test, 3));
  
  list_print(Test);
  printf("Length: %d\n", list_length(Test));
  
  printf("5 is in: %d\n", list_is_in(Test, 5));
  
  printf("Element at index 2: %d\n", list_get_elem_at(Test, 2));
  
  printf("Index of 9: %d\n", list_get_index_of(Test, 9));
  
  list_free(Test);
  
  return 0;
}
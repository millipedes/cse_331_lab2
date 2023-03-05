#ifndef MEM_H
#define MEM_H

#include <stdio.h>
#include <stdlib.h>

typedef struct MEMORY_REF_T {
  char load_store;
  int address;
  int since_last_access;
} * memory_ref;

memory_ref init_memory_ref(char load_store, int address, int since_last_access);
void debug_memory_ref(memory_ref the_memory_ref);
void free_memory_ref(memory_ref the_memory_ref);

#endif

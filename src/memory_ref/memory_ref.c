#include "include/memory_ref.h"

memory_ref init_memory_ref(char load_store, int address,
    int since_last_access) {
  memory_ref the_memory_ref = calloc(1, sizeof(struct MEMORY_REF_T));
  the_memory_ref->load_store = load_store;
  the_memory_ref->address = address;
  the_memory_ref->since_last_access = since_last_access;
  return the_memory_ref;
}

void debug_memory_ref(memory_ref the_memory_ref) {
  printf("[MEMORY_REF]: ");
  printf("`%c` ", the_memory_ref->load_store);
  printf("`%d`/", the_memory_ref->address);
  printf("`%x` ", the_memory_ref->address);
  printf("`%d`\n", the_memory_ref->since_last_access);
}

void free_memory_ref(memory_ref the_memory_ref) {
  if(the_memory_ref)
    free(the_memory_ref);
}

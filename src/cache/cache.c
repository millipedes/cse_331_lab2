#include "include/cache.h"

cache init_cache(replacement_policy policy, allocation_type alloc_type,
    int miss_penalty, int line_size, int associativity, int data_size) {
  cache the_cache = calloc(1, sizeof(struct CACHE_T));
  the_cache->policy = policy;
  the_cache->alloc_type = alloc_type;
  the_cache->miss_penalty = miss_penalty;
  the_cache->line_size = line_size;
  the_cache->associativity = associativity;
  the_cache->data_size = data_size * KILO;
  the_cache->entries = calloc(data_size * KILO, sizeof(struct MEMORY_REF_T *));
  return the_cache;
}

void debug_cache(cache the_cache) {
  printf("[CACHE]\n");
  printf("Policy: %s\n", replacement_policy_to_string(the_cache->policy));
  printf("Allocation Type: %s\n",
      allocation_type_to_string(the_cache->alloc_type));
  printf("Miss Penalty: %d\n", the_cache->miss_penalty);
  printf("Line Size: %d B\n", the_cache->line_size);
  printf("Associativity: ");
  if(!the_cache->associativity)
    printf("Fully Associative\n");
  else if(the_cache->associativity == 1)
    printf("Direct Mapped\n");
  else
    printf("%d\n", the_cache->associativity);
  printf("Data Size: %d B\n", the_cache->data_size);
  for(int i = 0; i < the_cache->data_size; i++)
    if(the_cache->entries[i])
      debug_memory_ref(the_cache->entries[i]);
}

void free_cache(cache the_cache) {
  if(the_cache) {
    if(the_cache->entries) {
      for (int i = 0; i < the_cache->data_size; i++)
        if(the_cache->entries[i])
          free_memory_ref(the_cache->entries[i]);
      free(the_cache->entries);
    }
    free(the_cache);
  }
}

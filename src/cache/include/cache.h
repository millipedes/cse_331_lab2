#ifndef CAC_H
#define CAC_H

#define KILO 1000

#include "../../memory_ref/include/memory_ref.h"
#include "../../option/include/allocation.h"
#include "../../option/include/replacement_policy.h"

typedef struct CACHE_T {
  memory_ref * entries;
  replacement_policy policy;
  allocation_type alloc_type;
  int miss_penalty;
  int line_size;
  int associativity;
  int data_size;
} * cache;

cache init_cache(replacement_policy policy, allocation_type alloc_type,
    int miss_penalty, int line_size, int associativity, int data_size);
void debug_cache(cache the_cache);
void free_cache(cache the_cache);

#endif

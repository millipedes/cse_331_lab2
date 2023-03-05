#ifndef FIL_H
#define FIL_H

#include <string.h>
#include "../../cache/include/cache.h"
#include "../../main/include/constants_macros.h"

#define ALLOC_INT(n, i) if(!n) n = calloc(i, sizeof(int));    \
                        else n = realloc(n, i * sizeof(int));

cache cache_from_config(char * file_name);
memory_ref memory_ref_from_cache(char * file_name);

#endif

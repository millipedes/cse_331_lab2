#ifndef ALL_H
#define ALL_H

#include <stdlib.h>

typedef enum {
  NO_WRITE_ALLOC,
  WRITE_ALLOC,
} allocation_type;

const char * allocation_type_to_string(allocation_type type);

#endif

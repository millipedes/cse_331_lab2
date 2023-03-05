#include "include/allocation.h"

const char * allocation_type_to_string(allocation_type type) {
  switch(type) {
    case NO_WRITE_ALLOC: return "No Write Allocate";
    case WRITE_ALLOC:    return "Write Allocate";
  }
  return NULL;
}

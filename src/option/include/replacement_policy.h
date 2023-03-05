#ifndef REP_H
#define REP_H

#include <stdlib.h>

typedef enum {
  RANDOM,
  FIFO,
} replacement_policy;

const char * replacement_policy_to_string(replacement_policy policy);

#endif

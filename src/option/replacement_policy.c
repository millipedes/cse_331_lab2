#include "include/replacement_policy.h"

const char * replacement_policy_to_string(replacement_policy policy) {
  switch(policy) {
    case FIFO:   return "FIFO";
    case RANDOM: return "Random";
  }
  return NULL;
}

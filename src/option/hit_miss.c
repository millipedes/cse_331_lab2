#include "include/hit_miss.h"

const char * hit_miss_to_string(hit_miss thm) {
  switch(thm) {
    case HIT:  return "Hit";
    case MISS: return "Miss";
  }
  return NULL;
}

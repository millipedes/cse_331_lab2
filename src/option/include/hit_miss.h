#ifndef HOM_H
#define HOM_H

#include <stdlib.h>

typedef enum {
  HIT,
  MISS,
} hit_miss;

const char * hit_miss_to_string(hit_miss thm);

#endif

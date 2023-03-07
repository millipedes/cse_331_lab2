#ifndef OUTP_H
#define OUTP_H

#include <stdio.h>
#include "../../option/include/hit_miss.h"

typedef struct OUTPUT_T {
  int total_hits;
  int total_misses;
  double total_hit_rate;
  int load_hits;
  int load_misses;
  double load_hit_rate;
  int store_hits;
  int store_misses;
  double store_hit_rate;
  int total_run_time;
  double average_memory_access_lat;
} * output;

output init_output(void);
output update_output(output the_output, char type, hit_miss thm,
    int cycle_time);
output update_total_hit_rate(output the_output);
output update_load_rate(output the_output);
output update_store_rate(output the_output);
void debug_output(output the_output);
void free_output(output the_output);

#endif

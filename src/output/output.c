#include "include/output.h"

output init_output(void) {
  output the_output = calloc(1, sizeof(struct OUTPUT_T));
  the_output->total_hits = 0;
  the_output->total_misses = 0;
  the_output->total_hit_rate = 0.0;
  the_output->load_hits = 0;
  the_output->load_misses = 0;
  the_output->load_hit_rate = 0.0;
  the_output->store_hits = 0;
  the_output->store_misses = 0;
  the_output->store_hit_rate = 0.0;
  the_output->total_run_time = 0;
  the_output->average_memory_access_lat = 0.0;
  return the_output;
}

output update_output(output the_output, char type, hit_miss thm,
    int cycle_time) {
  switch(thm) {
    case HIT:
      the_output->total_hits++;
      switch(type) {
        case 's':
          the_output->store_hits++;
          the_output = update_store_rate(the_output);
          break;
        case 'l':
          the_output->load_hits++;
          the_output = update_load_rate(the_output);
          break;
        default:
          fprintf(stderr, "There was an error your load/store code is: %c\n",
              type);
          exit(1);
      }
      break;
    case MISS:
      the_output->total_misses++;
      switch(type) {
        case 's':
          the_output->store_misses++;
          the_output = update_store_rate(the_output);
          break;
        case 'l':
          the_output->load_misses++;
          the_output = update_load_rate(the_output);
          break;
        default:
          fprintf(stderr, "There was an error your load/store code is: %c\n",
              type);
          exit(1);
      }
      break;
    default:
      fprintf(stderr, "There was an error your hit_miss code is: %d\n", thm);
      exit(1);
  }
  the_output = update_total_hit_rate(the_output);
  the_output->total_run_time += cycle_time;
  return the_output;
}

output update_total_hit_rate(output the_output) {
  the_output->total_hit_rate = (double)the_output->total_hits
    / ((double)the_output->total_misses + (double)the_output->total_hits);
  return the_output;
}

output update_load_rate(output the_output) {
  the_output->load_hit_rate = (double)the_output->load_hits
    / ((double)the_output->load_misses + (double)the_output->load_hits);
  return the_output;
}

output update_store_rate(output the_output) {
  the_output->store_hit_rate = (double)the_output->store_hits
    / ((double)the_output->store_misses + (double)the_output->store_hits);
  return the_output;
}

void debug_output(output the_output) {
  printf("[OUTPUT]\n");
  printf("Total Hit Rate: %f\n", the_output->total_hit_rate);
  printf("Load Hit Rate: %f\n", the_output->load_hit_rate);
  printf("Store Hit Rate: %f\n", the_output->store_hit_rate);
  printf("Total Run Time: %d\n", the_output->total_run_time);
  printf("Average Memory Access: %f\n", the_output->average_memory_access_lat);
}

void free_output(output the_output) {
  if(the_output)
    free(the_output);
}

#include "include/file_io.h"

cache cache_from_config(char * file_name) {
  FILE * fp = fopen(file_name, "r");
  cache the_cache = NULL;
  int * entries = NULL;
  int index = 1;
  char buf[MAX_LINE_SIZE] = {0};
  while(fgets(buf, MAX_LINE_SIZE, fp)) {
    ALLOC_INT(entries, index)
    entries[index - 1] = atoi(buf);
    index++;
  }
  the_cache = init_cache(entries[3], entries[5], entries[4], entries[0],
      entries[1], entries[2]);
  free(entries);
  fclose(fp);
  return the_cache;
}

memory_ref memory_ref_from_cache(char * file_name) {
  FILE * fp = fopen(file_name, "r");
  int start_index = 0;
  char * buf = calloc(MAX_LINE_SIZE, sizeof(char));
  int * entries = NULL;
  char * tmp = NULL;
// memory_ref init_memory_ref(char load_store, int address, int since_last_access);
  fgets(buf, MAX_LINE_SIZE, fp);
  tmp = strtok(buf + 2, " ");
  start_index = tmp - buf;
  ALLOC_INT(entries, 1)
  entries[0] = atoi(buf + start_index + 2);
  printf("%s\n\n\n\n", buf + start_index);
  tmp = strtok(buf + start_index, " ");
  start_index = tmp - buf;
  ALLOC_INT(entries, 2)
  entries[1] = atoi(buf + start_index + 1);
  memory_ref the_memory_ref = init_memory_ref(buf[0], entries[0],  entries[1]);
  debug_memory_ref(the_memory_ref);
  free_memory_ref(the_memory_ref);
  free(buf);
  free(entries);
  fclose(fp);
  return NULL;
}

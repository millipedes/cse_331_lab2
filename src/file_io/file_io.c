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
  char * buf = calloc(MAX_LINE_SIZE, sizeof(char));
  int * entries = NULL;
  int index = 0;
  fgets(buf, MAX_LINE_SIZE, fp);
  /**
   *    <|>
   * ------------------
   * | s 0x1fffff50 1 |
   * ------------------
   */
  ALLOC_INT(entries, 1)
  NEXT_CHAR(buf, index, ' ')
  entries[0] = charp_to_int(buf + index);
  NEXT_CHAR(buf, index, ' ')
  ALLOC_INT(entries, 2)
  entries[1] = atoi(buf + index);
  memory_ref the_memory_ref = init_memory_ref(buf[0], entries[0],  entries[1]);
  debug_memory_ref(the_memory_ref);
  free_memory_ref(the_memory_ref);
  free(buf);
  free(entries);
  fclose(fp);
  return NULL;
}

/**
 * TODO fix this!
 */
int charp_to_int(char * the_hex) {
  int index = 0;
  int final = 0;
  printf("the_hex: %s\n", the_hex + 2);
  while(the_hex[index + 2] != ' ') {
    switch(the_hex[index + 2]) {
      case '0':                                 break;
      case '1': final += (1  * pow(16, index)); break;
      case '2': final += (2  * pow(16, index)); break;
      case '3': final += (3  * pow(16, index)); break;
      case '4': final += (4  * pow(16, index)); break;
      case '5': final += (5  * pow(16, index)); break;
      case '6': final += (6  * pow(16, index)); break;
      case '7': final += (7  * pow(16, index)); break;
      case '8': final += (8  * pow(16, index)); break;
      case '9': final += (9  * pow(16, index)); break;
      case 'a': final += (10 * pow(16, index)); break;
      case 'b': final += (11 * pow(16, index)); break;
      case 'c': final += (12 * pow(16, index)); break;
      case 'd': final += (13 * pow(16, index)); break;
      case 'e': final += (14 * pow(16, index)); break;
      case 'f': final += (15 * pow(16, index)); break;
    }
    index++;
  }
  return final;
}

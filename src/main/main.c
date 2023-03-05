#include "../file_io/include/file_io.h"

int main(void) {
  cache the_cache = cache_from_config("./test.conf");
  memory_ref_from_cache("./test.trace");
  debug_cache(the_cache);
  free_cache(the_cache);
  return 0;
}

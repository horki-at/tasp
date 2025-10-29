#include "path.ih"

void path_copy(size_t *dest, size_t *src, size_t size)
{
  for (size_t i = 0; i != size; ++i)
    dest[i] = src[i];
}

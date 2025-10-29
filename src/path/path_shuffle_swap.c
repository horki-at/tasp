#include "path.ih"

void path_shuffle_swap(size_t *path, size_t size)
{
  Pair pair = get_random_pair(size);
  swap(path + pair.idx1, path + pair.idx2);
}

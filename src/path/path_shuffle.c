#include "path.ih"

int path_shuffle(size_t *path, size_t size)
{                               // we have 3 method to shuffle
  static void (*shuffle[3])(size_t *, size_t) = { 
    &path_shuffle_swap,
    &path_shuffle_invert,
    &path_shuffle_shift,
  };

  int const shuffle_method = rand() % 3;
  (*shuffle[shuffle_method])(path, size);

  return shuffle_method;
}

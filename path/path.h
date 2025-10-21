#ifndef INCLUDED_PATH_
#define INCLUDED_PATH_

#include "../graph/graph.h"

#include <stddef.h>


size_t *path_init(size_t size);
void path_copy(size_t *dest, size_t *src, size_t size);

float path_compute(Graph graph, size_t *path);  // computes path cost

int path_shuffle(size_t *path, size_t size);

void path_shuffle_display(int method); // display the path shuffle method
void path_display(size_t *path, size_t size);


#endif

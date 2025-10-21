#include "path.ih"

size_t *path_init(size_t size)
{
	size_t *path = malloc(size * sizeof(size_t));
																// initial path: 0 1 2 ... n-2 n-1
	for (size_t i = 0; i != size; ++i)
		path[i] = i;

	return path;
}

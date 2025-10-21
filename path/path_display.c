#include "path.ih"

void path_display(size_t *path, size_t size)
{
	printf("[ ");
	for (size_t i = 0; i != size; ++i)
		printf("%zu ", path[i]);
	printf("]\n");
}
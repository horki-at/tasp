#include "path.ih"

void path_shuffle_shift(size_t *path, size_t size)
{
	size_t *tmp = malloc(size * sizeof(size_t));
	
																// perform cyclic shift and store in tmp
	for (size_t i = 0; i != size; ++i)
		tmp[i] = path[(i + 1) % size];

	path_copy(path, tmp, size);		// copy tmp back into path
	free(tmp);
}

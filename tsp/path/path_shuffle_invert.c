#include "path.ih"

void path_shuffle_invert(size_t *path, size_t size)
{
	Pair pair = get_random_pair(size);
																// invert segment [idx1..idx2]
	size_t left = pair.idx1;
	size_t right = pair.idx2;
	while (left < right)
		swap(path + left++, path + right--);
}

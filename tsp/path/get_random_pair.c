#include "path.ih"

Pair get_random_pair(size_t size)
{																				 // 0 <= idx1 <= idx2 < n
	size_t const idx1 = rand() % size;
	size_t const idx2 = rand() % size;

	return (Pair){
		.idx1 = (idx1 < idx2) ? idx1 : idx2,
		.idx2 = (idx1 < idx2) ? idx2 : idx1,
	};
}
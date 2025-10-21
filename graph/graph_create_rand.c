#include "graph.ih"

Graph graph_create_rand(size_t size, int min, int max)
{
	Graph graph = {
		.size = size,
		.data = malloc(size * sizeof(Vertex)),
		.distance = (void *)0,
	};

	for (size_t i = 0; i != size; ++i)
	{
		graph.data[i].x = min + rand() % (max - min + 1);
		graph.data[i].y = min + rand() % (max - min + 1);
	}

	precompute_distances(&graph);
	return graph;
}

#include "graph.ih"

void graph_distances_display(Graph graph)
{
	printf("Distances:\n");
	printf("===========================================\n");
	for (size_t i = 0; i != graph.size; ++i)
	{
		for (size_t j = 0; j != graph.size; ++j)
			printf("%.2f ", graph.distance[i * graph.size + j]);
		printf("\n");
	}
	printf("===========================================\n");
}

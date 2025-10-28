#include "graph.ih"

void graph_display(Graph graph)
{
	printf("Graph.\n");
	printf("===========================================\n");
	printf("Size = %zu\n", graph.size);

	printf("Cities:\n");
	for (size_t i = 0; i != graph.size; ++i)
		printf("%zu: (x=%d, y=%d)\n", i, graph.data[i].x, graph.data[i].y);
	printf("===========================================\n");
}

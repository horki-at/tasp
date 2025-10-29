#include "graph.ih"

Graph graph_create_stdin(void)
{
  Graph graph = {0};
  scanf("%zu", &graph.size);    // get graph size

                                // get graph vertices
  graph.data = malloc(graph.size * sizeof(Vertex));
  for (size_t i = 0; i != graph.size; ++i)
    scanf("%d %d", &graph.data[i].x, &graph.data[i].y);

  precompute_distances(&graph);
  return graph;
}

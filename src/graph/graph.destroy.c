#include "graph.ih"

void graph_destroy(Graph graph)
{
  free(graph.data);
  free(graph.distance);
}

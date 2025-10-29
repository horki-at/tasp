#include "path.ih"

float path_compute(Graph graph, size_t *path)
{
  float cost = 0;

  for (size_t i = 0; i != graph.size; ++i)
  {
    size_t from = path[i];
    size_t to = path[(i + 1) % graph.size];
    cost += graph.distance[from * graph.size + to];
  }

  return cost;
}

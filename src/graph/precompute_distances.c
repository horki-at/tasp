#include "graph.ih"

void precompute_distances(Graph *graph)
{
  graph->distance = malloc(graph->size * graph->size * sizeof(float));
  
  for (size_t i = 0; i != graph->size; ++i)
  {
    graph->distance[i * graph->size + i] = 0;  // dist(A, A) = 0
    for (size_t j = i + 1; j != graph->size; ++j) 
    {
      int dx = graph->data[i].x - graph->data[j].x;
      int dy = graph->data[i].y - graph->data[j].y;
      float dist = sqrtf(dx * dx + dy * dy);

      graph->distance[i * graph->size + j] = // dist(A, B) = dist(B, A)
        graph->distance[j * graph->size + i] = dist;
    }
  }
}

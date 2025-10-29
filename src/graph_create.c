#include "main.ih"

Graph graph_create(Config const *config)
{
  Graph graph;

  switch (config->mode)
  {
  case MODE_RANDOM:
    graph = graph_create_rand(config->size, config->min, config->max);
    break;
  case MODE_STDIN:
    graph = graph_create_stdin();
    break;
  default:                      // shouldn't happen
  }

  return graph;
}

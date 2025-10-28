#include "main.ih"

void action_path(Config const *config, Graph graph)
{
  size_t *solution = sim_annealing(graph, config->T, config->T_aim,
                                   config->noimpr_aim, config->m, NULL);

  path_display(solution, graph.size);
  free(solution);
}

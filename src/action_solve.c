#include "main.ih"

void action_solve(Config const *config, Graph graph)
{
  size_t *solution = sim_annealing(graph, config->T, config->T_aim,
                                   config->noimpr_aim, config->m, NULL);
  printf("%f\n", path_compute(graph, solution));
  free(solution);
}

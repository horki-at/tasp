#include "main.ih"

void action_plot(Config const *config, Graph graph)
{
  FILE *out = fopen("data", "w");
  if (!out)
  {
    printf("Unable to open the stream.\n");
    exit(1);
  }
  
  free(sim_annealing(graph, config->T, config->T_aim,
                     config->noimpr_aim, config->m, out));
  run_gnuplot("plot.gnu", config->output);
}

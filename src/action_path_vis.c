#include "main.ih"

void action_path_vis(Config const *config, Graph graph)
{
  FILE *out = fopen("data", "w");
  if (!out)
  {
    printf("Unable to open the stream.\n");
    exit(1);
  }

  size_t *solution = sim_annealing(graph, config->T, config->T_aim,
                                   config->noimpr_aim, config->m, NULL);

                                // write the graph coordintes into out
  for (size_t i = 0; i != graph.size; ++i)
    fprintf(out, "%d %d %zu\n", graph.data[i].x, graph.data[i].y, i);
                                // write the path into out
  fprintf(out, "\n");
  for (size_t i = 0; i != graph.size + 1; ++i)
    fprintf(out, "%zu\n", solution[i % graph.size]); // include the start vertex

  if (out)
    fclose(out);
  free(solution);
  
  run_gnuplot("solve.gnu", config->output);
}

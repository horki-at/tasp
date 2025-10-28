#include "main.ih"

void action_graph_vis(Config const *config, Graph graph)
{
	FILE *out = fopen("data", "w");
	if (!out)
	{
		printf("Unable to open the stream.\n");
		exit(1);
	}
                                // write the graph coordintes into out
  for (size_t i = 0; i != graph.size; ++i)
    fprintf(out, "%d %d %zu\n", graph.data[i].x, graph.data[i].y, i);

  if (out)
    fclose(out);

  run_gnuplot("graph.gnu", config->output);
}

#include "main.ih"

static void (*action_dispatch[])(Config const *, Graph) = {
  &action_plot,                 // ACTION_PLOT
  &action_solve,                // ACTION_SOLVE
  &action_solve_vis,            // ACTION_SOLVE_VIS
  &action_graph,                // ACTION_GRAPH
  &action_graph_vis,            // ACTION_GRAPH_VIS
  &action_graph_vis_nol,        // ACTION_GRAPH_VIS_NOL
  &action_distances,            // ACTION_DISTANCES
};

void execute(Config const *config)
{
	srand(config->seed);
  Graph graph = graph_create(config);

  (*action_dispatch[config->action])(config, graph);
  
	graph_destroy(graph);
}

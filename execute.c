#include "main.ih"

void execute(Config config)
{
	srand(config.seed);

	Graph graph;
	switch (config.mode)
	{
	case MODE_RANDOM:
		graph = graph_create_rand(config.size, config.min, config.max);
		break;
	case MODE_STDIN:
		graph = graph_create_stdin();
		break;
	default:											// shouldn't happen
	}

	FILE *out = fopen("data", "w");
	if (!out)
	{
		printf("Unable to open the stream.\n");
		exit(1);
	}

	solve(graph, config.T, config.T_aim, config.noimpr_aim, config.m, out);
	system("gnuplot plot.gnu && rm data");

	graph_destroy(graph);
}

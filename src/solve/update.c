#include "solve.ih"

float update(Graph graph, size_t *best, size_t *candidate, float T)
{
	float const										// compute delta cost of best and candidatest
		best_cost      = path_compute(graph, best),
		candidate_cost = path_compute(graph, candidate),
		delta_cost     = candidate_cost - best_cost;

	float cost = best_cost;
	int accept = 1;								// whether to accept the candidate
	
	if (delta_cost > 0)						// sometimes accept worse candidate
	{
		float const
			prob   = expf(-delta_cost / T),
			choice = (float)rand() / RAND_MAX;

		accept = choice < prob;
	}

	if (accept)
	{
		path_copy(best, candidate, graph.size);
		cost = candidate_cost;
	}

	return cost;
}

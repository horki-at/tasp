#ifndef INCLUDED_SOLVE_
#define INCLUDED_SOLVE_

#include "../graph/graph.h"

#include <stdio.h>
#include <stddef.h>

// Solve TSP using Simulated Annealing.
// Parameters:
// - graph: the graph being solved.
// - T: initial temperature.
// - T_aim: desired temperature.
// - noimpr_aim: desired #iterations without improvement.
// - m: #iterations to be performed per one temperature value.
// - out: stream to store all (temp, cost) pairs for plotting.
// Returns: the best path
size_t *sim_annealing(Graph graph, float T, float T_aim, size_t noimpr_aim,
                      size_t m, FILE *out);

#endif

#ifndef INCLUDED_SOLVER_
#define INCLUDED_SOLVER_

#include "../cities/cities.h"

																// solves TSP using simulating annealing
void solve(Cities cities, size_t temp, size_t M, size_t m);

#endif

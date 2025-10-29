#include "solve.ih"

size_t *sim_annealing(Graph graph, float T, float T_aim, size_t noimpr_aim,
                      size_t m, FILE *out)
{
  size_t *best      = path_init(graph.size); 
  size_t *candidate = path_init(graph.size);
  
  float best_cost = path_compute(graph, best);
  size_t noimpr = 0;            // #iterations with no improvement
  
  while (T > T_aim && noimpr < noimpr_aim) 
  {
    if (out)
      fprintf(out, "%f %f\n", T, best_cost);

    size_t impr = 0;            // #iterations with improvement for T
    
    for (size_t i = 0; i != m; ++i) // repeat m times for the same T
    {
      path_copy(candidate, best, graph.size);
      path_shuffle(candidate, graph.size);

      float const old_best_cost = best_cost;
      best_cost = update(graph, best, candidate, T);

      impr += best_cost < old_best_cost;
    } 
    
    noimpr = (impr) ? (0) : (noimpr + 1);
    T *= 0.99;
  }

  free(candidate);
  return best;
}

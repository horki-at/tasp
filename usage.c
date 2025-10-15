#include "main.ih"

static char const s_usage_info[] = "                                      \n\
Usage: tsp [OPTIONS] [MODE] actions ...args                               \n\
  Options: <optional>                                                     \n\
    --help  (-h)      - displays this message.                            \n\
    --seed  (-s)      - sets the seed for random number generator.        \n\
    --range (-r) a b  - sets the range [a;b) for random number generator. \n\
    --fancy (-f)      - flags to display cities in a fancy manner.        \n\
                                                                          \n\
  Modes: <optional>                                                       \n\
	  rand   - generate random cities (DEFAULT)                             \n\
    args   - input cities via variadic arguments ...args (fmt: <id, x, y>)\n\
    std  n - input n cities via stdin until STOP                          \n\
                                                                          \n\
	Actions: <required at least 1>	                                        \n\
    display     - output cities.                                          \n\
    solve       - finds the shortest path that visits all cities once via \n\
                  the process of simulating annealing.                    \n";

void usage(void)
{
	printf("%s\n", s_usage_info);
}

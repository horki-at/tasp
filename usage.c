#include "main.ih"

																// see parse_arguments.c for long_options
static char const s_usage_info[] = "Usage: tsp [OPTIONS] actions [args]   \n\
  Options: <optional>                                                     \n\
    --help  (-h)       - displays this message.                           \n\
    --seed  (-s) num   - sets the seed for random number generator.       \n\
    --min   (-n) num   - sets the minimum possible coordinate.            \n\
    --max   (-x) num   - sets the maximum possible coordinate.            \n\
    --fancy (-f)       - flags to display cities in a fancy manner.       \n\
    --mode  (-M) str   - specifies the mode of city retrieval             \n\
      Where str:                                                          \n\
        rand    - generate random cities (DEFAULT)                        \n\
        args    - input cities via variadic args (fmt: <id, x, y>)        \n\
        std     - input cities via stdin until STOP (fmt: <id, x, y>)     \n\
                                                                          \n\
	Actions: <required>                 	                                  \n\
    --action (-A) ..action                                                \n\
      Where action:                                                       \n\
          display     - output cities.                                    \n\
          solve       - finds the shortest path that visits all cities    \n\
                        once via simulating annealing.                    \n";

void usage(void)
{
	printf("%s\n", s_usage_info);
}

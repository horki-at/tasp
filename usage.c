#include "main.ih"

																// see parse_arguments.c for long_options
static char const s_usage_info[] = "Usage: %s [OPTIONS] -A action          \n\
Options: <optional>                                                      \n\
  --help      (-h)      - displays this message.                         \n\
  --seed      (-s) num  - seed for RNG (DEFAULT: 69)                     \n\
  --size      (-S) num  - #vertices to generate (DEFAULT: 1000)          \n\
  --min       (-n) num  - minimum coord (DEFAULT: -1000)                 \n\
  --max       (-x) num  - maximum coord (DEFAULT: 1000)                  \n\
  --temp      (-t) num  - initial temperature (DEFAULT: 1000.0f)         \n\
  --tempAim   (-T) num  - desired temperature (DEFAULT: 0.4f)            \n\
  --mParam    (-m) num  - m-parameter (DEFAULT: 10)                      \n\
  --noimprAim (-i) num  - max no-improvement #iterations (DEFAULT: 1000) \n\
  --mode      (-M) str  - specifies the mode of city retrieval           \n\
    Where str:                                                           \n\
      rand    - generate random cities (DEFAULT)                         \n\
      std     - input cities via stdin until STOP (fmt: <id, x, y>)      \n\
Action: <required> at least 1                                            \n\
  --action (-A) str                                                      \n\
    Where str:                                                           \n\
      plot       - plot the cost versus temperature                      \n\
      solve      - print the found path                                  \n\
      solve_vis  - visualize the found path                              \n\
      graph      - print the graph being analyzed                        \n\
      graph_vis  - visualize the graph being analyzed                    \n";

void usage(char const *progname)
{
	printf(s_usage_info, progname);
}

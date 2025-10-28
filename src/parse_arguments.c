#include "main.ih"

static Mode opt_to_mode(const char *str)
{
	if (strcmp(str, "rand") == 0)
		return MODE_RANDOM;
	if (strcmp(str, "std") == 0)
		return MODE_STDIN;

	return MODE_INVALID;
}

static Action opt_to_action(const char *str)
{
  if (strcmp(str, "plot") == 0)
    return ACTION_PLOT;
  if (strcmp(str, "solve") == 0)
    return ACTION_SOLVE;
  if (strcmp(str, "path") == 0)
    return ACTION_PATH;
  if (strcmp(str, "path_vis") == 0)
    return ACTION_PATH_VIS;
  if (strcmp(str, "graph") == 0)
    return ACTION_GRAPH;
  if (strcmp(str, "graph_vis") == 0)
    return ACTION_GRAPH_VIS;
  if (strcmp(str, "graph_vis_nol") == 0)
    return ACTION_GRAPH_VIS_NOL;
  if (strcmp(str, "distances") == 0)
    return ACTION_DISTANCES;

  return ACTION_INVALID;
}

static Config s_config = {			// default configuration 
	.ok         = 1,
	.mode       = MODE_RANDOM,
  .action     = ACTION_GRAPH,
	.seed       = 69,
	.size       = 50,
	.min        = -100,
	.max        = 100,
	.T          = 1000.0f,
	.T_aim      = 0.4f,
	.m          = 10,
	.noimpr_aim = 1000,
  .output     = "result.png",
};

static char const short_options[] = "hs:S:n:x:t:T:m:i:M:o:A:";
static struct option long_options[] = {
	{"help",      no_argument,       0, 'h'},
	{"seed",      required_argument, 0, 's'},
	{"size",      required_argument, 0, 'S'},
	{"min",       required_argument, 0, 'n'},
	{"max",       required_argument, 0, 'x'},
	{"temp",      required_argument, 0, 't'},
	{"tempAim",   required_argument, 0, 'T'},
	{"mParam",    required_argument, 0, 'm'},
	{"noimprAim", required_argument, 0, 'i'},
	{"mode",      required_argument, 0, 'M'},
  {"output",    required_argument, 0, 'o'},
  {"action",    required_argument, 0, 'A'},
	{0, 0, 0, 0}
};

Config parse_arguments(int argc, char **argv)
{
	if (argc == 1)								// no arguments provided, default config
		return s_config;

	while (1)											// while we can parse
	{
		errno = 0;									// for strtoul error checking
		int option_index;
		int short_opt = getopt_long(argc, argv, short_options, long_options,
																&option_index);

		if (short_opt == -1)				// no more options
			break;

		switch (short_opt)
		{
		case 'h':
			usage(argv[0]);
			exit(0);
			break;
		case 's':
			s_config.seed = strtoul(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'S':
			s_config.size = strtoul(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'n':
			s_config.min = strtol(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'x':
			s_config.max = strtol(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 't':
			s_config.T = strtof(optarg, NULL);
			if (errno)
				s_config.ok = 0;
			break;
		case 'T':
			s_config.T_aim = strtof(optarg, NULL);
			if (errno)
				s_config.ok = 0;
			break;
		case 'm':
			s_config.m = strtoul(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'i':
			s_config.noimpr_aim = strtoul(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'M':
			s_config.mode = opt_to_mode(optarg);
			if (s_config.mode == MODE_INVALID)
				s_config.ok = 0;
			break;
    case 'o':
      s_config.output = strdup(optarg);
      break;
    case 'A':
      s_config.action = opt_to_action(optarg);
      if (s_config.action == ACTION_INVALID)
        s_config.ok = 0;
      break;
		default:
			printf("?? getopt returned character code 0%o ??\n", short_opt);
		}
	}

	return s_config;
}

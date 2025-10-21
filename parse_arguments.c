#include "main.ih"

static Mode opt_to_mode(const char *str)
{
	if (strcmp(str, "rand") == 0)
		return MODE_RANDOM;
	if (strcmp(str, "std") == 0)
		return MODE_STDIN;

	return MODE_INVALID;
}

static Config s_config = {			// default configuration 
	.ok         = 1,
	.mode       = MODE_RANDOM,
	.seed       = 69,
	.size       = 1000,
	.min        = -1000,
	.max        = 1000,
	.T          = 1000.0f,
	.T_aim      = 0.4f,
	.m          = 10,
	.noimpr_aim = 1000,
};

static char const short_options[] = "hs:S:n:x:t:T:m:i:M:";
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
		default:
			printf("?? getopt returned character code 0%o ??\n", short_opt);
		}
	}

	return s_config;
}

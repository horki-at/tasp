#include "main.ih"

static Config s_config = {			// default configuration 
	.ok          = 1,
	.argc        = 0,
	.argv        = (void *)0,
	.mode        = MODE_RANDOM,
	.action      = ACTION_INVALID,
	.seed        = 69,
	.min         = -10,
	.max         = 10,
	.temp        = 50,
	.M           = 100,
	.m           = 10,
	.fancy       = 0
};

static char const short_options[] = "hs:n:x:fM:A:";
static struct option long_options[] = {
	{"help",   no_argument,       0, 'h'},
	{"seed",   required_argument, 0, 's'},
	{"min",    required_argument, 0, 'n'},
	{"max",    required_argument, 0, 'x'},
	{"fancy",  no_argument,       0, 'f'},
	{"mode",   required_argument, 0, 'M'},
	{"action", required_argument, 0, 'A'},
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
			s_config.action = ACTION_HELP;
			break;
		case 's':
			s_config.seed = strtoul(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'n':
			s_config.min = strtoul(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'x':
			s_config.max = strtoul(optarg, NULL, 10);
			if (errno)
				s_config.ok = 0;
			break;
		case 'f':
			s_config.fancy = 1;
			break;
		case 'M':
			s_config.mode = opt_to_mode(optarg);
			if (s_config.mode == MODE_INVALID)
				s_config.ok = 0;
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

	if (optind < argc)						// ...args were specified
	{	
		if (s_config.mode != MODE_ARGS) // args must exist only with MODE_ARGS
			s_config.ok = 0;
		else {
			s_config.argc = argc - optind;
			s_config.argv = argv + optind;
		}
	}

	if (s_config.action == ACTION_INVALID || s_config.mode == MODE_INVALID)
		s_config.ok = 0;

	return s_config;
}

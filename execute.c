#include "main.ih"

static Cities (*const s_generate_cities[])(usize argc,
																					 char **argv,
																					 i64 min,
																					 i64 max) = {
	&generate_cities_rand,				// MODE_RANDOM
	&generate_cities_args,        // MODE_ARGS
	&generate_cities_std,         // MODE_STD
};

static void (*const s_dispatch_action[])(Cities cities,
																				 size_t temp,
																				 size_t M,
																				 size_t m) = {
	&display,											// ACTION_DISPLAY
	&solve,                       // ACTION_SOLVE
};

void execute(Config config)
{
	if (config.action == ACTION_HELP)
	{
		usage();
		return;
	}
	
	Cities cities = (*s_generate_cities[config.mode])(config.argc, config.argv,
																										config.min, config.max);
	(*s_dispatch_action[config.action])(cities, config.temp, config.M, config.m);
	destroy_cities(cities);
}

#include "main.ih"

static Config s_config = {			// default configuration 
	.ok          = 0,
	.argc        = 0,
	.argv        = (void *)0,
	.mode        = MODE_RANDOM,
	.action      = ACTION_HELP,
	.seed        = 69,
	.min         = -10,
	.max         = 10,
	.temp        = 50,
	.M           = 100,
	.m           = 10
};

Config parse_arguments(size_t argc, char **argv)
{
	// TODO: do the parsing here.

	return s_config;
}

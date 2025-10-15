#include "display.ih"

void display_config(Config const config)
{
	printf("User's current process configuration is:\n");
	printf("ok: %s\n", config.ok ? "YES" : "NO");

	printf("argc: %zu\n", config.argc);
	printf("argv: ");
	for (usize i = 0; i != config.argc; ++i)
		printf("%s ", config.argv[i]);
	printf("\n");

	switch (config.mode)
	{
	case MODE_RANDOM:
		printf("mode: RANDOM\n");
		break;
	case MODE_ARGS:
		printf("mode: ARGS\n");
		break;
	case MODE_STD:
		printf("mode: STD\n");
		break;
	case MODE_INVALID:
		printf("mode: INVALID\n");
		break;
	}

	switch (config.action)
	{
	case ACTION_DISPLAY:
		printf("action: DISPLAY\n");
		break;
	case ACTION_SOLVE:
		printf("action: SOLVE\n");
		break;
	case ACTION_HELP:
		printf("action: HELP\n");
		break;
	case ACTION_INVALID:
		printf("action: INVALID\n");
		break;
	}

	printf("seed: %zu\n", config.seed);
	printf("range: [%" PRIi64 "; %" PRIi64 ")\n", config.min, config.max);
	printf("temp: %zu\n", config.temp);
	printf("M-parameter: %zu\n", config.M);
	printf("m-parameter: %zu\n", config.m);
	printf("fancy: %s\n", config.fancy ? "YES" : "NO");
	printf("\n");
}

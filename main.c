#include "main.ih"

int main(int argc, char **argv)
{
	Config config = parse_arguments(argc, argv);
	if (!config.ok)
	{
		printf("Invalid arguments: try `tsp --help`\n");
		return 1;
	}

	execute(config);
	return 0;
}

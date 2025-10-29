#include "main.ih"

int main(int argc, char **argv)
{
  Config config = parse_arguments(argc, argv);
  if (!config.ok)
  {
    usage(argv[0]);
    exit(1);
  }

  execute(&config);
  return 0;
}

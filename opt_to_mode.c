#include "main.ih"

Mode opt_to_mode(const char *str)
{
	if (strcmp(str, "rand") == 0)
		return MODE_RANDOM;
	if (strcmp(str, "args") == 0)
		return MODE_ARGS;
	if (strcmp(str, "std") == 0)
		return MODE_STD;

	return MODE_INVALID;
}

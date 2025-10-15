#include "main.ih"

Action opt_to_action(const char *str)
{
	if (strcmp(str, "display") == 0)
		return ACTION_DISPLAY;
	if (strcmp(str, "solve") == 0)
		return ACTION_SOLVE;

	return ACTION_INVALID;
}

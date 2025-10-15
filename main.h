#ifndef INCLUDED_MAIN_
#define INCLUDED_MAIN_

#include "utils.h"

typedef enum
{
	MODE_RANDOM,									// generate cities randomly.
	MODE_ARGS,										// input cities via cli arguments.
	MODE_STD,											// input cities via stdin.
	MODE_INVALID,
} Mode;

typedef enum
{
	ACTION_DISPLAY,
	ACTION_SOLVE,
	ACTION_HELP,
	ACTION_INVALID
} Action;

typedef struct
{
	b8     ok;										// whether parsing was successful
	usize   argc;				  				// number of variadic arguments (..args)
	char    **argv;               // variadic arguments (...args)
	Mode    mode;									// input mode for cities
	Action  action;								// action that will be executed
	usize  seed;									// seed for RNG
	i64 min, max;		    					// range [min;max) coordinates for cities
	usize  temp;									// temperature for SA
	usize  M;                     // M-parameter for SA
	usize  m;					  				  // m-parameter for SA
	b8 fancy;                     // whether to display in a fancy manner
} Config;

#endif

#ifndef INCLUDED_CITIES_
#define INCLUDED_CITIES_

#include "../utils.h"

typedef struct
{
	usize id;
	i64   x, y;
} City;

typedef struct
{
	usize  size;									// number of cities.
	City  *data;									// actual cities.
} Cities;

Cities generate_cities_rand(usize argc, char **argv, i64 min, i64 max);
Cities generate_cities_args(usize argc, char **argv, i64 min, i64 max);
Cities generate_cities_std(usize argc, char **argv, i64 min, i64 max);

void destroy_cities(Cities cities);

#endif

#ifndef INCLUDED_DISPLAY_
#define INCLUDED_DISPLAY_

#include "../main.h"
#include "../cities/cities.h"

void display_config(Config const config); // displays the config file.

void display(Cities cities, size_t temp, size_t M, size_t m);

#endif

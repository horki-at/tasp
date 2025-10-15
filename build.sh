#!/bin/bash

# TODO: do PCH
gcc -std=c23 -Wall -Werror -pedantic *.c cities/*.c display/*.c solver/*.c

.SUFFIXES:
.RECIPEPREFIX = |

VERBOSE ?= false
QUIET   := $(if $(filter true,$(VERBOSE)),,@)

CC      := ccache gcc
CFLAGS  := -std=c23 -Wall -Werror -pedantic -O2
LDFLAGS := 

C_PROG_SOURCES        := main.c
C_SOURCES             := $(filter-out $(C_PROG_SOURCES),$(wildcard */*.c *.c))
C_INT_HEADERS         := $(wildcard */*.ih *.ih)
C_PROGS               := $(patsubst %.c,%,$(C_PROG_SOURCES))
C_OBJECT_FILES        := $(patsubst %.c,%.o,$(C_SOURCES))
C_PRECOMPILED_HEADERS := $(C_INT_HEADERS:%=%.gch)

# default target are all sources with main
all: $(C_PROGS)

# link the main program
$(C_PROGS): $(C_OBJECT_FILES) | $(C_PRECOMPILED_HEADERS)
|@echo "[ LINK $^ => $@ ]"
|$(QUIET) $(CC) $(CFLAGS) -o $@ $(C_PROG_SOURCES) $(C_OBJECT_FILES) $(LDFLAGS)

%.o: %.c | $(C_PRECOMPILED_HEADERS)
|@echo "[ COMPILE $^ => $@ ]"
|$(QUIET) $(CC) $(CFLAGS) -c -o $@ $^

%.ih.gch: %.ih
|@echo "[ PRECOMPILE $^ => $@ ]"
|$(QUIET) $(CC) $(CFLAGS) -x c-header -o $@ $^

clean:
|@echo "[ CLEAN ]"
|$(QUIET) rm -f $(C_PROGS) $(C_OBJECT_FILES) $(C_PRECOMPILED_HEADERS)

debug: CFLAGS += -g -DDEBUG
debug: $(C_PROGS)

release: CFLAGS += -O3 -DNDEBUG
release: $(C_PROGS)

.PHONY: all clean debug release

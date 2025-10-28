.SUFFIXES:
.RECIPEPREFIX = |

VERBOSE ?= false
QUIET   := $(if $(filter true,$(VERBOSE)),,@)

CC      := ccache gcc
CFLAGS  := -std=c23 -Wall -Werror -pedantic
LDFLAGS := -lm

TARGET := tasp

C_SOURCES             := $(wildcard tsp/*/*.c tsp/*.c)
C_HEADERS             := $(wildcard tsp/*/*.h tsp/*.h)
C_INT_HEADERS         := $(wildcard tsp/*/*.ih tsp/*.ih)
C_OBJECTS             := $(patsubst %.c,%.o,$(C_SOURCES))
C_PRECOMPILED_HEADERS := $(C_INT_HEADERS:%=%.gch)

# default target are all sources with main
all: clean $(TARGET)

# compile and link the target program
$(TARGET): $(C_OBJECTS) | $(C_PRECOMPILED_HEADERS)
|@echo "[ LINK $< => $@ ]"
|$(QUIET) $(CC) $(CFLAGS) -o $@ $(C_OBJECTS) $(LDFLAGS)

%.o: %.c $(C_HEADERS) | $(C_PRECOMPILED_HEADERS)
|@echo "[ COMPILE $^ => $@ ]"
|$(QUIET) $(CC) $(CFLAGS) -o $@ -c $<

%.ih.gch: %.ih
|@echo "[ PRECOMPILE $^ => $@ ]"
|$(QUIET) $(CC) $(CFLAGS) -x c-header -o $@ $<

clean:
|@echo "[ CLEAN ]"
|$(QUIET) rm -f $(C_OBJECTS) $(TARGET) $(C_PRECOMPILED_HEADERS)

debug: CFLAGS += -g -DDEBUG
debug: clean $(TARGET)

release: CFLAGS += -O3 -DNDEBUG
release: clean $(TARGET)

.PHONY: all clean debug release

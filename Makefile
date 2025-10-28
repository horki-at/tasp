.SUFFIXES:
.RECIPEPREFIX = |

ifeq ($(shell test -w /usr/local/bin && echo yes),yes)
	PREFIX ?= /usr/local
else
	PREFIX ?= $(HOME)/.local
endif

BINDIR     := $(PREFIX)/bin
SCRDIR     := $(PREFIX)/share/tasp/
DEF_SCRDIR := src/gnuplot

VERBOSE ?= false
QUIET   := $(if $(filter true,$(VERBOSE)),,@)

CC      := ccache gcc
CFLAGS  := -std=c23 -Wall -Werror -pedantic -DSCRDIR=\"$(DEF_SCRDIR)\"
LDFLAGS := -lm

TARGET := tasp

C_SOURCES             := $(wildcard src/*/*.c src/*.c)
C_HEADERS             := $(wildcard src/*/*.h src/*.h)
C_INT_HEADERS         := $(wildcard src/*/*.ih src/*.ih)
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

install: CFLAGS := $(filter-out -DSCRDIR=%,$(CFLAGS))
install: CFLAGS += -DSCRDIR=\"$(SCRDIR)\"   # override $(DEF_SCRDIR)
install: release
|@echo "[ INSTALLING... ]" 
|$(QUIET) install -d $(BINDIR)
|$(QUIET) install -m 755 $(TARGET) $(BINDIR)/$(TARGET)
|$(QUIET) mkdir -p $(SCRDIR)
|$(QUIET) cp -r src/gnuplot/* $(SCRDIR)
|@echo "[ FINISHED ]"
|@printf "Installed %s in %s. Make sure it is in PATH.\n" $(TARGET) $(BINDIR)

uninstall:
|@echo "[ UNINSTALLING... ]"
|$(QUIET) rm -f $(BINDIR)/$(TARGET)
|$(QUIET) rm -rf $(SCRDIR)
|@echo "[ FINISHED ]"

.PHONY: all clean debug release install uninstall

# build options
PREFIX ?= /usr/local
warn_flags = -pedantic -Wall
opt_flags = -O0
dbg_flags = -g
# -------------

srcdir ?= .
ccsrc = $(wildcard $(srcdir)/gmath/*.cc)
obj = $(ccsrc:.cc=.o) $(csrc:.c=.o)
dep = $(obj:.o=.d)
name = gmath

CFLAGS = $(warn_flags) $(opt_flags) $(dbg_flags)
CXXFLAGS = $(warn_flags) $(opt_flags) $(dbg_flags)
LDFLAGS = $(libgl)

sys = $(shell uname -s | sed 's/MINGW.*/MINGW/')
ifeq ($(sys), Darwin)
	alib = lib$(name).a

	libgl = -framework OpenGL -lGLEW
else ifeq ($(sys), MINGW)
	alib = $(name).lib

	libgl = -lopengl32 -lglew32
else
	alib = lib$(name).a

	libgl = -lGL -lGLU -lGLEW
endif

.PHONY: all
all: $(alib)

$(alib): $(obj)
	$(AR) rcs $@ $(obj)

-include $(dep)

%.d: %.c
	@$(CPP) $(CFLAGS) $< -MM -MT $(@:.d=.o) >$@

%.d: %.cc
	@$(CPP) $(CXXFLAGS) $< -MM -MT $(@:.d=.o) >$@

.PHONY: clean
clean:
	rm -f $(obj) $(alib)

.PHONY: cleandep
cleandep:
	rm -f $(dep)

#
# Makefile: Builds the SuperTTD project. Use with GNU Make.
#
# (c) 2019 thatlittlegit. This code is licensed under the *Unlicense*. See
# https://unlicense.org.
#
# Windows users: Run in (Git) Bash. If it doesn't work, make a bug report.
WARNINGS=-Wall

CC=$(CXX)
LD=g++

CXXFLAGS=$(WARNINGS) -c
LDLIBS=-lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp

RM=rm
CLANGFORMAT=clang-format

TARGETS= \
	src/spriteman.o \
	src/superttd.o \
	src/tileman.o \

all: superttd
superttd: src/superttd
	mv $^ $@
src/superttd: $(TARGETS)

src/spriteman.o: src/spriteman.cpp src/spriteman.hpp
src/superttd.o: src/superttd.cpp src/superttd.hpp src/tileman.hpp src/spriteman.hpp
src/tileman.o: src/tileman.cpp src/tileman.hpp

clean:
	$(RM) -f $(wildcard src/*.o) $(wildcard superttd) $(wildcard src/superttd)

format: $(wildcard src/*.cpp) $(wildcard src/*.hpp)
	$(CLANGFORMAT) -style=WebKit -i $^

.PHONY: clean format

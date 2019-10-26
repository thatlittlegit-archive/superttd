#
# Makefile: Makefile for GNU Make.
#
# Windows users: Run in (Git) Bash. If it doesn't work, make a bug report.
WARNINGS=-Wall

CXX=g++
LD=g++

CXXFLAGS=$(WARNINGS) -c -Iinclude
LDFLAGS=-lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp

RM=rm

all: superttd
superttd: $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))
	$(LD) $(LDFLAGS) -o $@ $^


clean:
	$(RM) -f $(wildcard src/*.o) $(wildcard superttd) $(wildcard src/superttd)

%.formatted: %.cpp
	clang-format $^ >/tmp/superttd
	mv /tmp/superttd $^

format: $(patsubst %.cpp,%.formatted,$(wildcard src/*.cpp))

.PHONY: clean format %.formatted

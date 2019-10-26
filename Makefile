#
# Makefile: Makefile for GNU Make.
#
# Windows users: Run in (Git) Bash. If it doesn't work, make a bug report.
WARNINGS=-Wall

CC=$(CXX)
LD=g++

CXXFLAGS=$(WARNINGS) -c -Iinclude
LDLIBS=-lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp

RM=rm

TARGETS= \
	src/spriteman.o \
	src/superttd.o \
	src/tileman.o \

all: superttd
superttd: src/superttd
	mv $^ $@
src/superttd: $(TARGETS)

src/spriteman.o: src/spriteman.cpp include/spriteman.hpp
src/superttd.o: src/superttd.cpp include/superttd.hpp include/tileman.hpp include/spriteman.hpp
src/tileman.o: src/tileman.cpp include/tileman.hpp include/spriteman.hpp

clean:
	$(RM) -f $(wildcard src/*.o) $(wildcard superttd) $(wildcard src/superttd)

format: $(wildcard src/*.cpp) $(wildcard include/*.hpp)
	clang-format -i $^

.PHONY: clean format

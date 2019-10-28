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

CXXFLAGS=$(WARNINGS) -c -std=c++17
LDLIBS=-lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp -lstdc++fs

RM=rm
CLANGFORMAT=clang-format

TARGETS= \
	src/sprite.o \
	src/superttd.o \
	src/tileman.o \
	src/namespaced_id.o \

all: superttd
superttd: src/superttd
	mv $^ $@
src/superttd: $(TARGETS)

src/sprite.o: src/sprite.cpp src/sprite.hpp src/namespaced_id.hpp
src/superttd.o: src/superttd.cpp src/superttd.hpp src/tileman.hpp src/sprite.hpp
src/tileman.o: src/tileman.cpp src/tileman.hpp src/namespaced_id.hpp
src/namespaced_id.o: src/namespaced_id.cpp src/namespaced_id.hpp

clean:
	$(RM) -f $(wildcard src/*.o) $(wildcard superttd) $(wildcard src/superttd)

format: $(wildcard src/*.cpp) $(wildcard src/*.hpp)
	$(CLANGFORMAT) -style=WebKit -i $^

.PHONY: clean format

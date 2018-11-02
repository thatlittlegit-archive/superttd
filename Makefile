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

all:
	[ -f '.depsok' ] || make testdeps
	make superttd

superttd: $(patsubst %.cpp,%.o,$(wildcard src/*.cpp))
	$(LD) $(LDFLAGS) -o $@ $^

testdeps:
	-rm testdeps.* a.out .depsok 2>/dev/null
	echo '#include <SFML/Graphics.hpp>\n#include <yaml-cpp/yaml.h>\nint main() {}' > testdeps.cpp
	$(CXX) testdeps.cpp 2>testdeps.err
	-rm testdeps.* a.out 2>/dev/null
	echo 'ok' > .depsok

clean:
	-rm src/*.o testdeps.* a.out superttd

%.formatted: %.cpp
	clang-format $^ >/tmp/superttd
	mv /tmp/superttd $^

format: $(patsubst %.cpp,%.formatted,$(wildcard src/*.cpp))

.PHONY: testdeps clean format %.formatted

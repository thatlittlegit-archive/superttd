#
# Makefile: Makefile for GNU Make.
#
# Windows users: Run in (Git) Bash. If it doesn't work, make a bug report.

CXX=g++
CC=gcc
LD=g++

WARNINGS=-Wall
CXX_FLAGS=$(WARNINGS) -c -Iinclude
LD_FLAGS=-o superttd -lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp

RM=rm
ECHONOE=echo
ECHO=$(ECHONOE) -e
TOUCH=touch
MD5=md5sum
DIFF=diff
CLANGFORMAT=clang-format

superttd:
	@ls .depsok >/dev/null 2>/dev/null || make -s testdeps
	@ls .ifnewer >/dev/null 2>/dev/null || make -s ifnewer
	@make -s build
	@$(ECHO) "\t --- FINISHED"

testdeps:
	@$(ECHO) '\t --- testdeps'
	@for file in $$(ls testdeps.* a.out .depsok 2>/dev/null); do $(ECHO) '\t RM '$$file && rm $$file; done
	@$(ECHONOE) '#include <SFML/Graphics.hpp>\n#include <yaml-cpp/yaml.h>\nint main() {}' > testdeps.cpp && $(ECHO) '\t CXX testdeps.cpp' && $(CXX) testdeps.cpp 2>testdeps.err

	@ls testdeps.err >/dev/null 2>/dev/null && if [ ! -s testdeps.err ]; then exit 0; else $(ECHO) '\t --- ERROR: Missing dependency!' ; cat testdeps.err ; $(ECHO) '\t --- exiting!' ; exit 1; fi
	@for file in $$(ls testdeps.* a.out 2>/dev/null); do $(ECHO) '\t RM '$$file && rm $$file; done
	@$(ECHO) 'ok' > .depsok
	@$(ECHO) '\t # .depsok created'

ifnewer:
	@$(ECHO) '\t --- ifnewer'
	@$(ECHO) '\t CC src/ifnewer.c'
	@$(CC) $(WARNINGS) src/ifnewer.c -o .ifnewer
	@$(ECHO) '\t # .ifnewer compiled'

clean:
	@-$(ECHO) "\t --- clean" && $(ECHO) "\t RM "$$(ls *.o 2>/dev/null);$(RM) *.o 2>/dev/null

build:
	@$(ECHO) "\t --- build"
	@-$(ECHO) "\t MD5SUM *.o";$(MD5) *.o >.buildtmp 2>/dev/null
	@for file in $$(ls src/*.cpp);do ./.ifnewer $$file $$(echo $$file | awk -F/ '{print $$2".o"}' | awk -F. '{print $$1"."$$3}') 2>/dev/null || ($(ECHO) "\t CXX "$$file && $(CXX) $(CXX_FLAGS) $$file) || exit 1;done
	@$(ECHO) "\t TOUCH *.o"
	@$(TOUCH) *.o
	@$(MD5) *.o | $(DIFF) .buildtmp - >/dev/null || $(ECHO) "\t LD "$$(ls *.o);$(LD) $$(ls *.o) $(LD_FLAGS);$(ECHO) "\t RM .buildtmp";rm .buildtmp

format:
	@$(ECHO) "\t --- format"
	@for file in $$(ls src/*.c src/*.cpp); do echo "CLANGFORMAT $$file" && $(CLANGFORMAT) $$file >/tmp/superttd; mv /tmp/superttd $$file; done

.PHONY: superttd

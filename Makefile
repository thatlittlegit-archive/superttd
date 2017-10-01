#
# Makefile: Makefile for GNU Make.
#
# Windows users: Run in (Git) Bash. If it doesn't work, make a bug report.

CXX=g++
LD=g++

CXX_FLAGS=-c -Wall -Iinclude
LD_FLAGS=-o superttd -lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp

RM=rm
ECHO=echo -e

superttd:
	@ls .depsok >/dev/null 2>/dev/null || make -s testdeps
	@make -s clean build
	@$(ECHO) "\t --- FINISHED"

testdeps:
	@$(ECHO) '\t --- testdeps'
	@for file in $$(ls testdeps.* a.out .depsok 2>/dev/null); do $(ECHO) '\t RM '$$file && rm $$file; done
	@$(ECHO) '#include <SFML/Graphics.hpp>\n#include <yaml-cpp/yaml.h>\nint main() {}' > testdeps.cpp && $(ECHO) '\t CXX testdeps.cpp' && $(CXX) testdeps.cpp 2>testdeps.err

	@ls testdeps.err >/dev/null 2>/dev/null && if [ ! -s testdeps.err ]; then exit 0; else $(ECHO) '\t --- ERROR: Missing dependency!' ; cat testdeps.err ; $(ECHO) '\t --- exiting!' ; exit 1; fi
	@for file in $$(ls testdeps.* a.out 2>/dev/null); do $(ECHO) '\t RM '$$file && rm $$file; done
	@$(ECHO) 'ok' > .depsok
	@$(ECHO) '\t # .depsok created'

clean:
	@-ls *.o >/dev/null 2>/dev/null && $(ECHO) "\t --- clean" && $(ECHO) "\t RM "$$(ls *.o 2>/dev/null);$(RM) *.o 2>/dev/null

build:
	@$(ECHO) "\t --- build"
	@for file in $$(ls src/*.cpp);do $(ECHO) "\t CXX "$$file;$(CXX) $(CXX_FLAGS) $$file;done
	@$(ECHO) "\t LD "$$(ls *.o);$(LD) $$(ls *.o) $(LD_FLAGS)

.PHONY: superttd

#
# Makefile: Makefile for GNU Make.
#

# WINDOWS USERS: Run in GitBash. Report all errors.

CXX=g++
LD=g++ # TODO: Make compatable with pure ld

CXX_FLAGS=-c -Wall -Iinclude
LD_FLAGS=-o superttd -lsfml-system -lsfml-window -lsfml-graphics -lyaml-cpp

RM=rm
ECHO=echo -e

superttd:
	@make -s clean build
	@$(ECHO) "\t --- FINISHED"

clean:
	@-ls *.o >/dev/null 2>/dev/null && $(ECHO) "\t --- clean" && $(ECHO) "\t RM "$$(ls *.o 2>/dev/null);$(RM) *.o 2>/dev/null

build:
	@$(ECHO) "\t --- build"
	@for file in $$(ls src/*.cpp);do $(ECHO) "\t CXX "$$file;$(CXX) $(CXX_FLAGS) $$file;done
	@$(ECHO) "\t LD "$$(ls *.o);$(LD) $$(ls *.o) $(LD_FLAGS)

.PHONY: superttd

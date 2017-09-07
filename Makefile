#
# Makefile: Makefile for GNU Make.
#

# WINDOWS USERS: Run in GitBash. Report all errors.

CXX=g++
LD=g++ # TODO: Make compatable with pure ld

CXX_FLAGS=-c -Wall
LD_FLAGS=-o superttd

RM=rm

superttd:
	@make -s clean build
	@echo "\t--- FINISHED"

clean:
	@echo "\t--- clean"
	@-echo "\tRM "$$(ls *.o 2>/dev/null);$(RM) *.o 2>/dev/null

build:
	@echo "\t--- build"
	@for file in $$(ls src/*.cpp);do echo "\tCXX "$$file;$(CXX) $(CXX_FLAGS) $$file;done
	@echo "\tLD "$$(ls *.o);$(LD) $(LD_FLAGS) $$(ls *.o)

.PHONY: superttd

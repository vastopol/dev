# Variables
COMP = g++
FLAGS = -Wall -Werror -ansi -pedantic
DEBUG = -g
FILES = functs/functs_com.cpp functs/functs_parse.cpp

# Targets
front: 
	$(COMP) $(FLAGS) $(FILES) front.cpp

debug:
	$(COMP) $(FLAGS) $(DEBUG) $(FILES) front.cpp
	
clean:
	rm a.out
	
# terrible lazy makefile... for now
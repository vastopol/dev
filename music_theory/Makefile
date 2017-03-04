# Variables
COMP = g++ -std=c++11
FILES = mus_f.cpp
FLAGS = -Wall -Werror -pedantic
DEBUG = -g

all: mst_default.cpp
	$(COMP) $(FLAGS) mst_default.cpp $(FILES)
debug: mst_default.cpp
	$(COMP) $(FLAGS) $(DEBUG) mst_default.cpp $(FILES)
clean: 
	rm a.out

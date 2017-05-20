#include <stdlib.h>
#include <string.h>
#include <stdio.h>

int grep(char* regexp, FILE* f, char* name);

int match(char* regexp, char* text);

int matchhere(char* regexp, char* text);

int matchstar(int c, char* regexp, char* text);

int matchstar2(int c, char* regexp, char* text);
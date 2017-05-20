#include <stdlib.h>
#include <string.h>
#include <stdio.h>

#include "grep.h"

// main: search for regexp in files
int main(int argc, char** argv)
{
	int i, nmatch;
	FILE* f;

	if(argc < 2)
	{
		printf("usage: grep regexp [file ...]\n");
		exit(2);
	}

	nmatch = 0;

	if(argc == 2)
	{
		if(grep(argv[1], stdin, NULL))
		{
			nmatch++;
		}
	}
	else
	{
		for(i = 2; i < argc; i++)
		{
			f = fopen(argv[i], "r");

			if(f == NULL)
			{
				printf("can't open %s:", argv[i]);
				continue;
			}

			if( grep(argv[1], f, argc ? argv[i] : NULL) > 0 )
			{
				nmatch++;
			}
			fclose(f);
		}
	}

	return nmatch == 0;
}
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

// print all lines of char >= 6
#define MINLEN 6

void strings(char* name, FILE* fin);

int main(int argc, char** argv)
{
	int i;
	FILE* fin;

	if(argc == 1)
	{
		printf("usage: stringz filenames\n");
	}
	else
	{
		for(i = 1; i < argc; i++)
		{
			if( (fin = fopen(argv[i], "rb")) == NULL ) // open file in binary mode
			{
				printf("can't open %s:", argv[i]);
			}
			else
			{
				strings(argv[i], fin);
				fclose(fin);
			}
		}
	}

	return 0;
}
//----------------------------------------------------

// strings: extract printable strings from stream
void strings(char* name, FILE* fin)
{
	int c, i;
	char buf[BUFSIZ];

	do {  // once for each string
		
		for(i = 0; (c = getc(fin)) != EOF; )
		{
			if(!isprint(c))
			{
				break;
			}

			buf[i++] = c;

			if(i >= BUFSIZ)
			{
				break;
			}
		}

		if(i >= MINLEN) // print if long enough
		{
			printf("%s: %.*s\n", name, i, buf);
		}

	} while(c != EOF);
}
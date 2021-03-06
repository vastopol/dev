#include "grep.h"


// search for regexp in file
int grep(char* regexp, FILE* f, char* name)
{
	int n, nmatch;
	char buf[BUFSIZ];

	nmatch = 0;
	while(fgets(buf, sizeof buf, f) != NULL)
	{
		n = strlen(buf);
		if(n > 0 && buf[n-1] == '\n')
		{
			buf[n-1] = '\0';
		}

		if(match(regexp, buf))
		{
			nmatch++;
			if(name != NULL)
			{
				printf("%s:", name);
			}
			printf("%s\n", buf);
		}
	}

	return nmatch;
}
//------------------------------------------------------------------

// search for regexp anywhere in text, returns as soon as it finds a match.
int match(char* regexp, char* text)
{
	if(regexp[0] == '^')
	{
		return matchhere(regexp+1, text);
	}

	do { // must look even if empty str

		if(matchhere(regexp, text))
		{
			return 1;
		}

	} while(*text++ != '\0');

	return 0;
}
//------------------------------------------------------------------

// search for regexp at beginning of text
int matchhere(char* regexp, char* text)
{
	if(regexp[0] == '\0')
	{
		return 1;
	}
	if(regexp[1] == '*')
	{
		return matchstar(regexp[0], regexp+2, text);
	}
	if(regexp[0] == '$' && regexp[1] == '\0')
	{
		return *text == '\0';
	}
	if(*text != '\0' && (regexp[0] == '.' || regexp[0] == *text))
	{
		return matchhere(regexp+1, text+1);
	}
	
	return 0;
}
//------------------------------------------------------------------

// search for c*regexp at beginning of text
int matchstar(int c, char* regexp, char* text)
{
	do {

		if(matchhere(regexp, text))
		{
			return 1;
		}

	} while(*text != '\0' && (*text++ == c || c == '.'));
	
	return 0;
}
//------------------------------------------------------------------

// leftmost longest search for c*regexp (greedy algorithm)
int matchstar2(int c, char* regexp, char* text)
{
	char* t;

	for(t = text; *t != '\0' && (*t == c || c == '.'); t++)
	{;}

	do {

		if(matchhere(regexp, text))
		{
			return 1;
		}

	} while(*text != '\0' && (*text++ == c || c == '.'));
	
	return 0;
}
//------------------------------------------------------------------
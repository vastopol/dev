#include "csv.h"

/* Internal Functions */

/* set variables back to starting values */
static void reset(void) 					
{
	free(line); /* free(NULL) peritted in ANSI C */
	free(sline);
	free(field);
	line = NULL;
	sline = NULL;
	field = NULL;
	maxline = maxfield = nfield = 0;
}
//--------------------------------

/* check for and consume \r, \n, \r\n, or EOF */
static int endofline(FILE* f, int c)	 	
{
	int eol;
	eol = ( c == '\r' || c == '\n');
	if(c == '\r')
	{
		c = getc(f);
		if(c != '\n' && c != EOF)
		{
			ungetc(c, f); /* read too far, put c back */
		}
	}
	return eol;
}
//--------------------------------

/* split line into fields */
static int split(void)						
{
	char *p, **newf;
	char *sepp; /* pointer to temporary separator character */
	int sepc;   /*  temporary separator character */

	nfield = 0;
	if(line[0] == '\0')
	{
		return 0;
	}

	strcpy(sline, line);
	p = sline; 

	do {

		if(nfield >= maxfield)
		{
			maxfield *= 2;
			newf = (char**) realloc(field, maxfield * sizeof(field[0]));
			if(newf == NULL)
			{
				return NOMEM;
			}
			field = newf;
		}

		if(*p == '"')
		{
			sepp = advquote(++p); /* skip internal quote */
		}
		else
		{
			sepp = p + strcspn(p, fieldsep);
		}
		sepc = sepp[0];
		sepp[0] = '\0';
		field[nfield++] = p;
		p = sepp + 1;

	} while(sepc == ',');

	return nfield;
}
//--------------------------------

/* quoted field, return pointer to next separator */
static char* advquote(char* p)				
{
	int i, j;
	for(i = j = 0; p[j] != '\0'; i++, j++)
	{
		if(p[j] == '"' && p[++j] != '"')
		{
			/* copy upto next separator or \0 */
			int k = strcspn(p+j, fieldsep);
			memmove(p+i, p+j, k);
			i += k;
			j += k;
			break;
		}
		p[i] = p[j];
	}
	p[i] = '\0';
	return p + j;
}
//--------------------------------

/* External Functions */

/* read next input of line */
extern char* csvgetline(FILE* f)			
{
	int i, c;
	char *newl, *news;

	if (line == NULL) /* allocate on first call */
	{
		maxline = maxfield = 1;
		line = (char*) malloc(maxline);
		sline = (char*) malloc(maxline);
		field = (char**) malloc(maxline * sizeof(field[0]));

		if(line == NULL || sline == NULL || field == NULL)
		{
			reset();
			return NULL; /* out of memory */
		}
	}

	for(i = 0; (c=getc(f)) != EOF && !endofline(f,c); i++)
	{
		if(i >= maxline-1) /* grow line */
		{
			maxline *= 2; /* double current size */
			newl = (char*) realloc(line, maxline);
			news = (char*) realloc(sline, maxline);

			if(newl == NULL || news == NULL)
			{
				reset();
				return NULL; /* out of memory */
			}

			line = newl;
			sline = news;
		}

		line[i] = c;
	}

	line[i] = '\0';

	if(split() == NOMEM)
	{
		reset();
		return NULL; /* out of memory */
	}

	return (c == EOF && i == 0) ? NULL : line;
}
//--------------------------------

/* return field n */
extern char* csvfield(int n)				
{
	if(n < 0 || n >= nfield)
	{
		return NULL;
	}
	return field[n];
}
//--------------------------------

/* return number of fields */
extern int csvnfield(void)					
{
	return nfield;
}
//--------------------------------
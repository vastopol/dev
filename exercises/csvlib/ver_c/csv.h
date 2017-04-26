/* interface for csv lib*/

/* External Functions */
extern char* csvgetline(FILE* f);	/* read next input of line */

extern char* csvfield(int n);		/* return field n */

extern int csvnfield(void);			/* return number of fields */

/* Internal Variables */
enum { NOMEM = -2 };				/* out of memory signal */

static char* line = NULL;			/* input chars */

static char* sline = NULL			/* line copy used by split */

static int maxline = 0;				/* size of line[] && sline[] */

static char** field = NULL;			/* field of pointers */

static int maxfield = 0;			/* size of field[] */

static int nfield = 0;				/* number of fields in field[] */

static char fieldsep = ",";			/* field separator chars */

/* Internal Functions */ 
static void reset(void); 			/* set variables back to starting values */

static int endofline(FILE* fin);	/* check for and consume \r, \n, \r\n, or EOF */

static int split(void);				/* split line into fields */

static char* advquote(char* p);		/* quoted field, return pointer to next separator */


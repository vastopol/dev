/* error wrapping functions */ 

#include <stdlib.h>
#include <stdio.h>

#include <stdarg.h>
#include <string.h>
#include <errno.h>


static char* name = NULL; // program name for messages

extern void eprintf(char* fmt, ...);

extern void weprintf(char* fmt, ...); // not done ***

extern char* estrdup(char* s);

extern void* emalloc(size_t n);

extern void* erealloc(void* v, size_t n); // not done ***

extern char* progname(void);

extern void setprogname(char* s);

extern void usage(void);
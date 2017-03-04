/*  singly linked list */

#include "stdio.h"
#include "stdlib.h"
#include "string.h"

typedef struct Nameval Nameval;

struct Nameval
{
    char    *name;
    int      val;
    Nameval *next; /* Next item in list */
};
/*-----------------------------------------*/


/* newitem: create new item from name and value */
Nameval* newitem(char *name, int value)
{
    Nameval* newp;
    
    newp = (Nameval*) malloc(sizeof(Nameval)); /* book uses emalloc */
    newp->name = name;
    newp->val = value;
    newp->next = NULL;
    
    return newp;
}
/*-----------------------------------------*/


/* addfront: add newp to the front of listp */
Nameval* addfront(Nameval *listp, Nameval *newp)
{
    newp->next = listp;
    return newp;
}
/*-----------------------------------------*/


/* addend: add newp to the end of listp 
    runs in O(n) time, must walk list to end */
Nameval* addend(Nameval *listp, Nameval *newp)
{
    Nameval *p;
    
    if(listp == NULL)
    {
        return newp;
    }
    
    for(p = listp; p->next != NULL; p = p->next)
    {}
    
    p->next = newp;
    return newp;
}
/*-----------------------------------------*/


/* lookup: sequential search for name in listp
    runs in O(n) time, must walk list to end */
Nameval* lookup(Nameval *listp, char *name)
{
    for( ; listp != NULL; listp = listp->next)
    {
        if(strcmp(name, listp->name) == 0)
        {
            return listp;
        }
    }
}
/*-----------------------------------------*/


/* apply: walk list and call another function on each element */
void apply(Nameval *listp, void(*fn)(Nameval*, void*), void *arg)
{
    for( ; listp != NULL; listp = listp->next)
    {
        (*fn)(listp, arg);  /* calls function */
    }
}
/*-----------------------------------------*/


/* printnv: print name and value using format in arg */
void printnv(Nameval *p, void *arg)
{
    char *fmt;
    fmt = (char*) arg;
    printf(fmt, p->name, p->val);
}
/*-----------------------------------------*/


/* inccounter: increment counter arg */
void inccounter(Nameval *p, void *arg)
{
    /* p is not used */
    int *ip;
    ip = (int*) arg;
    (*ip)++;
}
/*-----------------------------------------*/


/* freeall: free all elements of listp */
void freeall(Nameval *listp)
{
    Nameval *next;
    
    for( ; listp != NULL; listp = next)
    {
        next = listp->next;
        /* doesn't free listp->name, assumes freed somewhere else... */
        free(listp);
    }
}
/*-----------------------------------------*/


/* delitem: delete first found "name" in listp */
Nameval* delitem(Nameval *listp, char *name)
{
    Nameval *p, *prev;
    
    prev = NULL;
    for(p = listp; p != NULL; p = p->next)
    {
        if(strcmp(name, p->name) == 0)
        {
            if(prev == NULL){
                listp = p->next;
            }
            else{
                prev->next = p->next;
            }
            free(p);
            /* doesn't free p->name, assumes freed somewhere else... */
            return listp;
        }
        prev = p;
    }
    
    printf("delitem: %s not in list", name); /* book uses eprintf */
    return NULL;
}
/*-----------------------------------------*/

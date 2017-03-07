/* Test harness for clist.h */

/* C Libraries */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* Data structure file */
#include "c_list.h"

int main()
{
    /* test constructor function */
    char* cstr1 = "test_node_1";
    int ival1 = 1;
    Nameval* item1 = newitem(cstr1, ival1); 
    
    char* cstr2 = "test_node_2";
    int ival2 = 2;
    Nameval* item2 = newitem(cstr2, ival2); 
    
    char* cstr3 = "test_node_3";
    int ival3 = 3;
    Nameval* item3 = newitem(cstr3, ival3); 
    
    /* test addfront && addend */
    Nameval* newl = addfront(item2, item1);
    newl = addend(newl, item3);
    
    /* test apply print && counter */
    apply(newl, printnv, "%s: %x\n");
    
    int n;    
    apply(newl, inccounter, &n);
    printf("Size of list: %d\n", n);
    
    /* test delete && freeall  */
    printf("delete item3\n");
    delitem(newl, cstr3);
    apply(newl, printnv, "%s: %x\n");
    
    freeall(newl);
    
    return 0;
}

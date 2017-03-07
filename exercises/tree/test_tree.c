/* Test harness for clist.h */

/* C Libraries */
#include "stdio.h"
#include "stdlib.h"
#include "string.h"

/* Data structure file */
#include "c_tree.h"

int main()
{
    int  intM = 1;
    char* charM = "M";
    Nameval* M = newitem(charM, intM);
    
    int  intZ = 2;
    char* charZ = "Z";
    Nameval* Z = newitem(charZ, intZ);
    
    
    int  intA = 3;
    char* charA = "A";
    Nameval* A = newitem(charA, intA);
    
    Nameval* tree = M;
    tree = insert(tree, Z);
    tree = insert(tree, A);
    
    applyinorder(tree, printnv, "%s: %x\n");
    printf("\n");
    applypostorder(tree, printnv, "%s: %x\n");
    printf("\n");
    
    int n = 0;
    applyinorder(tree, inccounter, &n);
    printf("count inorder: %d \n", n);
    n = 0;
    applypostorder(tree, inccounter, &n);
    printf("count postorder: %d \n", n);
    
    return 0;
}

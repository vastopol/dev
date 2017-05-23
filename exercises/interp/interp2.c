/* 
interpretation && compilation for a virtual machine
part 2: operator table
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Symbol Symbol;
typedef struct Tree Tree;

struct Symbol
{
	int value;
	char* name;
};

struct Tree
{
	int     op; 	// operation code
	int     value; 	// value if number
	Symbol* symbol; // symbol entry if variable
	Tree*   left;
	Tree*   right;
};


enum // operation codes, Tree.op
{
	NUMBER, VARIABLE, ADD, DIVIDE, MAX, ASSIGN, /* etc... */
};

//-----------------------------------------------------------

// FORWARD DECLARE Table && OPS BEFORE HAND
int (*optab[])(Tree*);
int pushop(Tree* t);
int pushsymop(Tree* t);
int addop(Tree* t);
int divop(Tree* t);
int maxop(Tree* t);
int assignop(Tree* t);
/* ... */

// eval version based on operator table
int eval(Tree* t)
{
	return (*optab[t->op])(t);
}

// optab: operator function table
int (*optab[])(Tree*) = {
	pushop,
	pushsymop,
	addop,
	divop,
	maxop,
	assignop
	/* ... */
};

int pushop(Tree* t)
{
	return t->value;
}

int pushsymop(Tree* t)
{
	return t->symbol->value;
}

int addop(Tree* t)
{
	return eval(t->left) + eval(t->right);
}

int divop(Tree* t)
{
	int left = eval(t->left);
	int right = eval(t->right);
	if(right == 0)
	{
		printf("divide %d by zero", left);
		exit(2);
	}
	return left / right;
}

int maxop(Tree* t)
{
	int left = eval(t->left);
	int right = eval(t->right);
	return left>right ? left : right;	
}

int assignop(Tree* t)
{
	t->left->symbol->value = eval(t->right);
	return t->left->symbol->value;
}
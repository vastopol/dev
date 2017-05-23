/* 
interpretation && compilation for a virtual machine
part 1: switch statement 
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

// eval version based on switch statement
int eval(Tree* t)
{
	int left, right;

	switch(t->op)
	{
		case NUMBER:
			return t->value;
		case VARIABLE:
			return t->symbol->value;
		case ADD:
			return eval(t->left) + eval(t->right);
		case DIVIDE:
			left = eval(t->left);
			right = eval(t->right);
			if(right == 0)
			{
				printf("divide %d by zero", left);
				exit(2);
			}
			return left / right;
		case MAX:
			left = eval(t->left);
			right = eval(t->right);
			return left>right ? left : right;			
		case ASSIGN:
			t->left->symbol->value = eval(t->right);
			return t->left->symbol->value;
		/* etc... */		
		default:
			printf("ERROR");
			return 0;
	}
}

//----------------------------------------------------------

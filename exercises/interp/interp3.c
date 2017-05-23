/* 
interpretation && compilation for a virtual machine
part 3: stack machine
*/

#include <stdio.h>
#include <stdlib.h>

typedef struct Symbol Symbol;
typedef struct Tree Tree;
typedef union Code Code;

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

union Code
{
	void (*op)(void);
	int value;
	Symbol* symbol;
};

enum // operation codes, Tree.op
{
	NUMBER, VARIABLE, ADD, DIVIDE, MAX, ASSIGN, /* etc... */
};

//-----------------------------------------------------------

#define NCODE 6
#define NSTACK 10

// FORWARD DECLARE OPS for code
void pushop(void);
void pushsymop(void);
void addop(void);
void divop(void);
void maxop(void);
void assignop(void);
/* ... */

int generate(int codep, Tree* t);

Code code[NCODE];
int stack[NSTACK];
int stackp; // stack pointer
int pc; // program counter

// eval stack machine
int eval(Tree* t)
{
	pc = generate(0, t);
	code[pc].op = NULL;

	stackp = 0;
	pc = 0;

	while(code[pc].op != NULL)
	{
		(*code[pc++].op)();
	}

	return stack[0];
}

int generate(int codep, Tree* t)
{
	switch(t->op)
	{
		case NUMBER:
			code[codep++].op = pushop;
			code[codep++].value = t->value;
			return codep;
		case VARIABLE:
			code[codep++].op = pushsymop;
			code[codep++].symbol = t->symbol;
			return codep;
		case ADD:
			codep = generate(codep, t->left);
			codep = generate(codep, t->right);
			code[codep++].op = addop;
			return codep;
		case DIVIDE:
			codep = generate(codep, t->left);
			codep = generate(codep, t->right);
			code[codep++].op = divop;
			return codep;
		case MAX:
			codep = generate(codep, t->left);
			codep = generate(codep, t->right);
			code[codep++].op = maxop;
			return codep;			
		/* etc... */		
		default:
			printf("ERROR");
			return 0;
	}
}

// pushop: push number; value is next word in code stream
void pushop(void)
{
	stack[stackp++] = code[pc++].value;
}

void pushsymop(void)
{
	;
}

void addop(void)
{
	;
}

// divop: compute ratio of two expr
void divop(void)
{
	int left, right;
	right = stack[stackp--];
	left = stack[stackp--];
	if(right == 0)
	{
		printf("divide %d by zero\n", left);
		exit(2);
	}
	stack[stackp++] = left / right;
}

void maxop(void)
{
	;	
}

void assignop(void)
{
	;
}
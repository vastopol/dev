// FP parser

#include <cstring>
#include <iostream>
#include <list>
#include <string>

using namespace std;

int main()
{

string input = ""; // initial str to convert char
char* copy = 0;    // copy to give strtok for parse
list<int> seq;     // the sequence to fill from string

cout << ">>> ";
getline(cin, input);
//strcpy(copy, input.c_str()); // copy string to char array for strtok
copy = (char*)(input.c_str());

char* matrix[256] = {0}; // argument vector - contains substrings
char* arr = 0;

// first pass parse on parentheses
arr = strtok(copy, "()");
matrix[0] = arr;
for(unsigned i = 1; arr != 0; i++)
{
    cout << i << endl;
    arr = strtok(NULL, "()");
    matrix[i] = arr;
}

// parse check
for(unsigned i = 0; matrix[i] != 0; i++)
{
    cout << matrix[i] << ", ";
}
cout << endl;


return 0;
}

/*

SYNTAX
------
~  = undefined

() = used for separation like  (2 + (3 * 4))

application
    f:a
    where   function f applied to value a
    
composition  
    f.g
    where   f.g:x = f:(g:x)
    
construction
    where   [1,2,3]  =  {1,2,3}
    
setting
    where  a = 4
        set element a to value 4
    where  c = [4,5,6]
        name and construct new sequence c
    where x = y
        set one unit to the other (if same type)
    
apply-to-all  @f       
    where   @f:{x1,...,xn}  =  {f:x1,...,f:xn}
    
    
condition 
    (h -> f,g)    
    where   (h -> f,g):x   
             =  f:x   if   h:x  =  T
             =  g:x   if   h:x  =  F
             =  ~    otherwise

*/
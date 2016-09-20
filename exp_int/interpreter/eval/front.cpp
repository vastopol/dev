#include "functs_eval.h"
#include "functs_com.h"

#include <iostream>
#include <string>

using namespace std;

// local functions

int main()
{
cout << "EVAL Engine" << endl;
cout << "Enter a command OR an expression/equation to evaluate" << endl;

string input;

do
{
    cout << ">>";
    getline(cin, input);
    cout << input << endl;
    
    if(input == "quit") // to end
    {
        break;
    }
        
    // parse here with arithmetic expression tree
    
    // if starts with "?:" then eval   
    eval(input);
        
    // else call com funct
    //com(input);
}
while(1);

cout << "END" << endl;

return 0;
}
//=====================================================



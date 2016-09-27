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
    getline(cin, input);    // get 
    cout << input << endl;  // echo
    
    if(input == "quit")     // end
    {
        break;
    }
    

    std::string letsee = input.substr(0, 3); // substring start at 0, 3 char long. ergo first 3 char
    // if starts with "?: " then call eval  && parse with arithmetic expression tree
    
    if(letsee == "?: ")
    {
        size_t pos = 3;             // should be at 4th char
        input = input.substr(pos);  // input now cut out "?: "
        eval(input);
    }        
    else //call com funct
    {
        com(input);
    }
    
}
while(1);

cout << "END" << endl;

return 0;
}
//=====================================================



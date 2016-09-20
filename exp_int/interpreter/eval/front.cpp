#include "functs.h"

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
    
    if(input == "quit")
    {
        break;
    }
        
    eval(input);
}
while(1);

cout << "END" << endl;

return 0;
}
//=====================================================



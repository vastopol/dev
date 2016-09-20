#include "functs_com.h"

void com(std::string s)
{
    if(s == "help") // to end
    {
        help();
    }
    else
   {
      cout << "Error:: Unknown Command";
   }
   
   return;
}
//-------------------------------------------------------------------------------------------


void help()
{
    cout << "Have matching parenthesis and correct grammar" << endl;   //// A = B, A != B, A < B, etc... use only 1 binary evaluator
    cout << "separete distinct sub-pieces with borders" << endl;
    cout << " E.g1: \"(1 * 2) = (3 - 1)\"" << endl;
    cout << " E.g2: \"([1 + 3] * 3) = ({24 / 3} + 4)\"" << endl;
    cout << "supports operations:" << endl <<  " &, |, ~, +, -, *, /, %," << endl;
    cout << " =, != <, >, <=, >=" << endl;
    
    return;
}
//-------------------------------------------------------------------------------------------


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
    cout << "Enter commands OR use \"?: \" operator to evaluate expressions & equations." << endl;
    cout << "Have matching parenthesis and correct grammar." << endl;   //// A = B, A != B, A < B, etc... use only 1 binary evaluator
    cout << "Separete distinct sub-pieces with borders." << endl;
    cout << " Ex1. \"?: (1 * 2) = (3 - 1)\"" << endl;
    cout << " Ex2. \"?: ([1 + 3] * 3) = ({24 / 3} + 4)\"" << endl;
    cout << "Supports operations:" << endl <<  " &, |, ~, +, -, *, /, %," << endl;
    cout << " =, != <, >, <=, >=" << endl;
    
    return;
}
//-------------------------------------------------------------------------------------------


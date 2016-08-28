#include "functs.h"

#include <iostream>
#include <string>


using namespace std;


int main()
{

string input;

cout << "Logical Calculator" << endl;
cout << "Enter an expression/equation to evaluate" << endl;

// cout << "Have matching parenthesis and correct grammar" << endl;   //// A = B, A != B, A < B, etc... use only 1 binary evaluator
// cout << "separete distinct sub-pieces with borders" << endl;
// cout << " E.g1: \"(1 * 2) = (3 - 1)\"" << endl;
// cout << " E.g2: \"([1 + 3] * 3) = ({24 / 3} + 4)\"" << endl;
// cout << "supports operations:" << endl <<  " &, |, !, +, -, *, /, %," << endl;
// cout << " =, != <, >, <=, >=" << endl;

//while(1)
//{
  
  
    cout << "?:";
    getline(cin, input);
    // cout << input << endl;
    
    eval(input);

  

//}


return 0;
}



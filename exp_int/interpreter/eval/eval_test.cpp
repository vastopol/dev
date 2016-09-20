#include "functs.h"

/*
logic operations : &, |, !
math operations:  +, -, *, /, %,
evaluations     : =, != <, >, <=, >=
*/


int main()
{
    // test strings
   //std::string str1 = "(1 * 2) = (3 - 1)";
   std::string str2 = "([1 + 3] * 3) = ({24 / 3} + 4)";
   //std::string str3 = "({[9 + 8] + [8 - 7]} * {[1 * 2] * [4 / 2]})";
   
   cout << str2 << endl;
   
   eval(str2); cout << endl;
   

   
return 0;
}



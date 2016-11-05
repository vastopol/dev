#include "functs_eval.h"
#include "functs_com.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
std::cout << "EVAL Engine" << std::endl;
std::cout << "Enter a command OR an expression/equation to evaluate" << std::endl;

std::string input;

do
{
    std::cout << ">>";
    getline(cin, input);    // get 
    std::cout << input << std::endl;  // echo
    
    std::string letsee = input.substr(0, 3); // substring start at 0, 3 char long. ergo first 3 char
    // if starts with "?: " then call eval  && parse with arithmetic expression tree
    
    if(letsee == "?: ")
    {
        size_t pos = 3;             // real input should be at 4th char
        input = input.substr(pos);  // input now cut out "?: "
        
        eval(input);                // call EVAL()
    }        
    else 
    {
        com(input);                 // call COM()
    }
    
}
while(1);

std::cout << "END" << std::endl;

return 0;
}
//=====================================================


#include "functs/functs_parse.h"
#include "functs/functs_com.h"

#include <iostream>
#include <string>

using namespace std;

int main()
{
std::cout << "FP Engine" << std::endl;
std::cout << "Enter a command OR an expression/equation to evaluate" << std::endl;

std::string input;

do
{
    std::cout << ">>> ";
    getline(cin, input);    // get 
    
    std::string arg1 = input.substr(0, 1); 
    // substring start at 0 , 1 char long
    // if starts with "%" then call eval  && parse with arithmetic expression tree
    
    std::string arg2 = input.substr(0, 4);
    // substr 0, 3 long
    // if is "def" then hash
    
    if(arg1 == "%") // eval
    {
        size_t pos = 1;             // real input is past signal
        input = input.substr(pos);  // input now cut out "%"
        exec(input);                // call EXEC()
    }   
    else if(arg2 == "Def ")
    {
        input = input.substr(4, (input.size() - 4) ); // cut out "DEF "
        
        std::cout << input << std::endl;
        
    }
    else 
    {
        com(input); // call COM()
    }
    
}
while(1);

std::cout << "END" << std::endl;

return 0;
}
//=====================================================


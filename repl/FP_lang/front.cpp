#include "functs/parse.h"
#include "functs/com.h"

#include <iostream>
#include <string>
#include <cstring>

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
    
    // if starts with "%"  parse && generate expression tree
    // then call exec to evaluate root of Equation/Expression
    if(input.substr(0, 1) == "%") 
    {
        size_t pos = 1;             // real input is past signal
        input = input.substr(pos);  // input now cut out "%"
        parse(input);                // call EXEC()
    }   
    else if(input.substr(0, 4) == "def ") // Variable Definition
    {
        // syntax: "def name = var"
        input = input.substr(4, (input.size() - 4) ); // cut out "def ", now "name = var"
        
        unsigned pos = input.find(" = "); // location of =
        
        std::cout << input << std::endl;
        std::cout << pos << std::endl;
        
        if(pos >= input.size() || pos == string::npos)
        {
            cout << "syntax error" << endl;
            continue;
        }
        
        // split out "=" and padding spaces
        //std::string var; // variable name, left half
       // std::string val; // variable value, right half
        
        // hash here
        
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


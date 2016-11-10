#include "functs/functs_parse.h"
#include "functs/functs_com.h"

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
    
    std::string str1 = input.substr(0, 1); 
    // substring start at 0 , 1 char long
    // if starts with "%" then call eval  && parse with arithmetic expression tree
    
    std::string str2 = input.substr(0, 4);
    // substr 0, 4 long
    // if is "def" followed by " " then hash
    
    if(str1 == "%") // eval
    {
        size_t pos = 1;             // real input is past signal
        input = input.substr(pos);  // input now cut out "%"
        exec(input);                // call EXEC()
    }   
    else if(str2 == "Def ") // syntax: "Def name = var"
    {
    
        input = input.substr(4, (input.size() - 4) ); // cut out "DEF "
        
        unsigned pos = input.find(" = "); // location of '#'
        
        std::cout << input << std::endl;
        std::cout << pos << std::endl;
        
        // split out "=" and padding spaces
        // std::string var; // variable, declaration, left half
        // std::string val; // value definition, right half
        
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


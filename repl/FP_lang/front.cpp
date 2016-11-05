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
    std::cout << ">>";
    getline(cin, input);    // get 
    std::cout << "echo1: " << input << std::endl;  // echo1
    
    std::string letsee = input.substr(0, 1); // substring start at 0, 3 char long. ergo first 3 char
    // if starts with "?: " then call eval  && parse with arithmetic expression tree
    
    if(letsee == "#")
    {
        size_t pos = 1;             // real input should be at 4th char
        input = input.substr(pos);  // input now cut out "?: "
        std::cout << "echo2: " << input << std::endl;  // echo2
        parse(input);                // call EVAL()
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


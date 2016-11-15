#include "com.h"

void com(std::string s)
{
    if(s == "exit")
    {
        exit(0);
    }
    else if(s == "clear")
    {
        std::cout << "\033c";
        return;
    }
    else if(s == "help")
    {
        help();
    } 
    else
    {
        std::cout << "ERROR: Unknown Command" << std::endl;
        
        // put the exec function here handle sys coms for memory management
        // handle the unknown command in the exec function
        
    }
   
   return;
}
//-------------------------------------------------------------------------------------------


void help()
{
    std::cout << "GENERAL:" << std::endl;
    std::cout << "Enter System commands OR use \"#\" operator to evaluate expressions AND equations." << std::endl;
    std::cout << "Have matching parenthesis and correct syntax and grammar." << std::endl;   //// A = B, A != B, A < B, etc... use only 1 binary evaluator
    std::cout << "Separete distinct sub-pieces with parenthesis." << std::endl;
    std::cout << std::endl;
    
    std::cout << "COMMANDS:" << std::endl;
    std::cout << "help" << " == " << "display help prompt" << std::endl;
    std::cout << "clear" << " == " << "clear the screen contents" << std::endl;
    std::cout << "exit" << " == " << "quit program" << std::endl;
    std::cout << std::endl;
    
    return;
}
//-------------------------------------------------------------------------------------------

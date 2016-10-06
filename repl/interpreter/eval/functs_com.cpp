#include "functs_com.h"

void com(std::string s)
{
    // // UNDOC FEAT... toggle if not need
    // /*//-------------------------------------------------
    if(s == "unsafe") 
    {
        char go = 'X';
        std::cout << "Are you SURE? Y/N?" << std::endl;
        std::cout << ">"; std::cin >> go; std::cout << '\n';
        if(go == 'Y')
        {        
            unsafe(); // danger time
        }
        else
        {
            std::cout << "AUTH::Fail" << std::endl;
        }
    }
    // *///--------------------------------------------------
    
    if(s == "exit")
    {
        quit();
    }
    else if(s == "clear")
    {
        clr_scr();
    }
    else if(s == "help")
    {
        help();
    } 
    else
    {
        std::cout << "Error:: Unknown Command" << std::endl;
    }
   
   return;
}
//-------------------------------------------------------------------------------------------

void unsafe()
{
    std::string danger_com = "DANGER";
    std::cout << '>'; std::cin >> danger_com; std::cout << '\n';
    system(danger_com.c_str());
}
//-------------------------------------------------------------------------------------------

void quit()
{
    clr_scr();
    std::cout << "Goodbye." << std::endl;
    exit(1);
}
//-------------------------------------------------------------------------------------------

void clr_scr()
{
    std::cout << "\033c";
    return;
}
//-------------------------------------------------------------------------------------------

void help()
{
    std::cout << "GENERAL:" << std::endl;
    std::cout << "Enter commands OR use \"?: \" operator to evaluate expressions & equations." << std::endl;
    std::cout << "Have matching parenthesis and correct syntax and grammar." << std::endl;   //// A = B, A != B, A < B, etc... use only 1 binary evaluator
    std::cout << "Separete distinct sub-pieces with borders." << std::endl;
    std::cout << " Ex1. \"?: (1 * 2) = (3 - 1)\"" << std::endl;
    std::cout << " Ex2. \"?: ((1 + 3) * 3) = ((24 / 3) + 4)\"" << std::endl;
    std::cout << "Supports operations:" << std::endl <<  " &, |, ~, +, -, *, /, %," << std::endl;
    std::cout << " =, != <, >, <=, >=" << std::endl;
    std::cout << std::endl;
    
    std::cout << "COMMANDS:" << std::endl;
    std::cout << "help" << " == " << "display help prompt" << std::endl;
    std::cout << "clear" << " == " << "clear the screen contents" << std::endl;
    std::cout << "exit" << " == " << "quit program" << std::endl;
    std::cout << std::endl;
    
    return;
}
//-------------------------------------------------------------------------------------------

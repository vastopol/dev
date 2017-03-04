#include <iostream>
#include <string>
#include <stack>
#include <iterator>

// local functions
std::string revStack(std::string s); // reverse string 

bool is_palind(std::string s); // return true is str is palindrome

//==============================================================
int main()
{
    std::string test;

    std::cout << "enter string" << std::endl;
    std::getline(std::cin, test);
    
    std::cout << (is_palind(test) ? "Palindrome!" : "Not Palindrome") << std::endl;
     
return 0;
}
//==============================================================


std::string revStack(std::string s)
{
    std::string dum;
    std::stack<char> sss;
    
    for(std::string::iterator it = s.begin(); it != s.end(); it++)
    {
        sss.push(*it);
    }
    
    while(!sss.empty())
    {
        dum.push_back(sss.top());
        sss.pop();
    }
    
    return dum;
}
//----------------------------------------------------------


bool is_palind(std::string s)
{
    return s == revStack(s);
}
//-----------------------------------------------------------

// Algorithm for checking if ballanced (), [], {}
// used in UCR CS14

#include <iostream>
#include <string>
#include <stack>
#include <iterator>

// local function
bool isBalanced(std::string s);

//==============================================================
int main()
{
    std::string test;

    std::cout << "enter string" << std::endl;
    std::getline(std::cin, test);
    
    std::cout << (isBalanced(test) ? "Balanced" : "Not Balanced") << std::endl;
     
return 0;
}
//==============================================================



bool isBalanced(std::string s) // check for ballanced number of separators: (), [], {}
{
    std::stack<char> ppp;
    
    for(std::string::iterator it = s.begin(); it != s.end(); it++)
    {
        if(*it == '(' || *it == '[' || *it == '{')
        {
            ppp.push(*it);
        }
        else if(*it == ')' || *it == ']' || *it == '}')
        {
            if(ppp.empty())
            {
                return false;
            }
            else
            {
                if(*it == ')' && ppp.top() != '(' )
                {
                    return false;
                }
                else if(*it == ']' && ppp.top() != '[' )
                {
                    return false;
                }
                else if(*it == '}' && ppp.top() != '{' )
                {
                    return false;
                }
                else
                {
                    ppp.pop();
                }
            } 
        }
    }
    
    return ppp.empty();
}
//-------------------------------------------------------------------------------------------
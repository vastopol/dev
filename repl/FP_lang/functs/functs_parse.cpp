#include "functs_parse.h"


bool exec(std::string str) // evaluation engine
{
    //PRELIMINARY CHECKS
    if(str.empty()) 
    {
      cout << "Error:: empty string" << endl; 
      return false;
    }
    else if(!isBalanced(str))
    {
      cout << "Error:: incorrect grammar : (,[,{..." << endl; 
      return false;
    }
    
    // here
    cout << "Parse here" << endl;
    
return false;  
}
//-------------------------------------------------------------------------------------------


bool isBalanced(string s) // check for ballanced number of separators (, {, [
{
    stack<char> ppp;
    
    for(string::iterator it = s.begin(); it != s.end(); it++)
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



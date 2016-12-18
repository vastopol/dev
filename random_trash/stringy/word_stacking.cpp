#include <iostream>
#include <string>
#include <stack>
#include <iterator>

using namespace std;

string revStack(string s);

bool palind(string s);

bool isBalanced(string s);



int main()
{
    string test = "table";
    string test2 = "kayak";
    string test3 = "(2 * (3 + 4))";
    string test4 = ")5*6 (";
    string test5;
    
    // cout << test << endl;
    // cout << revStack(test) << endl;
    
    // cout << (palind(test) ? "Palindrome!" : "Not Palindrome") << endl << endl;
    
    
    // cout << test3 << endl;
    // cout << (isBalanced(test3) ? "Balanced" : "Not Balanced") << endl; 
    // cout << test4 << endl;
    // cout << (isBalanced(test4) ? "Balanced" : "Not Balanced") << endl;
    
    cout << "enter eqn" << endl;
    getline(cin, test5);
    cout << (isBalanced(test5) ? "Balanced" : "Not Balanced") << endl;
    
    

return 0;
}


string revStack(string s)
{
    string dum;
    stack<char> sss;
    
    for(string::iterator it = s.begin(); it != s.end(); it++)
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
//------------------------------------------------------------------


bool palind(string s)
{
    return s == revStack(s);
}
//-----------------------------------------------------------

bool isBalanced(string s)
{
    stack<char> ppp;
    
    for(string::iterator it = s.begin(); it != s.end(); it++)
    {

        if(*it == '(' || *it == '[' || *it == '<' || *it == '{')
        {
            ppp.push(*it);
        }
        else if(*it == ')' || *it == ']' || *it == '>' || *it == '}')
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
                else if(*it == '>' && ppp.top() != '<' )
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
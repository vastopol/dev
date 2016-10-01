#include "functs_eval.h"


bool eval(std::string str) // evaluation engine
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
   
   //LOCAL VARS
   std::queue<std::string> Que;     // begining string
   std::queue<std::string> QueL;    // if eqn holds left side
   std::queue<std::string> QueR;    // if eqn holds right side
   std::string temp;                // if eqn holds comparator
   
   // take out space character spearators
   unsigned i = 0;
   unsigned j = 0;
   for(; i < str.size(); i++)
   {
      if(str.at(i) == ' ' || i == str.size()-1)
      {
         for(; j <= i ; j++)
         {
            temp += str.at(j);
         }
         
         if(j != str.size())
         {
            temp = temp.substr(0,temp.size()-1); // get rid of the space after the string 
         }
         Que.push(temp);
         temp.clear();
      }
   }
   
   // now at this point Q contains pieces separate but in order, no spaces
   // if an equation then
   // have to separate into sub parts to be evaluated separately and compared
   // QueL = left half before eval sign
   // QueR = right half after eval sign
   // set temp = eval sign and use that aside
   // else evaluate expression


    // err check
    if(Que.empty())
    {
      cout << "Error:: empty Queue in eval function" << endl; 
      return false;
    }

    if(isEqn(Que))   
    {
        cout << "Equation not done" << endl;
        
        while(Que.front() != "=" && Que.front() != "!=" && Que.front() != "<" && Que.front() != "<=" && Que.front() != ">" && Que.front() != ">=")
        {
            QueL.push(Que.front()); //fill Queue for left side
            Que.pop();
        }
        
        temp = Que.front(); Que.pop();  // capture the evaluator
        QueR = Que;                     // fill Queue for right side with leftovers
        
        
        // NOW, have branch for temp to choose how after evaluation what corresponding truth value is for A vs B
        // all cases for each possibility plus default catch
        // recursive eval each half and compare
        // return truth value
        
        
        /*
            bool z = false;
            x = recurEval(QueL) ??
            y = recurEval(QueR) ??
        
            if(temp == "=")         // =
            {
            }
            else if(temp == "!=")   // !=
            {
            }
            else if(temp == "<")    // <
            {
            }
            else if(temp == "<=")   // <=
            {
            }
            else if(temp == ">")    // >
            {
            }
            else if(temp == ">=")   // >=
            {
            }
            else        //default catch
            {
                cout << "ERROR:: unknown evaluator" << endl;
                return false;
            }
        
        */
        
        
        
        //   cout << "After" << endl;
        
        //   while(!QueL.empty())
        //   {
        //       cout << QueL.front() << ',';// << ',' << endl;
        //       QueL.pop();
        //   }
          
        //   cout << endl << temp << endl;
          
        //   while(!QueR.empty())
        //   {
        //       cout << QueR.front() << ',';// << ',' << endl;
        //       QueR.pop();
        //   }
          
    }
    else    
    {
        // run through rescrsuve evauator output result && true
        cout << "Expression" << endl;
        
        //   while(!Que.empty())
        //   {
        //       cout << Que.front() << ',';
        //       Que.pop();
        //   }
      
      
      cout << "not done expression evaluator" << endl;
        
    }
        

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


bool isEqn(std::queue<std::string> Que) // segfault?? maybe
{    
    if(Que.empty()) return false; // err chk?
     
    while(!Que.empty())
    {
        if(Que.front() != "=" && Que.front() != "!=" && Que.front() != "<" && Que.front() != "<=" && Que.front() != ">" && Que.front() != ">=") 
        {
            Que.pop();
        }
        else
        {
            break;
        }
    }
    
    // should still have pieces left if there is an eval sign
    return !Que.empty();
}
//-------------------------------------------------------------------------------------------


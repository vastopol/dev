// Algorithm for removing ' ' 

#include <iostream>
#include <string>
#include <stack>
#include <queue>

using namespace std;


//string parse for ' ' keep order
queue<string> spaceOut(const string& str)
{
    queue<string> Q1;
    
    for(unsigned k= 0; k < str.size(); k++) // collect up individual words
    {
        string temp;
        
        for(unsigned h = k; k < str.size() && str.at(k) != ' '; h++)
        {
            temp.push_back( str.at(h) );
            k++;
        }

        Q1.push(temp); // queue of words
    }
    
    return Q1;
}

int main()
{

    string test;
    queue<string> testQ;
    
    getline(cin, test);
    cout << endl;
        
    testQ = spaceOut(test);
    
    cout << endl << "out Q" << endl << endl;
    
    while(!testQ.empty())
    {
        cout << testQ.front() << endl;
        testQ.pop();
    }
    
return 0;
}
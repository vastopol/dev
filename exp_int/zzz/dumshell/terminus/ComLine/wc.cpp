// word count program
// mimics the unix wc function

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
    
    
    if(argc != 2)
    {
        return 1;
    }
    
    ifstream inFS;
    string s;
    int charCnt = 0;
    char ch = 'c';
    int wordCount = 0;
    int lineCount = 0;
    
    inFS.open(argv[1]);
    if(!inFS.is_open())
    {
         cout << "error opening file" << endl;  
         return 1;
    }
    
   
    while(inFS.get(ch))
    {
        charCnt++;
        if(iswspace(ch)) // is whitespace
        {
            if(iswspace(inFS.peek())) // looks at next char but not extract or anything
            {
                wordCount++;
            }
        }
        if(ch == '\n')
        {
           lineCount++; 
        }
        inFS.peek();
        if(ch != '\n' && inFS.eof())
        {
            ++lineCount;
        }
    }
    
    cout << charCnt << endl;
    cout << wordCount << endl;
    cout << lineCount << endl;
    
return 0;
}
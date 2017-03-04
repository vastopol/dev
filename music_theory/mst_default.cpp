//  musical set theory 
//  STD = C++11

#include "mus_f.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>
#include <sstream>
#include <string>

using namespace std;

void fillVector(vector<int>& v);
queue<string> spaceOut(const string& str);

int main()
{
    // PRESET VARIABLES
    // vector<int> v = {0,1,2,3,4,5,6,7,8,9,10,11}; // chromatic scale from c
    // vector<int> v = {0,4,7}; // Cmaj triad
   
    int n; // choice
    vector<int> v;

    do{
        
        fillVector(v);
        if(v.empty()){cout << "Empty\n"; continue;}
        
        cout << "Before:" << endl;
        display(v);
    
        cout << "Choose operation:\n" << "1. Transpose\n"
             << "2. Inversion\n" << "3. Retrograde" << endl;
        
        cin >> n;
        
        switch(n)
        {
            case 1: transpose(v); break;   // transposition
            case 2: invert(v); break;      // inversion
            case 3: R(v); break;           // retrograde
            default: cout << "ERROR::unknown entry" << endl; break;
        }
    
        cout << "After:" << endl;
        display(v);
        cout << endl;
    
        v.clear();              // empty vector 
        cin.clear();
        cin.ignore(256, '\n');  // clear cin of newlines, reset flags
    
    
    }while(1);

return 0;
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------


void fillVector(vector<int>& v)
{
    string str;
    queue<string> strQ;
    cout << "Enter notes of chord, separate with spaces" << endl;
    
    getline(cin,str);
    
    strQ = spaceOut(str);
    
    while(!strQ.empty()) 
    {
        if(strQ.front() == "C")
        {
            v.push_back(0);
        }
        else if(strQ.front() == "C#")
        {
            v.push_back(1);
        }
        else if(strQ.front() == "D")
        {
            v.push_back(2);
        }
        else if(strQ.front() == "D#")
        {
            v.push_back(3);
        }
        else if(strQ.front() == "E")
        {
            v.push_back(4);
        }
        else if(strQ.front() == "F")
        {
            v.push_back(5);
        }
        else if(strQ.front() == "F#")
        {
            v.push_back(6);
        }
        else if(strQ.front() == "G")
        {
            v.push_back(7);
        }
        else if(strQ.front() == "G#")
        {
            v.push_back(8);
        }
        else if(strQ.front() == "A")
        {
            v.push_back(9);
        }
        else if(strQ.front() == "A#")
        {
            v.push_back(10);
        }
        else if(strQ.front() == "B")
        {
            v.push_back(11);
        }
        else
        {
            cout << endl << "ERROR: "<< strQ.front() << endl; // ERROR CHECK
            strQ.pop();
            continue;
        }
        cout << strQ.front() << ' ';
        strQ.pop();
    }
    
    cout << endl;
    
    return;
}
//-----------------------------------------------------

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
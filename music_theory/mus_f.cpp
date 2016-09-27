//  musical set theory
//  STD = C++11

#include "mus_f.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;


void display(vector<int> &v)
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        switch(v.at(i))
        {

            case 0: cout  << "C" << ' '; break;
            case 1: cout  << "C#" << ' '; break;
            case 2: cout  << "D" << ' '; break;
            case 3: cout  << "D#" << ' '; break;
            case 4: cout  << "E" << ' '; break;
            case 5: cout  << "F" << ' '; break;
            case 6: cout  << "F#" << ' '; break;
            case 7: cout  << "G" << ' '; break;
            case 8: cout  << "G#" << ' '; break;
            case 9: cout  << "A" << ' '; break;
            case 10: cout << "A#" << ' '; break;
            case 11: cout << "B" << ' '; break;
            default: cout << "X" << ' '; break; // ERROR CHECK
        }
    }
    cout << endl;
}
//-----------------------------------------------------------------

void transpose(vector<int> &v)
{
    vector<int> s = {0,1,2,3,4,5,6,7,8,9,10,11}; // from c , change to key current
    vector<int> r = {0,1,2,3,4,5,6,7,8,9,10,11}; // from c , for reference to

    string keyTo = "xXx";
    bool noGo = false;
    int tones = 0;
    unsigned i = 0;  // loop index 
    unsigned kk = 0; // index measured by degrees on chromatic from c

    //correct s to the leading tone of v
    T(s, v.at(0));

    do{
        cout << "Enter key to transpose series to: " << endl;
        cin >> keyTo;
        noGo = false;

        // SET the var, measured by degrees on chromatic from c
        if(keyTo == "C")
        {
            kk = 0;
        }
        else if(keyTo == "C#")
        {
            kk = 1;
        }
        else if(keyTo == "D")
        {
            kk = 2;
        }
        else if(keyTo == "D#")
        {
            kk = 3;
        }
        else if(keyTo == "E")
        {
            kk = 4;
        }
        else if(keyTo == "F")
        {
            kk = 5;
        }
        else if(keyTo == "F#")
        {
            kk = 6;
        }
        else if(keyTo == "G")
        {
            kk = 7;
        }
        else if(keyTo == "G#")
        {
            kk = 8;
        }
        else if(keyTo == "A")
        {
            kk = 9;
        }
        else if(keyTo == "A#")
        {
            kk = 10;
        }
        else if(keyTo == "B")
        {
            kk = 11;
        }
        else
        {
            cout << "ERROR" << endl; // ERROR CHECK
            noGo = true;
        }

    }while(noGo == true);
   
    while(s.at(i) != r.at(kk)) // move by to scale if need...
    {
        tones++;
        i++;
    }

    T(v, tones); // call T()
    
    return;
}
//-----------------------------------------------------------------

void T(vector<int> &v, int n) // transposition by n semitones
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        v.at(i) = (v.at(i) + n) % 12;
    }
}
//-----------------------------------------------------------------

void invert(vector<int> &v) // inversion helper
{
    queue<int> q;
    int k = -1;
    int n;

    // count inverversions
    for(unsigned i = 0; i < v.size(); i++) // fill queue
    {
        q.push(v.at(i));
    }

    cout << "@0: "; display(v);
    for(unsigned i = 0; i < v.size() ; i++)
    {
        k = q.front();
        q.pop();
        q.push(k);

        for(unsigned j = 0; j < v.size(); j++)
        {
            v.at(j) = q.front();
            k = q.front();
            q.pop();
            q.push(k);
        }
        if(i < v.size()-1) // sz-1 possible inversions before repeat
        {
            cout << "@" << (i + 1) << ": ";
            display(v);
        }
    }

    // user input
    cout << "enter inversion index:" << endl;
    cin >> n;

    I(v, n);

}
//-----------------------------------------------------------------

void I(vector<int> &v, int n) // inversion n times
{
    queue<int> q;
    int k = -1;
    
    for(unsigned i = 0; i < v.size(); i++) // fill queue
    {
        q.push(v.at(i));
    }
    
    for(unsigned i = 0; i < n ; i++) // cycle through inversions
    {
        k = q.front();
        q.pop();
        q.push(k);

        for(unsigned j = 0; j < v.size(); j++)
        {
            v.at(j) = q.front();
            k = q.front();
            q.pop();
            q.push(k);
        }
    }
}
//-----------------------------------------------------------------

void R(vector<int> &v) // retrograde
{
    std::reverse(v.begin(), v.end());
}
//----------------------------------------------------------------


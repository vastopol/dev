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

    //correct s to the leading tone of v
    T(s, v.at(0));

    do{
        cout << "Enter key to transpose series to: " << endl;
        cin >> keyTo;
        noGo = false;

        // measured by degrees on chromatic from c
        if(keyTo == "C")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(0))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "C#")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(1))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "D")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(2))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "D#")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(3))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "E")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(4))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "F")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(5))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "F#")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(6))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "G")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(7))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "G#")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(8))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "A")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(9))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "A#")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(10))
            {
                tones++;
                i++;
            }
        }
        else if(keyTo == "B")
        {
            unsigned i = 0;
            while(s.at(i) != r.at(11))
            {
                tones++;
                i++;
            }
        }
        else
        {
            cout << "ERROR" << endl; // ERROR CHECK
            noGo = true;
        }

    }while(noGo == true);

    T(v, tones); // call T()
}
//-----------------------------------------------------------------

void T(vector<int> &v, int n) // transposition
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        v.at(i) = (v.at(i) + n) % 12;
    }
}
//-----------------------------------------------------------------

void I(vector<int> &v) // inversion
{
    queue<int> q;
    int k = -1;
    int n;

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


    cout << "enter number of inversions to perform:" << endl;
    cin >> n;

    for(unsigned i = 0; i < n ; i++)
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
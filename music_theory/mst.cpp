//  musical set theory test
//  STD = C++11

#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


void display(vector<int> &v);

void T(vector<int> &v, int n); // transpose by n semitones

void R(vector<int> &v); // retrograde = reversal


int main()
{
    
    //vector<int> v = {0,1,2,3,4,5,6,7,8,9,10,11}; // chromatic scale
    
    vector<int> v = {0,4,7}; // Cmaj triad
    int n;
    
    cout << "Before" << endl;
    display(v);

    // // transpose    
    // cout << "enter number of semitones to shift by" << endl;
    // cin >> n;
    // T(v, n);
    
    // //retrograde
    // R(v);
    
    cout << "After" << endl;
    display(v);
    
return 0;
}

void display(vector<int> &v)
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        switch(v[i])
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

void T(vector<int> &v, int n)
{
    for(unsigned i = 0; i < v.size(); i++)
    {
        v[i] = (v[i] + n) % 12;
    }
}
//-----------------------------------------------------------------

void R(vector<int> &v)
{
    std::reverse(v.begin(), v.end());
}
//----------------------------------------------------------------


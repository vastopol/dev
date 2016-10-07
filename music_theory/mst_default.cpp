//  musical set theory test
//  STD = C++11

#include "mus_f.h"

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

int main()
{
    // //VARIABLES
    //vector<int> v = {0,1,2,3,4,5,6,7,8,9,10,11}; // chromatic scale from c
    vector<int> v = {0,4,7}; // Cmaj triad

    int n; // choice

    cout << "Before" << endl;
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

    cout << "After" << endl;
    display(v);

return 0;
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------





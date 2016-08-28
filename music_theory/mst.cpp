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

    //vector<int> v = {0,1,2,3,4,5,6,7,8,9,10,11}; // chromatic scale from c

    vector<int> v = {0,4,7}; // Cmaj triad

    //vector<int> v = {2,6,9}; // Dmaj triad

    int n;

    cout << "Before" << endl;
    display(v);

        // // transposition
        //transpose(v);


        // // retrograde
        //R(v);

        // // inversion
        //I(v);

    cout << "After" << endl;
    display(v);

return 0;
}
//-----------------------------------------------------------------
//-----------------------------------------------------------------





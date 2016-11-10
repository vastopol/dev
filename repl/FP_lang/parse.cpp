// FP parser
#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <vector>

using namespace std;

int main()
{

string input = "";     // initial str to convert char
char* copy = 0;        // copy to give strtok for parse
char* arr = 0;         // temp array
vector<string> matrix; // argument vector - contains substrings

cout << ">>> ";
getline(cin, input);
copy = (char*)(input.c_str()); // copy string to char array for strtok

// 1. first pass parse on "()"
//--------------------------------
arr = strtok(copy, "()");
matrix.push_back(string(arr));
for(unsigned i = 1; arr != 0; i++)
{
    arr = strtok(NULL, "()");
    if(arr)
    {
        matrix.push_back(string(arr));
    }
}
//---------------------------------

// parse check
for(unsigned i = 0; i < matrix.size(); i++)
{
    cout << matrix.at(i) << ',';
}
cout << endl;

// now must parse individual matrix substrings individually

// 2. second pass parse on ":"

// for(unsigned i = 1; i <= matrix.size(); i++)
// {
//     for()
//     {
//          
//     }
// }



return 0;
}


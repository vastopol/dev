// main
// cstrings and char arrays
// displays everything entered into command line with stripped whitespace


#include <iostream>
#include <cstring>

using namespace std;

int main(int argc, char** argv)
{
 
     for(int i = 0; i < argc ; i++)
     {
         cout << argv[i];
     }
     cout << endl;
 
return 0;   
}
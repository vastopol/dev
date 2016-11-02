#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[])
{
    ofstream outFS;
    string fileName = "default.txt"; // default

    if(argc > 1) // will only use argv[1] 
    {
        fileName = string(argv[1]); // set file name to user choice
    }
    
    outFS.open(fileName.c_str);
    if(!outFS.is_open())
    {
        cout << "ERROR: Failed to open " << fileName << endl;
        exit(1);
    }
    
        
    
return 0;
}
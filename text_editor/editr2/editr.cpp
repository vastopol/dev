// EDITR - very simple text editor, built around streams

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

int main(int argc, char* argv[]) // comline arg to executable will become name
{
    ifstream inFS;  // to read in from file && display
    ofstream outFS; // to write to file
    string fileName = "default.file"; // default file name

    if(argc == 2) // will only use argv[1] 
    {
        fileName = string(argv[1]); // set file name to user choice
    }
    else if(argc > 2) // too many args
    {
        cout << "ERROR: Too many arguments, will only build first" << endl;
        fileName = string(argv[1]); // still set file name but to first user choice
    }
    
    outFS.open(fileName.c_str());
    if(!outFS.is_open())
    {
        cout << "ERROR: Failed to open " << fileName << endl;
        exit(1);
    }
    
    // PLANS
    // Now file is open and ready to recieve user input
    
    // read in user input, print it to screen, then send to file
    
    // if user wants to see file close out stream, then open instream and read file to screen.
    // after close instream and reopen outstream for editing
    
    // have an option to select a line to edit, close outFS, open inFS pull up and display line, close infs
    // then open outFS, user gives start to end point to replace, and the text to replace it with
    
        
return 0;
}
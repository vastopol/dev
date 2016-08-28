////dumshell function implementation

#include "dumDef.h"

#include <algorithm>
#include <cstdlib>
#include <cstring>
#include <ctime>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

void comExe(string& com)
{
    
    if(com == "help")
    {
       helpMenu();
       return;
    }
    else if(com == "clear")
    {
       clearScreen();
    }
    else if(com == "mkfile")
    {
        fileGen();
    }
    else
    {
       cout << "ERROR: Unrecognized Command" << endl;
       cout << "Input " << "\"" << com << "\"" << " does not match any known arguments" << endl;
       return;
    }
    
return;
}

//=========================================================================

void clearScreen()
{
    cout << "\033c";
    return;
}

//=========================================================================

void helpMenu()
{
    cout << "HELP_MENU" << endl;
    cout << "$: \"clear\" == clear screen" << endl;
    cout << "$: \"mkfile\" == create new file" << endl;
    cout << "$: \"quit\" == end dumshell program" << endl;
    return;
}

//=========================================================================
void fileGen()
{
      string fileName;
      ofstream fout;
      
      cout << "file generator" << endl;
      cout << "Enter new file name . extension" << endl;
      cout << ">> ";
      cin >> fileName;
      
      fout.open(fileName.c_str()); // create file here

      if(!fout)
      {
         cout << "ERROR: Making new file" << endl;
         return;
      }
      else 
      {
         cout << "New File \"" << fileName << "\" created" << endl;
      }
      
      fout.close(); // close new gen file
}
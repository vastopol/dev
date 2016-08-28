// definitions of dumshell functions

#ifndef __DUMDEF_H__
#define __DUMDEF_H__

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


void comExe(string& s); // takes string in and executes according command

void clearScreen(); // clear escape sequence

void helpMenu(); // display list of valid commands

void fileGen(); // make a new file




#endif //__DUMDEF_H__
// program to read a file's content and output to the terminal

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
       
    //part 1
    cout << "argv[0]: " << argv[0] << endl;

//adds .cpp to make sure program opens c++ files
//disable part 2 to create corruptable files

    //part 2
    string s = argv[0];
    cout << "s: " << s << endl;
    s += ".cpp";
    cout << "s: " << s << endl;
    
    //part 2 alt using cstrings
    
        char* cstring = 0;
        
        //number of memory spaces in original:
        //strlen(argv[0]) + 1
        
        cstring = new char[strlen(argv[0]) + 5];
        
        int i = 0;
        unsigned int len = strlen(argv[0]);
        for(; i < len; ++i)
        {
            cstring[i] = argv[0][i];
        }
        cstring[i++] = '.';
        cstring[i++] = 'c';
        cstring[i++] = 'p';
        cstring[i++] = 'p';
        cstring[i] = '\0';
        cout << "cstring: " << cstring << endl;
      
    //part 3
    string name;
    
    cout << endl;
    cout << "Enter name of file to read: (file_name.type_of_file)" << endl;
    cout << "to print from other directories full path needed"<< endl;
    cout << "DO NOT ENTER: a.out" << endl;
    cout << ">> ";
    cin >> name;
    
    // .c_str()
    ifstream ifs(name.c_str());
    if(!ifs.is_open())
    {
        cout << "error could not open \"" << name << "\" for reading" << endl;
        return 0;
    }
    
    string line;
    cout << endl;
    
    while(ifs.good())
    {
        getline(ifs, line );
        cout << line << endl;
    }
    //cout << line << endl;
    
return 0;   
}
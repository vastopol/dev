// program to read a file's content and output to the terminal

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
    string name;

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
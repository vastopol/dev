//file printer strips whitespace
// FIXME

#include<iostream>
#include<string>
#include<fstream>
#include<cstdlib>
#include<cstring>

using namespace std;

int main(int argc, char** argv)
{
    if(argc == 1)
    {
        cout << "ERROR missing args" << endl;
        exit(1);
    }
    
    // command-line argument interface
    // name of current program is in argv[0], and string knows how to handle it.
    string inFName = argv[1];
    
    // create an input file stream (open a file for reading)
    ifstream fin;
    
    // try to open the filename we created. Notice ".c_str()". this is necessary
    fin.open(inFName.c_str());
    
    // sanity check: is the file open?
    if (!fin.is_open()) 
    {
        // not open? error
        cout << "FIN: ERROR while opening \"" << inFName << "\" for reading." << endl;
        return 1;
    }
    
    // now for the output file. 
    string outFName;
    if(argc == 3) 
    {
        outFName = argv[2]; 
    }
    else
    {
        outFName = "default.dat"; //Here's a default name
    }
    
    // create an output file stream (open a file for writing)
    ofstream fout;
    
    // try to open the file named by "outFName"
    fout.open(outFName.c_str());
    
    // sanity check: is the file open?
    if(!fout.is_open()) 
    {
        cout << "FOUT: ERROR while opening \"" << outFName << "\" for writing." << endl;
        return 1;
    }

    // temp for storing each line
    string line;
    
    // go through all lines provided by fin
    while(fin.good())
    {
        // get a line
        getline(fin, line);
        
        // if there's a comment
        if(line.find("//") != string::npos)
        {
            // resize to get rid of the comment
            line.resize(line.find("//"));
        }
        
        // no more comment! print to file
        fout << line << endl;
        
    } // no more input lines
    
    // close the input file
    fin.close();
    
    // close the output file
    fout.close();
    
    return 0;
}
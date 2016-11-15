// FP parser
#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <vector>

using namespace std;

void exec(std::string str);
void def(std::string s); // definition, hashing name to value

int main()
{

string input = "";     // initial str to convert char

cout << ">>> ";
getline(cin, input);

exec(input);


return 0;
}
//=========================================================
//=========================================================


void exec(std::string str)
{    
    if(str.substr(0, 3) == "def") // Variable Definition
    {        
        // syntax: "def name = var"
        unsigned pos = str.find(" "); // location of first space
        if(pos != 3)
        {
            std::cout << "ERROR: Syntax" << std::endl;
            return;
        }

        // cut out "def ", now "name = var"
        def( str.substr(4, (str.size() - 4) );
    }
    else
    {
        char* copy = 0;        // copy to give strtok for parse
        char* arr = 0;         // temp array
        vector<string> matrix; // argument vector - contains substrings
        copy = (char*)(str.c_str()); // copy string to char array for strtok
        
        // parse on "()"
        ///************************************************************
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
        
        // parse check
        for(unsigned i = 0; i < matrix.size(); i++)
        {
            cout << matrix.at(i) << ',';
        }
        cout << endl;
        
        ///*************************************************************
        
        // now must parse individual matrix substrings individually
        // 2. second pass parse on ":"

    }

}
//------------------------------------------------------------------------------------------


void def(std::string s) 
{
    // syntax: name = value
    // where element
    //    name = atom   (x = 3)
    // OR
    // where sequence
    //    name = {atom,...,atom}   (s = {1,2,3})
    
    unsigned pos = s.find(" = "); // location of =
    
    std::cout << s << std::endl;
    std::cout << pos << std::endl;
    
    if(pos >= s.size() || pos == std::string::npos)
    {
        std::cout << "ERROR: Syntax" << std::endl;
        return;
    }
            
    // split out "=" and padding spaces
    std::string var = s.substr(0, (pos + 1)); // variable name, left half; sz = pos + 1
    pos = s.find_last_of(" "); // location of last " "
    std::string val = s.substr((pos + 1), (s.size() - pos)); // variable value, right half
    
    std::cout << var << std::endl;
    std::cout << val << std::endl;
    
    // hash here
}
//-----------------------------------------------------------------------------------------
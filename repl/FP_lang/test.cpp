// FP parser harness

#include <iostream>
#include <cstring>
#include <string>
#include <list>
#include <vector>

using namespace std;

void exec(std::string str); // parse internal mockup for definiton
void def(std::string s); // definition, hashing name to value
void rem(std::string s); // access hashes and remove var if found
void print(); // print element hash, print list hash

int main(){

string input = "";     // initial str to convert char

do{
    cout << ">>> ";
    getline(cin, input);
    exec(input);
}while(1);

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
            std::cout << "ERROR1: Syntax" << std::endl;
            return;
        }

        // cut out "def ", now "name = var"
        def( str.substr(4, (str.size() - 4) ));
        return;
    }
    else if(str.substr(0, 2) == "rm")
    {
        // syntax: "rm name"
        unsigned pos = str.find(" "); // location of first space
        if(pos != 2)
        {
            std::cout << "ERROR1: Syntax" << std::endl;
            return;
        }   
        
        // remove the variable
        rem( str.substr(3, (str.size() - 1) ));
    }
    else if(str.substr(0, 2) == "ls")
    {
        //print all vars
        print();
    }
    else
    {
        std::cout << "other" << std::endl;
    }
}
//------------------------------------------------------------------------------------------


void def(std::string s) // definition function
{
    // split out "=" and padding spaces
    //**************************************************
    unsigned pos = s.find(" = "); // location of =
    if(pos >= s.size() || pos == std::string::npos)
    {std::cout << "ERROR2: Syntax" << std::endl; return;}
            
    std::string var = s.substr(0, (pos + 1)); // variable name, left half; sz = pos + 1
    if(var.empty()){std::cout << "ERROR3: Syntax -> var" << std::endl; return;}
    
    pos = s.find_last_of(" "); // location of last " "
    if(pos >= s.size() || pos == std::string::npos)
    {std::cout << "ERROR4: Syntax" << std::endl; return;}
    
    std::string val = s.substr((pos + 1), (s.size() - pos)); // variable value, right half
    if(val.empty()){std::cout << "ERROR5: Syntax -> val" << std::endl; return;}
    //*****************************************************
    
    // hash here
    //**************************************************************
    if(val.at(0) == '{' && val.at(val.size() - 1) == '}' ) // sequence
    {
        std::cout << "Sequence: " << std::endl;
        
        val = val.substr(1, (val.size() - 1)); // gone {
        val = val.substr(0, (val.size() - 1)); // gone }
        if(val.empty()){std::cout << "ERROR6: Def of Empty seq.\nPush null list later" << std::endl; return;}
        
        std::list<string> ls;
        char* copy = (char*)(val.c_str());        // copy to give strtok for parse
        char* arr = 0;         // temp array
        
        // extract && store the elements of the sequence        
        arr = strtok(copy, ",");
        ls.push_back(std::string(arr));
        for(unsigned i = 1; arr != 0; i++)
        {
            arr = strtok(NULL, ",");
            if(arr)
            {
                ls.push_back(std::string(arr));
            }
        } 
        
        // parse check, print list
        for(list<std::string>::iterator it = ls.begin(); it != ls.end(); it++)
        {
            std::cout << *it << ", ";
        }
        std::cout << std::endl;
        
    }
    else // element
    {
        std::cout << "element: " << std::endl;
        std::cout << var << std::endl;        
        std::cout << val << std::endl;
        
    }
    //******************************************************************************
    
}
//-----------------------------------------------------------------------------------------

void rem(std::string s) // access hashes and remove var if found
{
    std::cout << s << std::endl;
}
//------------------------------------------------------------------------------------------

void print() // print element hash, print list hash
{
    std::cout << "print function" << std::endl;
}
//------------------------------------------------------------------------------------------
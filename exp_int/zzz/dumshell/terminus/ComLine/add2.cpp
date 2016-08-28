// stuff
// adds 2 numbers entered into command line after argumenet

#include <iostream>
#include <cstring>
#include <cstdlib>

using namespace std;

int main(int argc, char** argv)
{
    if(argc != 3)
    {
        cout << "error\n";
    }
    else
    {
        cout << atoi(argv[1]) + atoi(argv[2]) << endl;   
    }
    
    
    
return 0;
}
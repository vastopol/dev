// char loop
// 10x10 blocks of random ascii characters

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

int main()
{
    srand(time(NULL));
    
    int loopStop = 10;
    int num = 0;
    
    for(int i = 0; i < loopStop; i++)
    {
        for(int j = 0; j < loopStop; j++)
        {
            num = rand() % 126 + 1;  
            // 32 - 126 normal ascii
            // 128 - 255 to extend ascii
            
            while(num < 33) // values over 32 can be cast char && output (32 == space)
            {
                num = rand() % 126 + 1; 
            }
    
            cout << static_cast<char>(num) << ' ';
        }
        cout << endl;
    }
    
return 0;
}
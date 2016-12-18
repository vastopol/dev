#include <iostream>
#include <string>

using namespace std;

#define ARR_SIZE 5  //Here to change arr size...

int main()
{
    int x[ARR_SIZE];
    
    int* p = x; // pointer to array first element
    
    char* cp = (char*)x;
    
    cout << "enter 5 numbers" << endl;
    
    for(int i = 0; i < ARR_SIZE; i++)
    {
        cout << ">> ";
        cin >> x[i];
    }
    
    
    for (int i = 0; i < ARR_SIZE; i++)
    {
        
        cout << "*p " << *p << " || "; // output the value
        
        for (int i = 0; i < 4; i++) // Cycle through the 4 bytes of the int, outputting each byte as if it were an int
        {
            cout << (int)(*cp); 
            cp++;
        }
        cout << endl;
      
        p++; // make the pointer point to the next one 
      
    }

return 0;
}
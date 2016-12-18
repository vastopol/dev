//make a loop that prints random number of times

#include <iostream>
#include <cstdlib>
#include <ctime>


using namespace std;

int main()
{
    
    srand(1000000 * (time(NULL))); // normally just: srand(time(NULL));
    
    int p = rand() % 500;
    int i = 0;
    int c = 0;
    
    do
    {
        if(i == p)
        {
           i = 0; 
           //cout << "X"; //check resets of i
        }
        for( i = 0; i < p; i++)
        {
            cout << "i:" << i << "p:" << p;
                for(int h = 0; h < p; h++) // OUTPUT FOR P: "*"
                {
                    cout << "h:" << h <<"*";
                }
                for(int q = 0; q < p; q++) //OUTPUT FOR I: "$"
                {
                    cout << "q:"  << q << "$";
                }
            p = rand() % 500; //mod p
        }
        cout << endl;
        c++;
        i = rand() % 501; //mod i
    }while(c < 50 );
    //increase size that c has to reach to extend runtime
    
     

return 0;
}

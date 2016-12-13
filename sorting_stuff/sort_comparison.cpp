/* Bubble Sort vs. Selection Sort */

#include <algorithm>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <string>
#include <vector>

using namespace std;

//Local function declarations
void selSort(vector<int> &v);

void bubSort(vector<int> &v);

void display(const vector<int> &v);

int main()
{
    srand(time(0));
    
    vector<int> L1;
    vector<int> L2;
    
    int n = rand() % 10 + 1;
    
    //fill vector w/ 10 random nums
    for(int i = 0; i < 10; i++)
    {
        L1.push_back(n);
        n = rand() % 10 + 1;
    }
    
    L2 = L1;
    
    
    cout <<"BUBBLE_SORT TEST" << endl;
    cout << "Unsorted L1" << endl;
    display(L1);
    
    bubSort(L1);
    
    cout << "sorted L1" << endl;
    display(L1);    

    cout << endl;
    cout << "---------------------------------------------" << endl;

    cout <<"SELECTION_SORT TEST" << endl;
    cout << "Unsorted L2" << endl;
    display(L2);
    
    selSort(L2);
    
    cout << "sorted L2" << endl;
    display(L2);   
    
return 0;
}
//==============================================
//==============================================


// Local function implementations 
void selSort(vector<int> &v)
{
    cout << "start of sort" << endl << endl;
    
    for(unsigned i = 0; i < v.size(); i++)
    {
        int min = i;
        
        for(unsigned j = i + 1; j < v.size(); j++)
        {
            if( v.at(j) < v.at(min) )
            {
                min = j;
            }
        }
        
        swap( v.at(i), v.at(min) );
        cout << "swap: ";
        display(v);
    }
    
    cout << endl;
    cout << "end of sort" << endl;
    return;
}
//----------------------------------------------

void bubSort(vector<int> &v)
{
    cout << "start of sort" << endl << endl;
    
    for(unsigned i = 0; i < v.size(); i++)
    {
        for(unsigned j = i + 1; j < v.size(); j++)
        {
            if( v.at(j) < v.at(i) )
            {
                //display(v);
                swap( v.at(i), v.at(j) );
                cout << "swap: ";
                display(v);
            } 
        }
    } 
    
    cout << endl;
    cout << "end of sort" << endl;
    return;
}
//-----------------------------------------------

void display(const vector<int> &v)
{
    for(int i = 0; i < v.size(); i++)
    {
        cout << v.at(i) << ", ";
    }
    cout << endl;
}
//------------------------------------------------

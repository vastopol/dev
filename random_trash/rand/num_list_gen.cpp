// main
// generate lists of random numbers of random size

#include <iostream>
#include <ctime>
#include <cstdlib>
#include <vector>

using namespace std;

int genRandInt(int low , int high);

void fillVector( vector<int> &scores, int, int);

void display(const vector<int> &scores);

//===============================================
int main()
{   
    srand(time(0));
 
    vector<int> scores;
    
    fillVector(scores, 0, 100);
    
    display(scores);
    
return 0;   
}
//====================================================


int genRandInt(int low , int high)
{
    return rand() % (high - low + 1) + 1; 
}
//--------------------------------------------------------

void fillVector( vector<int> &scores, int low, int high)
{
    int size = genRandInt(100, 200);
    
    for(int i = 0; i < size; ++i)
    {
     scores.push_back(genRandInt(low, high));
    }
     
    return;
}
//--------------------------------------------------------

void display(const vector<int> &scores)
{
    for(unsigned int i = 0; i < scores.size(); ++i)
    {
     cout << scores.at(i) << ",";
    }
     
    cout << endl;
    return; 
}
//--------------------------------------------------------
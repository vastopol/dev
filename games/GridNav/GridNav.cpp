#include <ctime>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

#define _GRID_SIZE_ 10
char grid[_GRID_SIZE_][_GRID_SIZE_]; // 2D playing field

// LOCAL FUNCTIONS
void display(); // display grid
void clear();   // escape character sequence for clear screen
void init(pair<int, int>& A , pair<int, int>& B , pair<int, int>& cur);  // initialize sequence

int main()
{
    srand(time(NULL));
    unsigned score = 0; 
    unsigned level = 1;
    pair<int, int> A;
    pair<int, int> B;
    pair<int, int> cur;
    char input = '@';
    int randomizer = -9999;
    bool flag = false;
    
    init(A, B, cur); // initialize board for first time
    
    do
    {
        clear(); // clear previous screen
        
        flag = false;
        cout << "Level: " << level << endl;
        cout << "Score: " << score << endl;
        cout << "Index: " << '(' << cur.second << ',' << cur.first << ')' << endl << endl;;
        //pairs ended up being (y,x) for display since format is quad IV on graph
            
        display(); // print grid
        
        cout << "enter direction to move one space: w == up, s == down, a == left, d == right | q == quit" << endl;
        cout << ">>";
        cin >> input;
        
        // kill sequence
        randomizer = rand() % 25 + 1; // gen a number [1,a]; 1 = instant death; b% chance = (1/a), 1/25 = .04%
        if(randomizer == 1) 
        {
            cout << "BANG... you died" << endl;
            break;
        }
        
        // choose and direct move || quit
        switch(input)
        {            
             case 'w': cur.first = cur.first - 1; score++; break; 
            // go up one space
            
            case 's': cur.first = cur.first + 1; score++; break; 
            // go down one space
            
            case 'a': cur.second = cur.second - 1; score++; break; 
            // go left one space
            
            case 'd': cur.second = cur.second + 1; score++; break; 
            // go right one space
            
            case 'q': clear(); cout << "Quit" << endl; exit(0); // quit && exit
            
            default: cout << "Error, Try Again?" << endl; flag = true; 
        } 
        
        if(cur.first < 0 || cur.first > 9 || cur.second < 0 || cur.second > 9) 
        {
            cout  << '\n' << "You fell of the grid and died..." << endl;
            break;
        }
        else if(cur.first == B.first && cur.second == B.second)
        {
            level++;
            init(A, B, cur); // reinit board for next level
            continue;
        }
        else if(flag == false)
        {
            if(grid[cur.first][cur.second] == ' ')
            {
                grid[cur.first][cur.second] = 'x';
            }
            else
            {
                grid[cur.first][cur.second] = (grid[cur.first][cur.second])++; 
            }
        }
        else
        {
            cout << "ERROR: UNKNOWN" << endl;
            exit(1);
        }
        
    }while(input != 'q');
    
    cout << endl << "GAME OVER" << endl;
    
return 0;
}
//==========================================================
//==========================================================


void init(pair<int, int>& A , pair<int, int>& B , pair<int, int>& cur)
{
    int x = -1;
    int y = -1;
    
    //initialize grid
    for(int i = 0; i < _GRID_SIZE_; i++)
    {
        for(int j = 0; j < _GRID_SIZE_; j++)
        {
            grid[i][j] = ' ';
        }
    }
       
    //game is on 10x10 try to cast A on left and B on right 
    
    //pair A
    x = rand() % 4;
    y = rand() % 4;
    grid[x][y] = 'A';
    cur.first = x;
    cur.second = y;
    A.first = x;
    A.second = y;
    
    //pair B    
    x = rand() % 4 + 4;
    y = rand() % 4 + 4;
    grid[x][y] = 'B';
    B.first = x;
    B.second = y;

}
//---------------------------------------------------------

   
void display()
{
    cout << '#';
    for(int i = 0; i < (2 * _GRID_SIZE_) + 1; i++)
    {
        cout << '_';
    }
    cout << endl;
    for(int i = 0; i < _GRID_SIZE_; i++ )
    {
        cout << ' ' << '|';
        for(int j = 0; j < _GRID_SIZE_; j++ )
        {
            cout << grid[i][j] << '|';
        }
        cout << endl;
    }
    cout << endl;
}
//-----------------------------------------------------


void clear()
{
    cout << "\033c";
    return;
}
//------------------------------------------------------
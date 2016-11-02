#include <ctime>
#include <cstdlib>
#include <cstring>
#include <utility>
#include <iostream>

using namespace std;

#define _GRID_SIZE_ 10
char grid[_GRID_SIZE_][_GRID_SIZE_]; //2D playing field

// LOCAL FUNCTIONS
void display();
void clear();

int main()
{
    // keep up here so it wont get reset
    unsigned score = 0; 
    unsigned level = 1;
    
    terrible_coding_strategy: // i cant believe im using a goto statement
    
    srand(time(NULL));

    int x = -1;
    int y = -1;
    pair<int, int> A;
    pair<int, int> B;
    pair<int, int> cur;
    char input = '@';
    int randomizer = -9999;
    bool flag = false;
    
    // char grid[_GRID_SIZE_][_GRID_SIZE_]; 
    //initialize grid
    for(int i = 0; i <_GRID_SIZE_; i++ )
    {
        for(int j = 0; j <_GRID_SIZE_; j++ )
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
    
    do
    {
        clear(); // clear previous grids on screen
        
        flag = false;
        cout << "Level: " << level << endl;
        cout << "Score: " << score << endl;
        cout << "Index: " << '(' << cur.second << ',' << cur.first << ')' << endl << endl;;
        //pairs ended up being (y,x) for display since format is quad IV on graph
            
        display();
        
        cout << "enter direction to move one space: w == up, s == down, a == left, d == right | q == quit" << endl;
        cout << ">>";
        cin >> input;
        
        randomizer = rand() % 25 + 1; // gen a number [1,x], 1 = instant death; y% chance = (1/x)
        if(randomizer == 1) 
        {
            cout << "BANG... you died" << endl;
            break;
        }
        
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
            
            case 'q': cout << "Quit" << endl; exit(0);// quit && exit
            
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
            goto terrible_coding_strategy;
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
        
        
    }while(input != 'q');
    
    cout << endl << "GAME OVER" << endl;
    
return 0;
}
//------------------------------------------------------------------------------------

   
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

///escape character sequence for clear screen
void clear()
{
    cout << "\033c";
    return;
}
//------------------------------------------------------
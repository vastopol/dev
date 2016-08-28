#include "dumDef.h"

using namespace std;

int main()
{
   cout << "Dumshell" << endl;
   cout << "enter 'help' for command list, quit to exit" << endl;
   
   string command;
   
   do{
      cout << ">> ";
      cin >> command;
      
      if(command != "quit")
      {
         comExe(command);
      }
   
   }while(command != "quit");
    
    
return 0;
}
//cat imitation

#include <cstdlib>
#include <cstring>
#include <fstream>
#include <iostream>
#include <sstream>
#include <string>

using std::cout;
using std::cin;
using std::endl;

void cat(std::string, std::string); // cat 2 files in current directory into new 3rd file
void fuse(std::string&, std::string&); // append file2 to file1

int main(int argc, char* argv[])
{
   std::string file1;
   std::string file2;
   
   if(argc == 3)
   {   
      file1 = std::string(argv[1]);
      file2 = std::string(argv[2]);
      
      cout << file1 << endl << file2 << endl;
      
      fuse(file1,file2);
      
   }
   else if(argc > 3)
   {
      cout << "Error:: too many input parameters" << endl;
      exit(1);
   }
   else if(argc == 2)
   {
      cout << "Error:: requires 2 input parameters" << endl;
      exit(1);
   }
   else
   {   
      cout << "Fail:: Enter easy mode" << endl;
      cout << "fuse 2 files" << endl;
      cout << "enter names.extensions below" << endl;
      cout << ">> ";
      cin >> file1;
      cout << ">> ";
      cin >> file2;
      cat(file1, file2);
   }

return 0;
}
//-----------------------------------------------------------------------------

void cat(std::string s1, std::string s2)
{
   std::string outFile;
   std::string temp;
   std::ofstream ofs1;
   std::ifstream ifs1;
   std::ifstream ifs2;
   
   cout << "enter name of output file below" << endl;
   cout << ">> ";
   cin >> outFile;
   ofs1.open(outFile.c_str());
   if(!ofs1.is_open())
   {
      cout << "Error: could not open output file for write" << endl;
      exit(1);
   }
   else
   {
      ifs1.open(s1.c_str());
      if(!ifs1.is_open())
      {
         cout << "Error: could not open input file1 for read" << endl;
         exit(1);
      }
      else
      {
         while(ifs1 >> temp)
         {
            ofs1 << temp << ' ';
         }
         //ofs1 << endl;  // make gap after input
         temp = std::string();
         ifs1.close();
      }
      ofs1 << endl << "xxxxxxxxx" << endl;////////////////////////////////////////////////
      ifs2.open(s2.c_str());
      if(!ifs2.is_open())
      {
         cout << "Error: could not open input file2 for read" << endl;
         exit(1);
      }
      else
      {
         while(ifs2 >> temp)
         {
            ofs1 << temp << ' ';
         }
         //ofs1 << endl;  // make gap after input
         ifs2.close();
         temp = std::string();
      }
   }
   ofs1.close();
   cout << "success" << endl;
}
//-----------------------------------------------------------------------------------------

void fuse(std::string &s1, std::string &s2)
{
   std::string temp = std::string();
   std::fstream ofs;
   std::fstream ifs;
   
   std::stringstream ppp;
      
   ofs.open(s1.c_str());
   if(!ofs.is_open())
   {
      cout << "Error: could not open output file for write" << endl;
      exit(1);
   }
   else
   {      
      ifs.open(s2.c_str());
      if(!ifs.is_open())
      {
         cout << "Error: could not open input file2 for read" << endl;
         exit(1);
      }
      else
      {
   
         while (ofs >> temp)
         {
            ppp << temp << ' ';
         }
         ppp << endl;
         
         while(ifs >> temp)
         {
            ppp << temp << ' ';
         }
         ifs.close();
         temp = std::string();
      }
           
      while(ppp >> temp)
      {
         ofs << temp << ' ' ;
      }
   }
   ofs.close();
   cout << "success" << endl;
}
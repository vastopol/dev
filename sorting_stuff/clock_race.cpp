//VERSION 1.0
#include "simple_sort.h"

#include <cstdlib>
#include <ctime>
#include <iostream>
#include <algorithm>

using namespace std;

const int CLOCKS_PER_MS = CLOCKS_PER_SEC/1000; //clock per milliseconds

int main()
{
   srand(time(0));

   int elapsedTime = 0;
   clock_t Start = 0;
   clock_t End = 0;
   
   vector<int> v1;
   int key_large = 100; // for count && bucket
   unsigned val;
   char in = 'x';
   
   cout << "Sort Race" << endl;
   cout << "Random Vector Sorting Challenge" << endl;
   cout << "1 = bubble, 2 = select, 3 = insert, 4 = shell," << endl;
   cout << "5= merge, 6 = count, 7 = bucket" << endl;
   
   do{
      cout << endl << "Enter size of vector to sort then press return to run" << endl;
      cin >> val;
      if(!cin.good() || val < 0)
      {
         cout << "Error" << endl;
         cin.ignore('\n', 256);
         cin.clear();
      }
      
      for(unsigned i = 0; i < val; i++)
      {
         v1.push_back(rand() % 100);
      } 
      
      if(v1.empty())// because of faulty input
      {         
         cin.ignore(1); // strip faults one by one
         cin.clear();
         continue;
      }
      
      vector<int> v2= v1;
      vector<int> v3= v1;
      vector<int> v4= v1;
      vector<int> v5= v1;
      vector<int> v6= v1;
      vector<int> v7= v1;
      
      //---------------------------------------------------------------------------------------------------
      Start = clock();
      bubble_sort(v1);
      End = clock();
      elapsedTime = (End - Start)/CLOCKS_PER_MS;   
      cout << "bubble_sort took: " << elapsedTime << " milliseconds" << endl;
      //-----------------------------------------------------------------------------------------------------
      Start = clock();
      select_sort(v2);
      End = clock();
      elapsedTime = (End - Start)/CLOCKS_PER_MS;   
      cout << "select_sort took: " << elapsedTime << " milliseconds" << endl;
      //-----------------------------------------------------------------------------------------------------   
      Start = clock();
      insert_sort(v3);
      End = clock();
      elapsedTime = (End - Start)/CLOCKS_PER_MS;   
      cout << "insert_sort took: " << elapsedTime << " milliseconds" << endl;
      //-----------------------------------------------------------------------------------------------------   
      Start = clock();
      shell_sort(v4);
      End = clock();
      elapsedTime = (End - Start)/CLOCKS_PER_MS;   
      cout << "shell_sort took : " << elapsedTime << " milliseconds" << endl;
      //-----------------------------------------------------------------------------------------------------   
      Start = clock();
      merge_sort(v5);
      End = clock();
      elapsedTime = (End - Start)/CLOCKS_PER_MS;   
      cout << "merge_sort took : " << elapsedTime << " milliseconds" << endl;
      //-----------------------------------------------------------------------------------------------------   
      Start = clock();
      count_sort(v6, key_large);
      End = clock();
      elapsedTime = (End - Start)/CLOCKS_PER_MS;   
      cout << "count_sort took : " << elapsedTime << " milliseconds" << endl;
      //-----------------------------------------------------------------------------------------------------
      Start = clock();
      bucket_sort1(v7, key_large);
      End = clock();
      elapsedTime = (End - Start)/CLOCKS_PER_MS;   
      cout << "bucket_sort took: " << elapsedTime << " milliseconds" << endl;
      //-----------------------------------------------------------------------------------------------------
      
      cout << endl << "Again?   Y/N" << endl;
      cin >> in;
      in = toupper(in);
      
   }while(in != 'N');
   
   
   return 0;
}
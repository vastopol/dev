//VERSION 1.0
#include "simple_sort.h"

#include <algorithm>
#include <cmath>
#include <cstdlib>
#include <ctime>
#include <iostream>
#include <iterator>
#include <vector>

using namespace std;


void bubble_sort(vector<int> &v)
{
   for(unsigned i = 0; i < v.size(); i++)
   {
      for(unsigned j = i + 1; j < v.size(); j++)
      {
         if(v.at(i) > v.at(j))
         {
            swap(v.at(i), v.at(j));
         }
      }
   }
}
//--------------------------------------------------------------------------------------

void select_sort(vector<int> &v)
{
   for(unsigned i = 0; i < v.size(); i++)
   {
      unsigned min = i;
      for(unsigned j = i + 1; j < v.size(); j++)
      {
         if(v.at(j) < v.at(min))
         {
            min = j;  
         }
      }
      if(v.at(i) > v.at(min))
      {
         swap(v.at(i), v.at(min));
      }
   }
}
//---------------------------------------------------------------------------------------

void insert_sort(vector<int> &v)
{
   for(unsigned i = 1; i < v.size(); i++)
   {
      unsigned j = i;
      while(j > 0 && v.at(j-1) > v.at(j))
      {
         swap(v.at(j-1), v.at(j));
         j--;
      }
   }
}
//---------------------------------------------------------------------------------------

void shell_sort(vector<int> &v) // uses shell's original specifications
{
   unsigned gap = floor(v.size()/2);  
   while(gap > 0)
   {
      for(unsigned i = gap; i < v.size(); i++)
      {
         unsigned j = i;
         while( j >= gap && v.at(j-gap) > v.at(j))
         {
            swap(v.at(j-gap), v.at(j));
            j -= gap;
         }
      }
      gap = floor(gap/2);
   }
}
//---------------------------------------------------------------------------------------

void merge_sort(vector<int> &v)
{
   if(v.size() == 1)
   {
      return;
   }
   
   unsigned mp = v.size()/2; // mid point
   vector<int>::iterator ip = v.begin() + mp;
   vector<int> v1;
   vector<int> v2;
   
   v1.assign(v.begin(), ip);
   v2.assign(ip, v.end()); 
   
   merge_sort(v1);
   merge_sort(v2);
   v = merge(v1,v2);
   
}

vector<int> merge(vector<int> &v1, vector<int> &v2)
{
   vector<int> v3;
   
   while(!v1.empty() && !v2.empty())
   {
      if(v1.at(0) < v2.at(0))
      {
         v3.push_back(v1.at(0));
         v1.erase(v1.begin());
      }
      else
      {
         v3.push_back(v2.at(0));
         v2.erase(v2.begin());
      }
   }
   while(!v1.empty())
   {
      v3.push_back(v1.at(0));
      v1.erase(v1.begin());
   }
   while(!v2.empty())
   {
      v3.push_back(v2.at(0));
      v2.erase(v2.begin());
   }
   return v3;
}
//-----------------------------------------------------------------------------------------


void count_sort(vector<int> &v, int largest_val) // have to know what the largest value is 
{
   vector<int> count(largest_val);
   
   for(unsigned i = 0; i < v.size(); i++) // count appearences
   {
      count.at(v.at(i))++;
   }
   
   int x = 0;
   for(unsigned i = 0; i < count.size(); i++) // go through each index
   {
      for(int j = 0; j < count.at(i); j++) // take vals from index j times
      {
         v.at(x++) = i;
      }
   }
}
//-----------------------------------------------------------------------------------------------------------------------

//==========================================================================================================================
//==========================================================================================================================
//==========================================================================================================================

template <typename TT>
void insertion_sort1(TT start, TT end, int jump) 
{
   for(TT i = start; i != end; i++)
   {
      TT j = i;
      while(j >= start + jump && *(j - jump) > *j)
      {
         swap(*(j - jump), *j);
         j -= jump;
      }
   }
}
//-----------------------------------------------------------------------------------------------------------------------

void bucket_sort1(vector<int> &v, int vals)// only ints... situation determines num buckets
{
   vector< vector<int> > box(vals/10); // vector of empty buckets, each holds certain values from [a,b]

   for(unsigned i = 0; i < v.size(); i++) // filling buckets in their range
   {
     box.at(v.at(i)/10).push_back(v.at(i));
   }

   for(unsigned i = 0; i < box.size(); i++) // sort buckets
   {
     insertion_sort1(box.at(i).begin(), box.at(i).end());
   }

   int x = 0;
   for(unsigned i = 0; i < box.size(); i++) // go through each index
   {
      for(unsigned j = 0; j < box.at(i).size(); j++) // take vals
      {
          v.at(x++) = box.at(i).at(j);
      }
   }
}
//------------------------------------------------------------------------------------------------------------------------

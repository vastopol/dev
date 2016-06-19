//VERSION 1.0
#include <iostream>
#include <vector>
#include <iterator>
#include <cstdlib>
#include <ctime>
#include <algorithm>

using namespace std;

///////////STAND_ALONE_FUNCTIONS//////////////////////////////////////

void bubble_sort(vector<int> &v);

void select_sort(vector<int> &v);

void insert_sort(vector<int> &v);

void shell_sort(vector<int> &v); // shell's sequence to find gap = floor(len/(2^k))

void merge_sort(vector<int> &v);
vector<int> merge(vector<int> &v1, vector<int> &v2);

void count_sort(vector<int> &v, int largest_val); 

////////ALTERNATES//////////////////////////////////////////////////////////

template <typename TT>
void insertion_sort1(TT start, TT end, int jump=1);

void bucket_sort1(vector<int> &v, int vals);  // uses insertion sort

/*

have a way to compare and time sorts... using different sizes of random numbers, then in order numbers, then reverse order numbers...

add other sorts:

quick
quick3
heap
radix

*/
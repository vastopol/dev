//  musical set theory 
//  STD = C++11

#ifndef __MUS_F__
#define __MUS_F__

#include <algorithm>
#include <iostream>
#include <queue>
#include <vector>

using namespace std;

void display(vector<int> &v);

void transpose(vector<int> &v); // transpose helper

void T(vector<int> &v, unsigned n); // transpose by n semitones

void invert(vector<int> &v); // inversion helper

void I(vector<int> &v, unsigned n); // invert n times

void R(vector<int> &v); // retrograde = reversal

#endif //__MUS_F__
#ifndef __DEF_H__
#define __DEF_H__

#include <iostream>
#include <string>
#include <vector>

using namespace std;

void clearScreen();

void printIntro();

bool IsStringVowel(char c);

bool IsStringConsonant(char c);

bool IsStringSymbol(char c);

void StringAnalyze(const string& sentence);

void StringUpper(string& sentence);

void StringLower(string& sentence);

void StringReverse(string& sentence);

void vectorDisplay(const vector<string>& paragraph);


#endif ///end of  __DEF_H__

#ifndef __FUNCTS_EVAL__
#define __FUNCTS_EVAL__

// #include <algorithm>
// #include <utility>
// #include <cmath>
// #include <ctime>
// #include <climits>
// #include <cstring>
// #include <cstdlib>
// #include <iomanip>
// #include <fstream>
// #include <sstream>
// #include <vector>
// #include <list>
#include <iostream>
#include <string>
#include <stack> 
#include <queue>
#include <iterator>

using namespace std; // maybe scope resolve later...

bool eval(std::string s);       // evaluation engine

bool isBalanced(std::string s); // refers to brackets, braces, parentheses...

bool isEqn(std::queue<std::string> Q);


#endif // __FUNCTS_EVAL__

/*
logic operations : &, |, !
math operations:  +, -, *, /, %,
evaluations     : =, != <, >, <=, >=
*/
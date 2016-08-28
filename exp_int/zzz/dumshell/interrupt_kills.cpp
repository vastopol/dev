#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <signal.h>

using namespace std;

volatile sig_atomic_t flag = 0;
void func(int sig){ // can be called asynchronously
    cout << endl << "Hehehehe you think I can be killed so easily??" << endl;
    flag++; // set flag
}

int main() {
    signal(SIGINT, func);
    
    int x = 0;
    while (flag < 3) { }
    cout << endl << endl << "Gosh. Fine then." << endl;
    
}
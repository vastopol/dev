#include <iostream>
#include "arithmeticExpression.h"

using namespace std;

int main()
{
    string expr1 = "";
    
    do{
        
    cout << ">> ";
    getline(cin, expr1);
    
    arithmeticExpression ex1(expr1);
    ex1.buildTree();
    
    cout << "expression 1: "<< expr1 << endl;
    cout << "infix: "; ex1.infix(); cout << endl;
    cout << "prefix: "; ex1.prefix(); cout << endl;
    cout << "postfix: "; ex1.postfix(); cout << endl;
    cout << endl;
    
    }while(1);

    return 0;
}
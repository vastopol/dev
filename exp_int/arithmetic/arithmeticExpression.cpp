// implementation
#include "arithmeticExpression.h"

#include <iostream>
#include <cstdlib>
#include <cstring>
#include <string>
#include <stack>
#include <sstream>
#include <fstream>

using namespace std;

/*
struct TreeNode
    char data;
    char key;
    TreeNode* left;
    TreeNode* right;
    TreeNode(char data, char key):data(data),key(key),left(0),right(0){}

class arithmeticExpression
  private:
    string infixExpression;
    TreeNode* root;

*/


//PRIVATE HELPER FUNCTIONS
int arithmeticExpression::priority(char op)
{
    int priority = 0;
    if(op == '('){
        priority =  3;
    }
    else if(op == '*' || op == '/'){
        priority = 2;
    }
    else if(op == '+' || op == '-'){
        priority = 1;
    }
    return priority;
}
//-----------------------------------------------------------

string arithmeticExpression::infix_to_postfix()
{
    stack<char> s;
    ostringstream oss;
    char c;
    for(unsigned i = 0; i< infixExpression.size();++i){
        c = infixExpression.at(i);
        if(c == ' '){
            continue;
        }
        if(c == '+' || c == '-' || c == '*' || c == '/' || c == '(' || c == ')'){ //c is an operator
            if( c == '('){
                s.push(c);
            }
            else if(c == ')'){
                while(s.top() != '('){
                    oss << s.top();
                    s.pop();
                }
                s.pop();
            }
            else{
                while(!s.empty() && priority(c) <= priority(s.top())){
                    if(s.top() == '('){
                        break;
                    }
                    oss << s.top();
                    s.pop();
                }
                s.push(c);
            }
        }
        else{ //c is an operand
            oss << c;
        }
    }
    while(!s.empty()){
        oss << s.top();
        s.pop();
    }
    return oss.str();
}
//-------------------------------------------------------------------------

 /* Helper function that outputs the infix notation of the arithmetic expression tree
    by performing the inorder traversal of the tree.
    An opening and closing parenthesis must be added at the 
    beginning and ending of each expression. */
 void arithmeticExpression::infix(TreeNode *n)
 {
     if(n == 0)
     {
         return;
     }
    //if ((n->left != 0 && n != root->left) || n == root)
    if(n->data == '+' || n->data == '-' || n->data == '/' || n->data == '*')
    {
        //if(n->left->left == 0 && n->left->right == 0)
        {
            cout << '(';
        }
    }
    infix(n->left);

    cout << n->data;

    infix(n->right);
    if(n->data == '+' || n->data == '-' || n->data == '/' || n->data == '*')
    //if((n->right != 0 && n != root->right) || n == root)
    {
        //if(n->right->left == 0 && n->right->right == 0)
        {
            cout << ')';
        }
    }
 }

 /* Helper function that outputs the prefix notation of the arithmetic expression tree
    by performing the preorder traversal of the tree. */
 void arithmeticExpression::prefix(TreeNode *n)
 {
     if(n == 0)
     {
         return;
     }
     
    cout << n->data;
    prefix(n->left);
    prefix(n->right);
 }

 /* Helper function that outputs the postfix notation of the arithmetic expression tree
    by performing the postorder traversal of the tree. */
 void arithmeticExpression::postfix(TreeNode *n)
 {
     if(n == 0)
     {
         return;
     }
     
    postfix(n->left);
    postfix(n->right);
    cout << n->data;
 }
 
 int arithmeticExpression::height(TreeNode *n)
 {
     if (n == 0) return 0;
     int x = height(n->left);
     int y = height(n->right);
     return ((x > y) ? x : y) + 1;
 }
 
 /* Helper function for generating the dotty file. This is a recursive function. */
 void arithmeticExpression::visualizeTree(ofstream &out, TreeNode *n)
 {
     if (n == 0)
     {
         return;
     }
     out << '\n';
     out << n->key << " [color = lightblue, style = filled, label=\"key=" << n->data;
     out << ", h=" << height(n)-1 << "\"];";
     if (n->left != 0)
     {
        out << "\n" << n->key << " -> " << (n->left)->key << ";";
        visualizeTree(out, n->left);
     }
     if (n->right != 0)
     {
        out << "\n" << n->key << " -> " << (n->right)->key << ";";
        visualizeTree(out, n->right);
     }
 }

//=========================================================================================
//=========================================================================================
//PUBLIC MEMBER FUNCTIONS

 /* Initializes an empty tree and sets the infixExpression
 to the value of parameter passed in. */
 arithmeticExpression::arithmeticExpression(const string &str)
    : infixExpression(str), root(0)
 {}

 /* Implementation of destrucor is optional.
    The destructor should deallocate all the nodes in the tree. */
 //arithmeticExpression::~arithmeticExpression();

 /* Converts the infixExpression to its equivalent postfix string
    and then generates the tree and assigns the root node to the 
    root data field. The key for the first node is 'a', 'b' for the second node and so on. */
 void arithmeticExpression::buildTree()
 {
    stack<TreeNode*> cstack;
    string temp = this->infix_to_postfix();
    char key = 'a';
    
    if(temp.size() == 0) return;
    
    
    for(unsigned i = 0; i < temp.size(); i++)
    {
        // 3=(, 2= */, 1 = +-, 0 =char
        
        if(priority(temp.at(i)) > 0)
        {
            TreeNode* tp = new TreeNode( temp.at(i) , key ); // makes a new node
            
            tp->right = cstack.top();
            cstack.pop();
            tp->left = cstack.top();
            cstack.pop();
            
            cstack.push(tp);
        }
        else
        {
            TreeNode* tp = new TreeNode( temp.at(i) , key ); // makes a new node
            cstack.push(tp);
        }
        key++;
    }
    root = cstack.top();
    return;
 }
 
 void arithmeticExpression::visualizeTree(const string &outputFilename)
 {
    ofstream outFS;
    outFS.open(outputFilename.c_str());
    if(!outFS.is_open()){
        cout<<"Error opening "<< outputFilename<<endl;
        return;
    }
    outFS<<"digraph G {"<<endl;
    visualizeTree(outFS,root);
    outFS<<"}";
    outFS.close();
    string jpgFilename = outputFilename.substr(0,outputFilename.size()-4)+".jpg";
    string command = "dot -Tjpg " + outputFilename + " -o " + jpgFilename;
    system(command.c_str());
}


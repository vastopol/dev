#include <iostream>
#include <string>
#include <cstring>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "def.h"

using namespace std;

///LOCAL FUNCTIONS
int Prompt();   // initial opton select 
unsigned select(); // vector index selector
void chooseMod(string&);
void cinCheck();


int main()
{
    clearScreen();
    printIntro();

    vector<string> paragraph;
    string sentence = "";

    do
    {    
        switch( Prompt() ) // initial decision function/prompt
        {
            case 0: // Write to vector
                {
                    cout << "Enter a sentence: " << endl;
                    cin.ignore();
                    getline(cin, sentence);
                    cout << endl << "You entered:" << endl << sentence << endl;
                    paragraph.push_back(sentence);
                    break;
                }
            case 1:
                {
                    cout << "Insert" << endl;
                    unsigned a = select();
                    
                    cout << "Enter a sentence: " << endl;
                    cin.ignore();
                    getline(cin, sentence);
                    cout << endl << "You entered:" << endl << sentence << endl;
                    
                    if(a < 0)
                    {
                        cout << "ERROR: Size" << endl;
                    }
                    else if( a >= paragraph.size() )
                    {
                        paragraph.push_back(sentence);
                    }
                    else
                    {
                        paragraph.insert( (paragraph.begin() + a) , sentence );
                    }
                    break;
                }
            case 2: // Erase from vector
                {
                    cout << "Remove" << endl;
                    unsigned a = select();
                    if( a < 0 || a >= paragraph.size() )
                    {
                        cout << "ERROR: Size" << endl;
                    }
                    else
                    {
                        paragraph.erase(paragraph.begin() + a);
                    }
                    break;
                }
            case 3: // Modify string
                {
                    cout << "Modify" << endl;
                    unsigned a = select();
                    if( a < 0 || a >= paragraph.size() )
                    {
                        cout << "ERROR: Size" << endl;
                    }
                    else
                    {
                        chooseMod( paragraph.at(a) );
                        cout << endl;
                    }
                    break;
                }
            case 4: // Analyze string
                {
                    cout << "Analyze" << endl;
                    unsigned a = 0;
                    a = select();
                    if(  a < 0 || a >= paragraph.size() )
                    {
                        cout << "ERROR: Size" << endl;
                    }
                    else
                    {
                        cout << endl;
                        StringAnalyze( paragraph.at(a) );
                        cout << endl;
                    }
                    break;
                }
            case 5:  // Print vector
                {
                    cout << "Vector contains: " << endl;
                    vectorDisplay(paragraph);
                    break;
                }
            case 6: clearScreen(); break;
            case 7: // Print to file && exit
                {    
                    ofstream OutFile;
                    string oFileName;
                    
                    cout << "Enter output file name:" << endl;
                    cin.ignore();
                    getline(cin, oFileName);
                    
                    OutFile.open(oFileName.c_str());
                    if(!OutFile)
                    {
                        cout << "ERROR: could not open file: " << oFileName << endl;
                        exit(1);
                    }
                    else
                    {
                        for(unsigned i = 0; i < paragraph.size(); i++)
                        {
                            OutFile << paragraph.at(i) << endl;
                        }
                    }
                    
                    cout << endl << "Successful Print" << endl << "END OF PROGRAM" << endl;
                    return 0;
                }
            default: cout << "ERROR: Invalid Choice" << endl; break;
        
        }// End switch

    }while(1);

return 0;
}
//======================================================================
//=====================================================================

int Prompt()
{
    int d;
    cout << endl << "Choose Option:" << endl;
    cout << "0 = Write, 1 = Insert from, 2 = Erase, 3 = Modify" << endl;
    cout << "4 = Analyze, 5 = View, 6 = Clear Screen, 7 = Save && Exit" << endl;
    cout << ">> ";
    cin >> d;
    cinCheck();
    return d;
}
//---------------------------------------------------------------------------------------

unsigned select()
{
    unsigned i = 0;
    cout << "Select vector index" << endl << ">> ";
    cin >> i;
    cinCheck();
    return i;
}
//---------------------------------------------------------------------------------------

void chooseMod(string& sentence)
{
    int i = 0;     /// str mod

    cout << "Enter 1 toUpper, enter 2 toLower, enter 3 to reverse" << endl;
    cout << ">> ";
    cin >> i;
    
    cinCheck();
    if(i > 3 || i < 1)
    { cout << "ERROR INVALID ENTRY: str mod" << endl; return;}

    cout << endl;
    cout << "Original sentence: " << sentence << endl;
    cout << "Changed sentence : ";

    if(i == 1) ///UPPER
    {
        StringUpper(sentence);
    }
    else if(i == 2) ///LOWER
    {
        StringLower(sentence);
    }
    else if(i == 3) ///REVERSE
    {
        StringReverse(sentence);
    }
    
    cout << sentence << endl;
    return;
}
//---------------------------------------------------------------------------------------

///input check function
void cinCheck()
{
    if(!cin.good()) /// Fix if CIN BROKEN
    {
        cin.clear(); /// fix buffer flags
        cin.ignore(1000, '\n'); /// ignore anyhting in the buffer
    }
    return;
}
///-----------------------------------------------------------------

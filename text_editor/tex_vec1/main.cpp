#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "def.h"

using namespace std;

///LOCAL FUNCTIONS
int Prompt();
void chooseMod(string&);
void saveFunc(string&, std::vector<string>&);

int main()
{
    clearScreen();
    printIntro();

    vector<string> paragraph;
    string sentence;
    int decision1 = 0;     /// primary choice

    do{
        cout << "Enter a sentence: " << endl;
        getline(cin, sentence);
        cout << endl << "You entered: " << sentence << endl;

        decision1 = Prompt();

        if(decision1 == 1) // ANALYZE
        {
            cout << endl;
            StringAnalyze(sentence);
            cout << endl;
            
            saveFunc(sentence, paragraph); // save last entered sentence after
        }
        else if (decision1 == 2) // MODIFY
        {
            chooseMod(sentence);
            cout << endl;

            saveFunc(sentence, paragraph); // save last entered sentence after
        }
        else if (decision1 == 3)
        {
            sentence.clear();

            if(sentence.empty())
            {
                cout << "Sentence cleared " << endl;
            }
            else
            {
                cout << "ERROR: clearing sentence" << endl;
                exit(1);
            }
        }
        else if(decision1 == 4) // SAVE
        {
            paragraph.push_back(sentence);
            cout << "Saved to vector" << endl;
        }
        else if(decision1 == 5) // DISPLAY
        {
            saveFunc(sentence, paragraph); // save last entered sentence before
            cout << endl;
            
            cout << "Vector contains: " << endl;
            vectorDisplay(paragraph);
        }
        else if(decision1 == 6) // fix to erase from vector
        {        
            saveFunc(sentence, paragraph); // save last entered sentence before
            cout << endl;
            
            int numDel = -99;
            
            vectorDisplay(paragraph);
            cout << "Enter sentence # to remove" << endl;
            cout << ">>";
            cin >> numDel;
            
            //convert to index
            numDel--;
            if(numDel >= paragraph.size() || numDel < 0)
            {
                cout << "ERROR: Invalid Index " << endl;
            }
            else
            {
                cout << "deleting" << endl;
                paragraph.erase(paragraph.begin() + numDel);
            }
            
        }
        else if(decision1 == 7)
        {
            saveFunc(sentence, paragraph); // save last entered sentence before
            cout << endl;
            
            ofstream OutFile;
            string oFileName;
            
            cout << "Enter output file name:" << endl;
            cin >> oFileName;
            
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
                
                cout << endl << "out file successful" << endl;
            }
            
            break;
        }
        else
        {
            cout << "ERROR INVALID ENTRY: decision1" << endl;
        }
        cout << endl;

        cinCheck();
        
    }while(1);

    cout << endl;
    cout << "END OF PROGRAM" << endl;

return 0;
}
//======================================================================
//=====================================================================

int Prompt()
{
    int d1 = 0;
    cout << endl;
    cout << "Enter 1 to analyze str, enter 2 to Modify str, enter 3 to clear str," << endl;
    cout << "Enter 4 to save str to vector, enter 5 to display vector, enter 6 to erase from vector," << endl;
    cout << "Enter 7 output vector to a file then END" << endl;
    cout << ">> ";
    cin >> d1;
    cinCheck();
    return d1;
}
//---------------------------------------------------------------------------------------

void chooseMod(string& sentence)
{
    int decision2 = 0;     /// str mod

    cout << "Enter 1 toUpper, enter 2 toLower, enter 3 to reverse" << endl;
    cout << ">> ";
    cin >> decision2;
    
    cinCheck();
    if(decision2 > 3 || decision2 < 1){ cout << "ERROR INVALID ENTRY: decision2" << endl; return;}

    cout << endl;
    cout << "Original sentence: " << sentence << endl;
    cout << "Changed sentence : ";

    if(decision2 == 1) ///UPPER
    {
        StringUpper(sentence);
    }
    else if(decision2 == 2) ///LOWER
    {
        StringLower(sentence);
    }
    else if(decision2 == 3) ///REVERSE
    {
        StringReverse(sentence);
    }
    
    cout << sentence << endl;
    return;
}
//---------------------------------------------------------------------------------------


void saveFunc(string& sentence, std::vector<string>& paragraph)
{
    char d3 = 'x';
    
    cout << "Save sentence? y/n" << endl;
    cin >> d3;
    cinCheck();
    if(d3 == 'y') 
    {
        paragraph.push_back(sentence);
        cout << "Saved to vector" << endl;
    }
    return;
}
//---------------------------------------------------------------------------------------

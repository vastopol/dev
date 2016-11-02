//VERSION 1.0
#include <iostream>
#include <string>
#include <vector>
#include <fstream>
#include <cstdlib>
#include <cstring>

#include "def.h"

using namespace std;

///LOCAL FUNCTIONS
void chooseMod(string&);

int Prompt();

void saveFunc(string&, std::vector<string>&);


int main()
{
    clearScreen();

    printIntro();

    vector<string> paragraph;
    string sentence;
    int decision1 = 0;     /// primary choice
    //char decision4 = 'x';  /// re-enter str: inside decision1 check chain, branch 3

    //char endLoop = 'n';

    do{
        cout << "Enter a sentence: " << endl;
        getline(cin, sentence);
        cout << endl << "You entered: " << sentence << endl;

        decision1 = Prompt();

        if(decision1 == 1)
        {
            cout << endl;
            StringAnalyze(sentence);
            cout << endl;
            
            saveFunc(sentence, paragraph);
        }
        else if (decision1 == 2) // mod str
        {
            chooseMod(sentence);
            cout << endl;

            saveFunc(sentence, paragraph);
        }
        else if (decision1 == 3)
        {
            sentence.clear();

            if(sentence.empty())
            {
                cout << "Sentence cleared " << endl;

                // ///offer re-enter && save
                // cout << endl << "Re-enter string? y/n" << endl;
                // cin >> decision4;
                // cinCheck();
                // if(decision4 == 'y')
                // {
                //     ///allows re-entry of another sentence
                //     cin.clear();
                //     cin.ignore(1000, '\n');

                //     cout << "Enter a new sentence: " << endl;
                //     getline(cin, sentence);
                //     cout << endl;

                //     saveFunc(sentence, paragraph);
                // }
            }
            else
            {
                cout << "ERROR: clearing sentence" << endl;
            }

        }
        else if(decision1 == 4)
        {
            paragraph.push_back(sentence);
            cout << "Saved to vector" << endl;
            //cout << "Vector now contains: " << endl;
            //vectorDisplay(paragraph);
        }
        else if(decision1 == 5)
        {
            saveFunc(sentence, paragraph);
            cout << endl;
            
            cout << "Vector contains: " << endl;
            vectorDisplay(paragraph);
        }
        else if(decision1 == 6)
        {
            cout << "fix to erase from vector" <<  endl;
            
            saveFunc(sentence, paragraph);
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
            saveFunc(sentence, paragraph);
            cout << endl;
            
            ofstream OutFile;
            string oFileName;
            
            cout << "Enter output file name:" << endl;
            cin >> oFileName;
            
            OutFile.open(oFileName.c_str());
            
            if(!OutFile)
            {
                cout << "ERROR: could not open file: " << oFileName << endl;
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

        // /// this part continues while loop if need quit option
        // cout << endl;
        // cout << "QUIT??  y/n" << endl;
        // cin >> endLoop;
        // cinCheck();
        // cout << endl;

        // ///also allows re-entry of more sentences if endLoop != 'y'
        cin.clear();
        cin.ignore(1000, '\n');

    //}while( endLoop != 'y');
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
    cout << "Choose what you want to do to the sentence" << endl;
    cout << "Enter 1 to analyze str, enter 2 to Modify str, enter 3 to clear str," << endl;
    cout << "Enter 4 to save str to vector, enter 5 to display vector, enter 6 to erase from vector," << endl;
    cout << "Enter 7 output vector to a file then END" << endl;
    cout << ">>";
    cin >> d1;
    cinCheck();
    return d1;
}


void chooseMod(string& sentence)
{
    int decision2 = 0;     /// str mod

    cout << "Enter 1 toUpper, enter 2 toLower, enter 3 to reverse" << endl;
    cout << ">>";
    cin >> decision2;
    cinCheck();

    if(decision2 == 1) ///UPPER
    {
        cout << endl;
        cout << "Original sentence: " << sentence << endl;
        cout << "Changed sentence : ";
        StringUpper(sentence);
        cout << sentence << endl;
    }
    else if(decision2 == 2) ///LOWER
    {
        cout << endl;
        cout << "Original sentence: " << sentence << endl;
        cout << "Changed sentence : ";
        StringLower(sentence);
        cout << sentence << endl;
    }
    else if(decision2 == 3) ///REVERSE
    {
        cout << endl;
        cout << "Original sentence: " << sentence << endl;
        cout << "Changed sentence : ";
        StringReverse(sentence);
        cout << sentence << endl;
    }
    else
    {
        cout << "ERROR INVALID ENTRY: decision2" << endl;
    }
    return;
}


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
       // cout << "Vector now contains: " << endl;
       // vectorDisplay(paragraph);
    }
    return;
}
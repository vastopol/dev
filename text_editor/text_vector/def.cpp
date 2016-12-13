#include "def.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

///input check function
void cinCheck()
{
    if(!cin.good()) /// Fix if CIN BROKEN
    {
        cin.clear(); /// fix buffer flags ??
        cin.ignore(1000, '\n'); /// ignore anyhting in the buffer??
    }
    return;
}
///============================================================

///escape character sequence for clear screen
void clearScreen()
{
    cout << "\033c";
    return;
}
///=========================================================


void printIntro()
{
    cout << "TEXT VECTOR PROGRAM" << endl;
    cout << "Enter strings, analyze/modify, store strings in a vector." << endl;
    cout << "Vector of strings can be called and displayed, Or output to a file " << endl;
    cout << endl;
    return;
}
///===========================================================


/// checks string for vowels
void IsStringVowel(string sentence)
{
  int k = sentence.size();
  bool outs = false;

    cout << "String isVowel : ";
    for(int i = 0; i < k; i++)
    {
        string s1 = sentence;
        char temp = 'x';
        outs = isalpha(s1.at(i));

        if(outs == true)
        {
            ///work more
            s1.at(i) = toupper(s1.at(i));
            temp = s1.at(i);

            if(temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U' )
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        }
        else
        {
            cout << "0";
        } 
    }
    cout << endl;

    return;
}
///==============================================================================


///checks string for consonants
void IsStringConsonant(string sentence)
{
    int k = sentence.size();
    bool outs = false;

    cout << "Str isConsonant: ";
    for(int i = 0; i < k; i++)
    {
      string s1 = sentence;
      char temp = 'x';
      outs = isalpha(s1.at(i));

       if(outs == true)
       {
            ///work more
            s1.at(i) = toupper(s1.at(i));
            temp = s1.at(i);

            if(temp != 'A' && temp != 'E' && temp != 'I' && temp != 'O' && temp != 'U')
            {
                cout << "1";
            }
            else
            {
                cout << "0";
            }
        } 
        else
        {
            cout << "0";
        }
    } 
    cout << endl;

    return;
}
///==================================================================


/// loop for symbols && punctuation
void IsStringSymbol(string sentence)
{
    int k = sentence.size();

    cout << "String isSymbol: ";

    for(int i = 0; i < k; i++)
    {
        string s1 = sentence;
        char temp = 'x';

        temp = s1.at(i);

        if(static_cast<int>(temp) < 33) /// ascii code up to 31 are null, 32 = space
            {
                cout << "0";
            }
        else if(static_cast<int>(temp) > 47 && static_cast<int>(temp) < 58) /// numbers 0-9
            {
                cout << "0";
            }
        else if(static_cast<int>(temp) > 64 && static_cast<int>(temp) < 91) /// uppercase letters
            {
                cout << "0";
            }
        else if(static_cast<int>(temp) > 96 && static_cast<int>(temp) < 123) ///lowercase letters
            {
                cout << "0";
            }
        else if(static_cast<int>(temp) == 127) // DEL
            {
                cout << "0";
            }
        else
            {
                cout << "1"; // 33-47, 58-64, 91-96, 123-126
            }

    } /// end of for loop
    cout << endl;

    return;
}
///==================================================================

///function to analyze entered string
///calls above functions inside where noted*
void StringAnalyze(const string &sentence)
{
    /// function variables
    int k = sentence.size();
    bool outs = false;

    cout << "String length: " << k << " units" << endl;
    cout << "You entered    : " << sentence << endl;

    ///isAlpha loop for characters
    cout << "String isAlpha : ";
    for(int i = 0; i < k; i++)
    {
      outs = isalpha(sentence.at(i));
      cout << outs;
    }
    cout << endl;

    ///isVowel loop for characters*
    IsStringVowel(sentence);

    ///isConsonant loop for characters*
    IsStringConsonant(sentence);

    ///isUpper loop for characters
    cout << "String isUpper : ";
    for(int i = 0; i < k; i++)
    {
      outs = isupper(sentence.at(i));
      cout << outs;
    }
    cout << endl;

    ///isLower loop for characters
    cout << "String isLower : ";
    for(int i = 0; i < k; i++)
    {
      outs = islower(sentence.at(i));
      cout << outs;
    }
    cout << endl;

    ///isDigit loop for characters
    cout << "String isDigit : ";
    for(int i = 0; i < k; i++)
    {
      outs = isdigit(sentence.at(i));
      cout << outs;
    }
    cout << endl;

    ///isSpace loop for characters
    cout << "String isSpace : ";
    for(int i = 0; i < k; i++)
    {
      outs = isspace(sentence.at(i));
      cout << outs;
    }
    cout << endl;

    ///isSymbol loop for characters*
    IsStringSymbol(sentence);

    return;
}
///============================================================================================


///function that changes & then outputs string  to UPPER
void StringUpper(string &sentence)
{
    for(unsigned int cnt = 0 ; cnt < sentence.size() ; cnt++)
    {
        sentence.at(cnt) = toupper(sentence.at(cnt));
    }
    return;
}
///==============================================================================================


///function that changes & then outputs string  to LOWER
void StringLower(string &sentence)
{
    for(unsigned int cnt = 0 ; cnt < sentence.size() ; cnt++)
    {
        sentence.at(cnt) = tolower(sentence.at(cnt));
    }
    return;
}
///==================================================================================================

///function to reverse string
void StringReverse(string& s)
{
    if(s.size() <= 1)
    {
        return;
    }
    
    for(unsigned i = 0; i < s.size()/2; i++)
    {   
        swap( s.at(i), s.at(s.size() -(1 + i) ) );
    }
    return;
}
///===================================================================================================

///string vector display
void vectorDisplay(const vector<string> &paragraph)
{
    if(paragraph.size() == 0)
    {
        cout << "Empty" << endl;
        return;
    }

    for(unsigned int i = 0; i < paragraph.size(); i++)
    {
        cout << i + 1 << ".) "  << paragraph.at(i) << endl;
    }
    return;
}
///=================================================================================================

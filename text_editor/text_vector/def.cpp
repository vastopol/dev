#include "def.h"

#include <iostream>
#include <string>
#include <vector>

using namespace std;

///escape character sequence for clear screen
void clearScreen()
{
    cout << "\033c";
    return;
}
///=========================================================


void printIntro()
{
    cout << "**********************************************************************" << endl;
    cout << "* TEXT VECTOR PROGRAM                                                *" << endl;
    cout << "* Enter strings, analyze/modify, store strings in a vector.          *" << endl;
    cout << "* Vector of strings can be called and displayed, Or output to a file *" << endl;
    cout << "**********************************************************************" << endl;
    return;
}
///===========================================================


/// checks string for vowels
bool IsStringVowel(char c)
{
    if(isalpha(c))
    {
        ///work more
        char temp = toupper(c);

        if(temp == 'A' || temp == 'E' || temp == 'I' || temp == 'O' || temp == 'U' )
        {
            return true;
        }
        else
        {
            return false;
        }
    }
    else
    {
        return false;
    } 


    return false;
}
///==============================================================================


/// checks string for consonants
bool IsStringConsonant(char c)
{
   if(isalpha(c))
   {
        ///work more
        char temp = toupper(c);

        if(temp != 'A' && temp != 'E' && temp != 'I' && temp != 'O' && temp != 'U')
        {
            return true;
        }
        else
        {
            return false;
        }
    } 
    else
    {
        return false;
    }

    return false;
}
///==================================================================


/// test for symbols && punctuation
bool IsStringSymbol(char c)
{
    if(static_cast<int>(c) < 33) /// ascii code up to 31 are control characters, 32 = space
        {
            return false;
        }
    else if(static_cast<int>(c) > 47 && static_cast<int>(c) < 58) /// numbers 0-9
        {
            return false;
        }
    else if(static_cast<int>(c) > 64 && static_cast<int>(c) < 91) /// uppercase letters
        {
            return false;
        }
    else if(static_cast<int>(c) > 96 && static_cast<int>(c) < 123) ///lowercase letters
        {
            return false;
        }
    else if(static_cast<int>(c) == 127) // DEL
        {
            return false;
        }
    else
        {
            return true; // 33-47, 58-64, 91-96, 123-126
        }

    return false;
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

    ///isVowel loop for characters*********************************************************************************
    cout << "String isVowel : ";
    for(int i = 0; i < k; i++)
    {
      outs = IsStringVowel(sentence.at(i));
      cout << outs;
    }
    cout << endl;

    ///isConsonant loop for characters*********************************************************************************
    cout << "Str isConsonant: ";
    for(int i = 0; i < k; i++)
    {
      outs = IsStringConsonant(sentence.at(i));
      cout << outs;
    }
    cout << endl;

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

    ///isSymbol loop for characters*********************************************************************************
    cout << "String isSymbol: ";
    for(int i = 0; i < k; i++)
    {
      outs = IsStringSymbol(sentence.at(i));
      cout << outs;
    }
    cout << endl;

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
        cout << i << ".) "  << paragraph.at(i) << endl;
    }
    return;
}
///=================================================================================================

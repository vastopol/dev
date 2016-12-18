//lists all posible permutations of a string

#include <iostream>
#include <string>

using namespace std;

//  variable to count permutations.
int count = 1;

// local function
void PermuteString(string head, string tail);

//========================================================
int main() 
{
   const string PROMPT_STRING = "Enter a string to permute (use ctrl-C to exit): ";
   string input = "";
   
   do
   {
      count = 1; // reinit
      input = ""; // reinit
      
      // Get input and permute the string
      cout << PROMPT_STRING << endl;
      cin >> input;
      PermuteString("", input);
   } 
   while (input.length() > 0);
   
   cout << "Done." << endl;

   return 0;
}
//========================================================


void PermuteString(string head, string tail) 
{
   char current = '?';
   string newPermute = "";
   int len = 0;
   int i = 0;

   len = tail.length();
   if (len <= 1)
   {
      // Output the permutation count on each line too
      cout << count << ") ";
      count++;
      cout << head + tail << endl;
   }
   else 
   { 
      // loop to output permutations
       for (i = 0; i < len; ++i) 
      {
         current = tail[i];           // Get next leading character
         newPermute = tail.substr(0, i) + tail.substr(i + 1);
                                       // Get the rest of the tail
         PermuteString(head + current, newPermute);
      } 
   }

   return;
} 
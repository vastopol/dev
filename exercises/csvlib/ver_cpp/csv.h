// Comma separated value class

#include <string>
#include <vector>
#include <iostream>

using namespace std;

class Csv // read and parse csv
{
	public:
		Csv(istream& fin = cin, string sep = ",")
			: fin(fin), fieldsep(sep) {}

		int getline(string&);
		string getfield(int n);
		int getnfield() const { return nfield; }

	private:
		istream& fin;			// input file pointer
		string line;			// input line
		vector<string> field;	// field of strings
		int nfield;				// number of fields
		string fieldsep;		// separator characters

		int split();
		int endofline(char);
		int advplain(const string& line, string& fld, int);
		int advquoted(const string& line, string& fld, int);
};

/*

default parameters for the constructor are defined so a default Csv object will
read from the standard input stream and use the normal field separator,
either can be replaced with explicit values

*/
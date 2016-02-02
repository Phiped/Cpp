#include <iostream>
#include <fstream>
#include "coding.h"
#include <string>

using namespace std;

ifstream infile;
ofstream outfile;

int main (int, char* argv[] ) {
	char ch;
	infile.open(argv[1]);
	string of = argv[1];
	of.erase(of.size()-4,of.size());
	of.append(".enc");

	outfile.open(of);

	if (infile.is_open())
	{
		while (infile.get(ch))
	    {
	    	outfile << Coding::encode(static_cast<unsigned char>(ch));
	    }
	infile.close();
	outfile.close();
	}
	else cout << "Unable to open file"; 
	return 0;
}
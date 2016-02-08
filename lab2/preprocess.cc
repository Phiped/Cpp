#include <iostream>
#include <fstream>
#include <string>
#include <istream>

using namespace std;

ifstream infile;
ofstream outfile;

string process (string line){
	string trigram;

	line.append(" "+line.size());

	for (int i = 0; i < line.size()-2; ++i)
	{
		trigram = line.substr(i,i+2);
		line.append(" "+trigram);			
	}
	return line;
}

int main (int, char* argv[]) {
	string line;
	infile.open(argv[1]);
	outfile.open("words.txt");
	
	if (infile.is_open())
	{
		while (getline(infile,line))
    	{
    		outfile << process(line) <<endl;
    	}
	infile.close();
	outfile.close();
	}
	else cout << "Unable to open file"; 
	return 0;
}

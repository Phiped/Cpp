#include <iostream>
#include <fstream>
#include <string>

using namespace std;


string process(string line){
  string newLine = line;
  int size = line.size();

  newLine.append(" " + size-2);

  for (int i = 0; i < size-2; ++i)
  {
    newLine.append(" " + line.substr(i,3));
  }
	return newLine;
}

int main (int, char* argv[]) {
  string line;
  ifstream infile ("text.txt");
  ofstream outfile("words.txt");
  string processedLine;


  if (infile.is_open() && outfile.is_open())
  {
    while ( getline (infile,line) )
    {
    	processedLine = process(line);
    	outfile << processedLine << '\n';
    }
    infile.close();
    outfile.close();
  }

  else cout << "Unable to open file"; 

  return 0;
}
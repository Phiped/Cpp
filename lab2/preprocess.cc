#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <algorithm>
#include <sstream>

using namespace std;

string process(string line){
  stringstream output;
  int size = line.size()-2;
  if (size < 0)
  {
    size = 0;
  }
  vector<string> trigrams;

  output << line;
  output << " " << size;

  for (int i = 0; i < size; ++i)
  {
    trigrams.push_back(line.substr(i,3));
  }

  sort(trigrams.begin(),trigrams.end());

  for (int i = 0; i < trigrams.size(); ++i)
  {
    output << " " << trigrams[i];
  }

	return output.str();
}

int main (int, char* argv[]) {
  string line;
  ifstream infile ("/usr/share/dict/words");
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
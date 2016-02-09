#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using namespace std;


Dictionary::Dictionary() {
	ifstream infile ("/usr/share/dict/words");
	string line;

	if (infile.is_open())
	{
		while (getline (infile, line))
		{
			set.insert(line);
			words[line.size()].insert(line);
		}
		infile.close();
	}


}

bool Dictionary::contains(const string& word) const {
	unordered_set<string>::const_iterator found = set.find(word);
	if (found == set.end())
	{
		return false;
	}
	return true;
}

vector<string> Dictionary::get_suggestions(const string& word) const {
	vector<string> suggestions;
	return suggestions;
}

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <algorithm>
#include "word.h"
#include "dictionary.h"

using namespace std;


Dictionary::Dictionary() {
	ifstream infile ("text.txt");
	string line;
	unordered_set<string> set;

	if (infile.is_open())
	{
		while (getline (infile, line))
		{
			set.insert(line);
		}
		infile.close();
	}


}

bool Dictionary::contains(const string& word) const {
	const_iterator found = set.find(word);
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

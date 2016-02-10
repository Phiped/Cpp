#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>

using namespace std;


Dictionary::Dictionary() {
	ifstream infile ("words.txt");
	vector<string> trigrams;
	string line;
	string word;
	int pos;
	int size;


	if (infile.is_open())
	{
		while (getline (infile, line))
		{
			pos = line.find(" ");
			word = line.substr(0,pos);
			set.insert(word);
			line.erase(0,pos+1);
			pos = line.find(" ");
			line.erase(0,pos+1);
			size = line.size();
//funkar hit





//			Word* w = new Word(word,trigrams);
//			words[word.size()].push_back(*w);
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

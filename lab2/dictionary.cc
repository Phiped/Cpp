#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <sstream>
#include "word.h"
#include "dictionary.h"
#include <unordered_set>
#include <algorithm>

using namespace std;


Dictionary::Dictionary() {
	ifstream infile ("words.txt");
	vector<string> trigrams;
	string line;
	string word;
	int pos;
	string trigram;


	if (infile.is_open())
	{
		while (getline (infile, line))
		{
			trigrams.clear();

			pos = line.find(" ");
			word = line.substr(0,pos);
			set.insert(word);
			line.erase(0,pos+1);
			pos = line.find(" ");
			line.erase(0,pos+1);

			stringstream s(line);
			while(getline (s,trigram,' ')){
				trigrams.push_back(trigram);
			}

				Word* w = new Word(word,trigrams);
				words[word.size()].push_back(*w);
		}
		infile.close();
	}
}

bool Dictionary::contains(const string& word) const {
	if (set.count(word) > 0)
	{
		return true;
	} 
	return false;
}

vector<string> Dictionary::get_suggestions(const string& word) {
	vector<string> suggestions;
	add_trigram_suggestions(suggestions, word);
	rank_suggestions(suggestions, word);
	trim_suggestions(suggestions);
	return suggestions;
}

void Dictionary::add_trigram_suggestions(vector<string>& suggestions, const string& w){
 	int size = w.size()-2;
 	vector<string> trigrams;
  	if (size < 0){
	   	size = 0;
	}
	  	
	for (int i = 0; i < size; ++i)
	{
		trigrams.push_back(w.substr(i,3));
	}

	sort(trigrams.begin(),trigrams.end());		
	for(int k = 0; k != 2; ++k)
	{
		if(w.size()+k > 0)
		{
			for (unsigned int i = 0; i < words[w.size()+k].size(); ++i)
			{
				if (words[w.size()+k].at(i).get_matches(trigrams) > (trigrams.size()/2))
				{
					suggestions.push_back(words[w.size()+k].at(i).get_word());
				}
			}
		}
	}

}

void Dictionary::rank_suggestions(vector<string>& suggestions, const string& word){
//	int[26][26] distance;
 

// 	vector<pair<int, string>> element;
// 	element.push_back(make_pair(dist,word));
// 	sort.element();
}

void Dictionary::trim_suggestions(vector<string>& suggestions){
	if (suggestions.size()>5)
	{
		suggestions.resize(5);
	}
}
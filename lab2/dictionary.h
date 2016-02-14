#ifndef DICTIONARY_H
#define DICTIONARY_H

#include <string>
#include <vector>
#include <unordered_set>
#include "word.h"

#define maxsize 25

class Dictionary {
public:
	Dictionary();
	bool contains(const std::string& word) const;
	std::vector<std::string> get_suggestions(const std::string& word);
private:
	std::unordered_set<std::string> set;
	std::vector<Word> words[maxsize];
	void add_trigram_suggestions(std::vector<std::string>& v, const std::string& w);
	void rank_suggestions(std::vector<std::string>& v, const std::string&);
	void trim_suggestions(std::vector<std::string>& v);
};

#endif
#include <string>
#include <vector>
#include "word.h"

using namespace std;

Word::Word(const string& w, const vector<string>& t) {
	word = w;
	trigrams = t;
}

string Word::get_word() const {
	return word;
}

unsigned int Word::get_matches(const vector<string>& t) const {
	int matches = 0;
	unsigned int index = 0;
	unsigned int i = 0;

	while(i < t.size() && index < trigrams.size())
	{
		if (t[i] == trigrams[index])
		{
			++index;
			++matches;
			++i;
		}
		else if (t[i] > trigrams[index]){
			++index;

		}else if (t[i] < trigrams[index]) {
			++i;
		}
	}
	return matches;
}

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
	int index = 0;

	for (unsigned int i = 0; i < t.size(); ++i)
	{
		if (t[i] == trigrams[index])
		{
			++index;
			++matches;
		}
		else if (t[i] > trigrams[index]){
			++i;

		}else if (t[i] < trigrams[index]) {

			++index;

		}
	}
	return matches;
}

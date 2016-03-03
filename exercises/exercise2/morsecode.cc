#include "morsecode.h"
#include <sstream>
#include <fstream>
#include <iostream>
#include <algorithm>

using namespace std;

MorseCode::MorseCode() {
	ifstream infile("morse.def");
	char ch;
	string code;

	while(infile>>ch>>code){
		table[ch-'a']=code;
	}
}

string MorseCode::encode(const string& text) const {
	string result;
	for (char ch: text)
	{
		if(ch <= 'z' && ch >= 'a'){
			result += table[ch-'a']+ " ";
		}
	}

	return result;
}

string MorseCode::decode(const string& code) const {
	stringstream ss;
	ss << code;
	string morse;
	string result;

	while(ss>>morse){
		int i = 0;
		while(i != 26 && table[i] != morse){
			++i;
		}
		result += (i != 26) ? static_cast<char>(i + 'a') : '?';
	}
	return result;
}

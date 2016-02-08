#include "morsecode.h"

#include <fstream>
#include <sstream>

using namespace std;

MorseCode::MorseCode() {
	ifstream in("morse.def");
	string s;
	while(in.getline(s,10)){
		std::cout << s.erase(0,2) << endl;
	}
}

string MorseCode::encode(const string& text) const {
	ifstream is(text);
	char c;
	string s;x

	while(is.get(c)){
		/*s.insert();*/
	}
	is.close();

	return s;
}

string MorseCode::decode(const string& code) const {
	ifstream is(code);
	char c;
	string s;

	while(is.get(c)){
		/*s.insert();*/
	}
	is.close();

	return s;
}

#include "editor.h"
#include <string>
#include <iostream>

using namespace std;

string::size_type Editor::find_left_par(string::size_type pos) const {
	char lpar;
	char rpar = text[pos];
	int count = 0;
	switch(rpar){
		case ']': lpar = '[';
		break;

		case ')': lpar = '(';
		break;

		case '}' : lpar = '{';
		break;

		default  : return string::npos;
	}

	string::size_type i = pos-1;
	bool found = false;

	while(i != string::npos && !found){
		if(text[i] == lpar && count == 0){
			found = true;
		}else if (text[i] == lpar && count != 0){
			--count;
		}else if (text[i] == rpar){
			++count;
		}
		--i;
	}
	
	return i;
}

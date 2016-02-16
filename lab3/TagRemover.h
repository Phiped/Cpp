#include <iostream>
#include <regex>
#include <string>
#ifndef TAGREMOVER_H
#define TAGREMOVER_H

class TagRemover{
public:
	TagRemover(istream in);
	void print(ostream cout);
private:
	std::string s;
	std::istream in;
};


#endif
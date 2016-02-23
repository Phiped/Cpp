#ifndef TAGREMOVER_H
#define TAGREMOVER_H
#include <iostream>
#include <string>
#include <fstream>
#include <regex>

class TagRemover{
public:
	TagRemover(std::ifstream& cin);
	void print(std::ostream& out) const;
private:
	std::string s;
	std::string result;
	std::regex e;
};


#endif
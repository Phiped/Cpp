#include <iostream>
#include <regex>
#include <string>

Class TagRemover{
public:
	TagRemover(istream in);
	void print(ostream out) const;
private:
	std::regex e (string reg);
	std::istream in;
}
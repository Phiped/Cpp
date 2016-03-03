#ifndef TEXT_H
#define TEXT_H

#include <string>
#include <vector>
#include "textiterator.h"

class Text {
	friend class textiterator;
public:
	using iterator = textIterator;
	void addLine(const std::string& line) { lines.push_back(line); }
	iterator begin() { return iterator(lines,0); }
	iterator end() { return iterator(lines,lines.size()); }

private:
	std::vector<std::string> lines;
};

#endif

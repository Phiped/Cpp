#ifndef ITERATOR_H
#define	ITERATOR_H

class textIterator: public std::iterator<std::forward_iterator_tag, bool>{
public:
	textIterator(std::vector<std::string>& l, size_t n): pos(0), pos_line(n), lines(l) {}

	bool operator == (const textIterator& it) const { return (it.pos == pos && pos_line == it.pos_line); }
	bool operator != (const textIterator& it) const {return !(it == *this);}
	
	char& operator* () { return (lines.at(pos_line)).at(pos); }

	// textIterator& operator= (const char c)  { 
	// 	(lines.at(pos_line)).at(pos) = c;
	// 	return *this;
	// }

	textIterator& operator++ (){
		++pos;
		if ((lines.at(pos_line)).size() == pos)
		{
			pos = 0;
			++pos_line;
		}
		return *this;
	}

private:
	unsigned int pos;
	unsigned int pos_line;
	std::vector<std::string> lines;
};

#endif

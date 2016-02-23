#include <iostream>

template<class T>

string toString(T a)
{
	istringstream is;

	is<<a;

	return is.str();

};
#include <string>
#include <sstream>
#include <stdexcept>
#include "date.h"


template<typename T>
std::string toString(T a){
	std::stringstream is;
	is<<a;
	return is.str();
}

template<class T>
T string_cast(std::string s){
	T a;
	try{
		std::stringstream sstream(s);
		sstream >> a;
	} catch (std::invalid_argument& e){
		std::cout << "Error: " << e.what() << std::endl;
	}

	return a;
}


int main(){
	double d = 1.234;
	Date today;
	std::string sd = toString(d);
	std::string st = toString(today);
	std::cout <<"output:"<< sd << std::endl << st <<std::endl;
	int i = 0;
	Date date;

	try {
		i = string_cast<int>("123");
		d = string_cast<double>("12.34");
		date = string_cast<Date>("2015-01-10");
	} catch (std::invalid_argument& e) {
		std::cout << "Error: " << e.what() << std::endl;
	}

	std::cout<< "output: "<< i << std::endl << d << std::endl << date << std::endl;
}
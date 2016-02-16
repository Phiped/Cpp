#include <ctime>  // time and localtime
#include "date.h"
#include <iostream>

int Date::daysPerMonth[] = {31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

Date::Date() {
	time_t timer = time(0); // time in seconds since 1970-01-01
	tm* locTime = localtime(&timer); // broken-down time
	year = 1900 + locTime->tm_year;
	month = 1 + locTime->tm_mon;
	day = locTime->tm_mday;
}

Date::Date(int y, int m, int d): year(y), month(m), day(d) {}

int Date::getYear() const {
	return year;
}

int Date::getMonth() const {
	return month;
}

int Date::getDay() const {
	return day;
}

void Date::next() {
	++day;
	if (day > daysPerMonth[month-1]) {
		day = 1;
		++month;
		if (month > 12) {
			month = 1;
			++year;
		}
	}
}

std::istream& operator>>(std::istream& is, Date& d) {
	string s;
	is >> s;
	year = s.substr(0,4);
	month = s.substr(5,7);
	day = s.substr(9,10);
	return is;
}

std::ostream& operator<<(std::ostream& os, const Date& d) {
	os << d.getYear << '-';
	if (d.getMonth < 10)
	{
		os<<0<<d.getMonth<< '-';
	}else{
		os<< d.getMonth << '-';
	}

	if (d.getDay < 10)
	{
		os<<0<<d.getDay;
	}else{
		os<< d.getDay;
	}

	return os;
}



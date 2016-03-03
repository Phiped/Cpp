#ifndef RATIONAL_H
#define RATIONAL_H

#include <iostream>

class Rational {
	friend std::ostream& operator<< (std::ostream& o, const Rational& r);	
	friend Rational operator+ (const Rational& r1,const Rational& r2);
public:
	Rational() : numerator(0), denominator(1){}
	Rational(int num): numerator(num), denominator(1){}
	Rational(int num, int den) {
		numerator = num / gcd(num,den);
		denominator = den / gcd(num,den);

	}
	Rational& operator+= (const Rational& r);

private:
	int numerator;
	int denominator;
	int gcd(int a, int b) {
    	return b == 0 ? a : gcd(b, a % b);
	}
};


#endif
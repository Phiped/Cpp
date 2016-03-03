#include "rational.h"

using namespace std;


ostream& operator<< (ostream& o, const Rational& r){
	if(r.denominator == 1){
		o << r.numerator;
	}else{
		o << r.numerator << '/' << r.denominator;
	}
	return o;
}

Rational& Rational::operator+= (const Rational& r){
	numerator = numerator*r.denominator + r.numerator*denominator;
	denominator *= r.denominator;
	int gc = gcd(numerator,denominator);
	numerator = numerator / gc;
	denominator = denominator / gc	;

	return *this;
}

Rational operator+ (const Rational& r1, const Rational& r2){
	Rational temp =r1;
	return temp += r2;
}

#ifndef Decimal_h
#define Decimal_h

#include "Integer.h"
#include <iostream>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;

#include <string>
using std::string;

class Decimal : public Integer{
public:

	Decimal();
	Decimal operator=(Decimal&);
	Decimal operator=(Integer&);
	Decimal operator=(string&);

	void CALC_assign(string);
	Decimal operator!();
	Decimal operator^(const Decimal&);

	Decimal operator+();
	Decimal operator-();

	Decimal operator*(const Decimal&);
	Decimal operator/(const Decimal&);

	Decimal operator+(const Decimal&);
	Decimal operator-(const Decimal&);

	friend istream& operator>> (istream&, Decimal&);
	friend ostream& operator<< (ostream&, Decimal&);
private:
	Integer denum, num;
};

istream& operator>> (istream&, Decimal&);
ostream& operator<< (ostream&, Decimal&);

#endif

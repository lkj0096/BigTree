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
	Integer operator=(Integer&);
	Integer operator=(Decimal&);
	Integer operator=(string&);

	void CALC_assign(string);
	numberobj* operator!();
	numberobj* operator^(const numberobj&);

	numberobj* operator+();
	numberobj* operator-();

	numberobj* operator*(const numberobj&);
	numberobj* operator/(const numberobj&);

	numberobj* operator+(const numberobj&);
	numberobj* operator-(const numberobj&);


	string output();
	void input(string);
	friend istream& operator>> (istream&, Decimal&);
	friend ostream& operator<< (ostream&, Decimal&);
private:
	int m_den_digit;
	vector<char> m_den;	//  denumerator
};

istream& operator>> (istream&, Decimal&);
ostream& operator<< (ostream&, Decimal&);

#endif

#ifndef Integer_h
#define Integer_h

#include "numberobj.h"
#include "Decimal.h"
#include <iostream>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;

#include <string>
using std::string;

class Integer : public numberobj {
public:

	Integer();
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
	friend istream& operator>> (istream&, Integer&);
	friend ostream& operator<< (ostream&, Integer&);

private:
	int m_num_digit; // digit
	bool m_posti; // postive == 1
	vector<char> m_num; //
};

istream& operator>> (istream&, Integer&);
ostream& operator<< (ostream&, Integer&);

#endif

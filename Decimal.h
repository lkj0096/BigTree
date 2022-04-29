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
	Decimal(const Decimal&);
	Decimal(const Integer);
	Decimal(const string);
	Decimal operator=(Decimal);
	Decimal operator=(Integer);
	Decimal operator=(string);
	Decimal(const Integer, const Integer);
	void CALC_assign(string);

	Decimal operator!();
	Decimal operator^(const Decimal);
	Decimal operator^(const Integer);
	friend Decimal operator^( const Integer, const Decimal);

	Decimal operator+();
	Decimal operator-();

	Decimal operator*(const Decimal);
	Decimal operator*(const Integer);
	friend Decimal operator*( const Integer, const Decimal);
	Decimal operator/(const Decimal);
	Decimal operator/(const Integer);
	friend Decimal operator/( const Integer, const Decimal);

	Decimal operator+(const Decimal);
	Decimal operator+(const Integer);
	friend Decimal operator+( const Integer, const Decimal);
	Decimal operator-(const Decimal);
	Decimal operator-(const Integer);
	friend Decimal operator-( const Integer, const Decimal);

	//friend istream& operator>> (istream&, Decimal&);
	//friend ostream& operator<< (ostream&, Decimal);
	
	void cout_nnnn() {
		std::cout << "\n---------------------------------\n";
		std::cout << "  num : " << (m_num.m_posti == 1 ? "" : "-") << m_num.m_val << std::endl;
		std::cout << "denum : " << (m_denum.m_posti == 1 ? "" : "-") << m_denum.m_val << std::endl;
		std::cout << "\n---------------------------------\n";
	}
	void output();
	Integer m_denum, m_num;
	
};

//istream& operator>> (istream&, Decimal&);
//ostream& operator<< (ostream&, Decimal);

Decimal operator^( const Integer, const Decimal);
Decimal operator*( const Integer, const Decimal);
Decimal operator/( const Integer, const Decimal);
Decimal operator+( const Integer, const Decimal);
Decimal operator-( const Integer, const Decimal);
#endif


#ifdef DEBUG
#define DEBUG
#endif // !DEBUG

#ifndef Integer_h
#define Integer_h

//#include "Calculator.h"
#include "numberobj.h"
#include <iostream>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;

#include <string>
using std::string;

class Integer : public numberobj {
public:
	string m_name;
	Integer();
	Integer(string);
	Integer(const char*);
	Integer(const Integer&);


	Integer operator=(const Integer);
	Integer operator=(string);
	Integer operator=(const char*);

	void CALC_assign(string);

	Integer operator!();
	Integer operator^(const Integer);

	Integer operator+();
	Integer operator-();

	Integer operator*(const Integer);
	Integer operator/(const Integer);

	Integer operator+(const Integer);
	Integer operator-(const Integer);


	bool isInteger(){return 1;};
	bool operator>(Integer);
	bool operator<(Integer);
	bool operator==(Integer);
	void input(string);
  void operator++();
	string output();

	bool m_posti; 		// postive == 1

	string  m_val; //
};

istream& operator>> (istream&, Integer&);
ostream& operator<< (ostream&, Integer);

#endif

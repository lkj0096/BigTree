//
//  numberobj.hpp
//  pro1
//
//  Created by <author> on 21/04/2022.
//
//
// #pragma once
#ifndef numberobj_h
#define numberobj_h

#include <iostream>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;

#include <string>
using std::string;

class numberobj{
public:
	// ~numberobj();

	// numberobj(numberobj& t_new);
	// numberobj& operator=(const numberobj&);

	virtual void CALC_assign(string) = 0;

	virtual numberobj* operator!() = 0;
	virtual numberobj* operator^(const numberobj&) = 0;

	virtual numberobj* operator+() = 0;
	virtual numberobj* operator-() = 0;

	virtual numberobj* operator*(const numberobj&) = 0;
	virtual numberobj* operator/(const numberobj&) = 0;

	virtual numberobj* operator+(const numberobj&) = 0;
	virtual numberobj* operator-(const numberobj&) = 0;


	virtual string output() = 0;
	virtual void input(string) = 0;
	friend istream& operator>> (istream&, const numberobj*&);
	friend ostream& operator<< (ostream&, const numberobj*&);
private:

	string name;
};

istream& operator>> (istream&, numberobj*&);
ostream& operator<< (ostream&, numberobj*&);
#endif /* numberobj_hpp */

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
	virtual bool isInteger();
	virtual string output();
	virtual void input(string);
};
ostream& operator<<(ostream& os, numberobj* ptr);
istream& operator>>(istream& is, numberobj* ptr);

#endif /* numberobj_hpp */

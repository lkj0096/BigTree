#include "numberobj.h"
#include <iostream>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;

#include <string>
using std::string;

istream& operator>> (istream& is, numberobj*& t_num){
	string str;
	is >> str;
	t_num->input(str);
	return is;
}

ostream& operator<< (ostream& os, numberobj*& t_num){
	os << t_num->output();
	return os;
}

#include "numberobj.h"

ostream& operator<<(ostream& os, numberobj* ptr){
	string out = ptr->output();
	out = out.length() == 0 ? "0" : out;
	os << out;
	return os;
}

istream& operator>>(istream& is, numberobj* ptr){
	string str;
	std::getline(is, str);
	ptr->input(str);
	return is;
}

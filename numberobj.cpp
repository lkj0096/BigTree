#include "numberobj.h"

ostream& operator<<(ostream& os, numberobj* ptr){
	os << ptr->output();
	return os;
}

istream& operator>>(istream& is, numberobj* ptr){
	string str;
	std::getline(is, str);
	ptr->input(str);
	return is;
}

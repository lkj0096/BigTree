#include "Integer.h"
#include <iostream>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;

#include <string>
using std::string;


Integer::Integer(){
	m_name = "_DEFAULT_CON";
	m_posti = 1;
	m_digit = 0;

}

Integer::Integer(const string& t_str){
	m_name = "_CON_STR";
	m_posti = (t_str[0] != '-');
}

Integer::Integer(const Integer& t_Int){
	m_name = "_CON_INT";
	m_posti = 1;
	m_digit = 0;

}

Integer Integer::operator=(const Integer& t_Int){
	return Integer("");
}

Integer Integer::operator=(const string& t_str){

}

void Integer::CALC_assign(string){

}

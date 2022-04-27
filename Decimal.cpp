#include "Decimal.h"
#include <iostream>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;

#include <string>
using std::string;

Decimal::Decimal() : Integer{} {
	m_name = "_DEC_DEFAULT_CON";
	m_num = Integer();
	m_num.CALC_assign("0");
	m_denum = Integer();
	m_denum.CALC_assign("1");
}
Decimal::Decimal(const Decimal& t_Dec) : Integer{} {
	m_num = t_Dec.m_num;
	m_denum = t_Dec.m_denum;
	m_name = "_DEC_CON_DEC";
}

Decimal::Decimal(const Integer t_Int) : Integer{} {
	m_num = Integer(t_Int);
	m_denum = Integer();
	m_denum.CALC_assign("1");
	m_name = "_DEC_CON_INT";

}
Decimal::Decimal(const string t_str) : Integer{} {
	m_num = Integer();
	m_num.CALC_assign("0");
	m_denum = Integer();
	m_denum.CALC_assign("1");
	m_name = "_DEC_CON_STR";
	// calc XXX(*this, t_str);

}
Decimal Decimal::operator=(Decimal t_Dec){
	Decimal newInt(t_Dec);
	newInt.m_name = "_DEC_COPY_DEC";
	return newInt;
}
Decimal Decimal::operator=(Integer t_Int){
	Decimal newInt(t_Int);
	newInt.m_name = "_DEC_COPY_INT";
	return newInt;
}
Decimal Decimal::operator=(string t_str){
	Decimal newDec;
	newDec.m_name = "_DEC_COPY_STR";
#ifdef DEBUG
	// calc XXX(newDec, t_str);
#else 
	

#endif // DEBUG

	return newDec;
}

void Decimal::CALC_assign(string t_str){
	string nu, de;
	
	//de = ;
	nu = t_str;
	m_num.CALC_assign(nu);
	m_denum.CALC_assign(de);
}

Decimal Decimal::operator!(){
	throw "!!!! Can't use Factorial Decimal !!!!";
	return *this;
}

Decimal Decimal::operator^(const Decimal){

}
Decimal Decimal::operator^(const Integer){

}
Decimal operator^( const Integer, const Decimal){

}

Decimal Decimal::operator+(){

}
Decimal Decimal::operator-(){

}

Decimal Decimal::operator*(const Decimal){

}
Decimal Decimal::operator*(const Integer){

}
Decimal operator*( const Integer, const Decimal){

}
Decimal Decimal::operator/(const Decimal){

}
Decimal Decimal::operator/(const Integer){

}
Decimal operator/( const Integer, const Decimal){

}

Decimal Decimal::operator+(const Decimal){

}
Decimal Decimal::operator+(const Integer){

}
Decimal operator+( const Integer, const Decimal){

}
Decimal Decimal::operator-(const Decimal){

}
Decimal Decimal::operator-(const Integer){

}
Decimal operator-( const Integer, const Decimal){

}

#include "Decimal.h"
#include <iostream>
using std::ostream;
using std::istream;
using namespace std;
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

Decimal::Decimal(const Integer t_num, const Integer t_denum) : Integer{} {
	m_num = Integer(t_num);
	m_denum = Integer(t_denum);
	m_name = "_DEC_CON_INT_INT";
}

Decimal::Decimal(const Integer t_Int) : Integer{} {
	m_num = Integer(t_Int);
	m_denum = Integer();
	m_denum.CALC_assign("1");
	m_name = "_DEC_CON_INT";

}

Decimal::Decimal(const string t_str) : Integer{} {
	m_num = Integer();
	m_num.CALC_assign("1");
	m_denum = Integer();
	m_denum.CALC_assign("1");
	m_name = "_DEC_CON_STR";
	// calc XXX(*this, t_str);
	this->CALC_assign(t_str);
}

Decimal Decimal::operator=(Decimal t_Dec) {
	Decimal newInt(t_Dec);
	newInt.m_name = "_DEC_COPY_DEC";
	
	return newInt;
}
Decimal Decimal::operator=(Integer t_Int) {
	Decimal newInt(t_Int);
	newInt.m_name = "_DEC_COPY_INT";
	return newInt;
}
Decimal Decimal::operator=(string t_str) {
	Decimal newDec;
	newDec.m_name = "_DEC_COPY_STR";
#ifdef DEBUG
	// calc XXX(newDec, t_str);
#else 


#endif // DEBUG

	return newDec;
}

void Decimal::CALC_assign(string t_str) {
	int cnt;

	if (t_str.find('.') != string::npos) {
		cnt = t_str.find('.');
		t_str.erase(t_str.begin() + cnt);
	}
	else {
		cnt = t_str.length() + 1;
	}
	//de = "1" + string(t_str.length() - cnt - 1,'0');

	//if (t_str[0] == '-') {
	//	t_str.erase(t_str.begin());
	//}

	m_num = Integer(t_str);
	m_denum.CALC_assign(string("1" + string(t_str.length() - cnt, '0')));
}

Decimal Decimal::operator!() {
#ifdef Calc_h
	throw "!!!! Can't use Factorial Decimal !!!!";

#else
	std::cout << "!!!! Can't use Factorial Decimal !!!!" << std::endl;
#endif // DEBUG  
	return *this;
}

istream& operator>> (istream& is, Decimal& t_Dec) {
	string str;
	is >> str;
#ifdef Calc_h
	calc(t_Dec, str);
#else

#endif // Calc_h
	return is;
}

ostream& operator<< (ostream& os, Decimal t_Dec) {
	//os << t_Dec.m_num.m_posti << "\t" << t_Dec.m_denum.m_posti << endl;
	os << ((t_Dec.m_num.m_posti ^ t_Dec.m_denum.m_posti) ? "-" : "");
	
	Integer Rv(t_Dec.m_num.m_val + string(200, '0'));
	
	Rv = Rv / t_Dec.m_denum;
	
	string opt = Rv.m_val.substr(0, 100);
	
	opt.insert(opt.end() - 100, '.');
	//os << opt.length() << "-----\n";
	os << (opt.length() == 101 ? "0" : "");
	os << opt;
	return os;
}
//---------------------------------------------

//bool bigger(Decimal a, Decimal b) { //a>b
//	Integer aM = a.m_denum, bM = b.m_denum;
//	a.m_denum = aM * bM;
//	b.m_denum = aM * bM;
//}
void swap(Integer& a, Integer& b) {
	Integer c = b;
	b = a;
	a = c;
}


Decimal Decimal::operator^(const Decimal ip){
	return *this;
}
Decimal Decimal::operator^(const Integer ip){
	Integer v = ip;
	Decimal b = (*this);
	Decimal ans = (Integer("1"), Integer("1"));
	while (v.m_val.size()) {
		ans = ans * b;
	}
	return ans;
}
Decimal operator^(const Integer a, const Decimal b){
	return b;
}

Decimal Decimal::operator+(){
	return (*this);
}
Decimal Decimal::operator-(){
	m_denum.m_posti = !m_denum.m_posti;
	return (*this);
}

Decimal Decimal::operator*(const Decimal ip){
	Decimal ans;
	ans.m_num = m_num * ip.m_num;
	ans.m_denum = m_denum * ip.m_denum;
	return ans;
}
Decimal Decimal::operator*(const Integer ip){
	Decimal ans;
	ans = (*this);
	ans.m_num = ans.m_num * ip;
	return ans;
}
Decimal operator*( const Integer a, const Decimal b){
	Decimal ans = b;
	ans.m_num = ans.m_num * a;
	return ans;
}
Decimal Decimal::operator/(const Decimal ip){
	Decimal v = ip;
	swap(v.m_denum, v.m_num);
	Decimal ans = (*this) * v;
	return ans;
}
Decimal Decimal::operator/(const Integer ip){
	Decimal ans = *(this);
	ans.m_denum = ans.m_denum * ip;
	return ans;
}
Decimal operator/( const Integer a, const Decimal b){
	Decimal v = b;
	swap(v.m_num, v.m_denum);
	v = v.m_num* a;
	return v;
}

Decimal Decimal::operator+(const Decimal ip){
	Decimal a = (*this), b = ip;
	//a.cout_nnnn(); b.cout_nnnn();
	a.m_num = a.m_num * b.m_denum + b.m_num * a.m_denum;
	//a.cout_nnnn();
	a.m_denum = a.m_denum * b.m_denum;
	return a;
}
Decimal Decimal::operator+(const Integer ip){
	Decimal a = *(this), b(ip, Integer("1"));
	return a + b;
}
Decimal operator+( const Integer a, const Decimal b){
	Decimal v(a, Integer("1"));
	return v + b;
}
Decimal Decimal::operator-(const Decimal ip){
	Decimal a = (*this), b = ip;
	if (a.m_posti && b.m_posti) {
		b.m_num.m_posti = !b.m_num.m_posti;
	}
	else if (a.m_posti && b.m_posti == 0) {
	}
	else if (a.m_posti == 0 && b.m_posti == 0) {
		a.m_num.m_posti = !a.m_num.m_posti;
	}
	else {
		b.m_num.m_posti = !b.m_num.m_posti;
	}
	return a + b;
}
Decimal Decimal::operator-(const Integer ip){
	Decimal b(ip, Integer("1")), a = *this;
	b.m_num.m_posti = !b.m_num.m_posti;
	return a + b;
	
}
Decimal operator-( const Integer a, const Decimal b){
	Decimal p(a, Integer("1"));
	Decimal v = b;
	v.m_num.m_posti = !v.m_num.m_posti;
	return p + v;
}

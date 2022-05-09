#include "Decimal.h"
#include "Calculator.h"
#include <iostream>
#include <regex>
using std::ostream;
using std::istream;

#include <vector>
using std::vector;
using namespace std;
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
	m_name = "_DEC_CON_DEC";
	m_num = t_Dec.m_num;
	m_denum = t_Dec.m_denum;
}

Decimal::Decimal(const Integer t_num, const Integer t_denum) : Integer{} {
	m_name = "_DEC_CON_INT_INT";
	m_num = t_num;
	m_denum = t_denum;
	m_num.m_posti = !(m_denum.m_posti ^ m_num.m_posti);
	m_denum.m_posti = 1;
}

Decimal::Decimal(const Integer t_Int) : Integer{} {
	m_name = "_DEC_CON_INT";
	m_num = t_Int;
	m_denum = Integer();
	m_denum.CALC_assign("1");
}

Decimal::Decimal(string t_str) : Integer{} {
	m_name = "_DEC_CON_STR";

	m_num = Integer();
	m_num.CALC_assign("1");
	m_denum = Integer();
	m_denum.CALC_assign("1");

	this->CALC_assign(t_str);
}

Decimal::Decimal(const char* t_str) : Integer{} {
	m_name = "_DEC_CON_STR";

	m_num = Integer();
	m_num.CALC_assign("1");
	m_denum = Integer();
	m_denum.CALC_assign("1");
	try {
		NumberConstruct(this, string(t_str));
	}
	catch (const char* s) {
		throw s;
	}
}

Decimal Decimal::operator=(Decimal t_Dec) {
	m_name = "_DEC_ASS_DEC";
	m_num = t_Dec.m_num;
	m_denum = t_Dec.m_denum;
	return *this;
}
Decimal Decimal::operator=(Integer t_Int) {
	m_name = "_DEC_ASS_INT";
	m_num = t_Int;
	m_denum = Integer();
	m_denum.CALC_assign("1");
	return *this;
}
Decimal Decimal::operator=(string t_str) {
	m_name = "_DEC_ASS_STR";

	try {
		NumberConstruct(this, t_str);
	}
	catch (const char* s) {
		throw s;
	}
	return *this;
}

Decimal Decimal::operator=(const char* t_str) {
	m_name = "_DEC_ASS_STR";

	try {
		NumberConstruct(this, string(t_str));
	}
	catch (const char* s) {
		throw s;
	}
	return *this;
}

void Decimal::CALC_assign(string t_str) {
	//t_str = regex_replace(t_str, regex("^0*"), "");
	//0.0 -> .0
	int cnt;
	m_name = "_DEC_CALC_ASSIGN";
	if (t_str.find('.') != string::npos) {
		cnt = t_str.find('.');
		t_str.erase(t_str.begin() + cnt);
	}
	else {
		cnt = t_str.length();
	}

	m_num.CALC_assign(t_str);
	m_denum.CALC_assign(string("1" + string(t_str.length() - cnt, '0')));
}

istream& operator>> (istream& is, Decimal& t_Dec) {
	string str;
	is >> str;
	try {
		NumberConstruct(&t_Dec, str);
	}
	catch (const char* s) {
		throw s;
	}

	return is;
}

ostream& operator<< (ostream& os, Decimal t_Dec) {
	os << ((t_Dec.m_num.m_posti ^ t_Dec.m_denum.m_posti) ? "-" : "");

	Integer Rv(t_Dec.m_num.m_val + string(100, '0'));

	Rv = Rv / t_Dec.m_denum;

	string opt = Rv.m_val;

	if (opt.length() < 100) {
		opt = string(100 - opt.length(), '0') + opt;
	}

	opt.insert(opt.end() - 100, '.');

	os << (opt.length() == 101 ? "0" : "") << opt;

	return os;
}

void Decimal::input(string str) {
	try {
		NumberConstruct(this, str);
	}
	catch (const char* s) {
		throw s;
	}
}

string Decimal::output() {

	Integer Rv(m_num.m_val + string(100, '0'));

	Rv = Rv / m_denum;

	string opt = Rv.m_val;



	if (opt.length() < 100) {
		opt = string(100 - opt.length(), '0') + opt;
	}

	opt.insert(opt.end() - 100, '.');

	opt = (opt.length() == 101 ? "0" : "") + opt;

	opt = ((m_num.m_posti ^ m_denum.m_posti) ? "-" : "") + opt;

	return opt;
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


Decimal Decimal::operator!() {
#ifdef Calculator_hpp
	Integer a(m_num / m_denum * m_denum);
	if (a == m_num) {
		m_num = !(m_num / m_denum) * m_denum;
	}
	else {
		throw "!!!! Cannot Factorial Decimal !!!!";
	}
#else
	std::cout << "!!!! Cannot Factorial Decimal !!!!" << std::endl;
#endif // DEBUG  
	return *this;
}

Decimal sqrt(Decimal v) {
	string ans = "";
	string ip = v.output();
	for (int t = 0; t < 300; ++t) { ip.push_back('0'); }
	int fpI = find(ip.begin(), ip.end(), '.') - ip.begin();
	if (fpI != ip.size()) { ip.erase(ip.begin() + fpI); }
	int R, K = 110;

	Integer t, curr, mem, mix;
	//cout << fpI << endl;
	if (fpI & 1) {
		string ip0; ip0.push_back(ip[0]);
		t.m_val = ip0, curr.m_val = "0", mem.m_val = "0", mix.m_val = "0"; R = 1;
		while (((curr + Integer("1")) * ((curr + Integer("1"))) < t) || ((curr + Integer("1")) * ((curr + Integer("1"))) == t)) { ++curr; }
		mem = curr * Integer("2");
		t = t - curr * curr;
		string s1, s2;
		s1 = { ip[R++], '0' };
		s2 = { ip[R++] };
		t = t * Integer("100") + Integer(s1) + Integer(s2);
		ans += curr.m_val;
	}
	else {
		string ip0; ip0.push_back(ip[0]); ip0.push_back(ip[1]);
		t.m_val = ip0, curr.m_val = "0", mem.m_val = "0", mix.m_val = "0"; R = 2;
		while (((curr + Integer("1")) * ((curr + Integer("1"))) < t) || ((curr + Integer("1")) * ((curr + Integer("1"))) == t)) { ++curr; }
		mem = curr * Integer("2");
		t = t - curr * curr;
		string s1, s2;
		s1 = { ip[R++], '0' };
		s2 = { ip[R++] };
		t = t * Integer("100") + Integer(s1) + Integer(s2);
		ans += curr.m_val;
	}
	//cout << t<<" " << mem << endl;
	while (K--) {
		Integer i;
		for (i.m_val = "0"; i < Integer("10"); ++i) {
			Integer j = i + Integer("1");
			mix = (mem * Integer("10") + j) * j;
			if (mix > t) { break; }
		}
		mix = (mem * Integer("10") + i) * i;
		mem = mem * Integer("10") + i + i;
		//cout << mix << endl;
		t = t - mix;
		string s1, s2;
		s1 = { ip[R++], '0' };
		s2 = { ip[R++] };

		t = t * Integer("100") + Integer(s1) + Integer(s2);
		ans += (i.m_val);
		//cout << t <<" " << mix << " " << mem << endl;
		//system("PAUSE");
	}
	fpI = (fpI + 1) / 2;
	ans.insert(ans.begin() + fpI, '.');
	string trans = string(ans.begin(), ans.begin() + fpI + 102);
	//cout << trans << endl;
	Decimal ret(trans);
	//下面是四捨五入~~~
	//string co = "0.";
	//for (int i = 0; i < 99; ++i) { co.push_back('0'); }
	//co.push_back('1');
	////cout << ans[fpI + 101] << endl;
	////cout << ret<<endl;
	//if (ans[fpI + 101] >= '5') {
	//	ret = ret + Decimal(co);
	//}
	return ret;
}

Decimal Decimal::operator^(const Decimal bb) {
	if (bb.m_num.m_val == "0") {
		if (m_num.m_val == "0") {
			throw "!!!! 0^0 has not defined !!!!";
		}
		else {
			Integer ans;
			ans.CALC_assign("1");
			return Decimal(ans, ans);
		}
	}
	Decimal b = bb;
	b.m_num.m_posti = 1;

	bool sign = m_num.m_posti;

	Integer d = b.m_denum;
	Integer e = b.m_num;

	if (Integer((e / d) * d) == e) {
		Decimal ret((*this) ^ (b.m_num / b.m_denum));
		if (bb.m_num.m_posti == 0) {
			//cout << "A" << endl;
			swap(ret.m_num, ret.m_denum);
		}
		ret.m_num.m_posti = sign;
		return ret;
	}

	if (m_num.m_posti == 0) {
		throw "!!!! negitive Base number !!!!";
	}
	Integer r = Integer(b.m_num) / Integer(b.m_denum);
	//cout << r << endl;
	Integer intPart = r * b.m_denum;
	Integer decimalPart = b.m_num - intPart;
	//cout << b.m_num << endl;
	//cout << intPart << " " << decimalPart<<" "<< endl;
	//cout << (Integer(b.m_num) * Integer("2")).m_name<<" "<<b.m_denum << endl;
	if (!(Integer(decimalPart) * Integer("2") == b.m_denum)) {
		throw "!!!! exponent is not multiple 0.5 number !!!!";
	}
	Decimal ans(*this);
	Decimal v = sqrt(ans);
	//cout << ans << endl;
	//system("PAUSE");
	//cout << r << endl;
	if (!(r == Integer("0"))) {
		ans = (*this) ^ r;
	}
	else {
		ans = Decimal("1");
	}
	Decimal ret =  v * ans;
	if(bb.m_num.m_posti==0){
		//cout << "A" << endl;
		swap(ret.m_num, ret.m_denum);
	}
	ret.m_num.m_posti = sign;
	return ret;
}

Decimal Decimal::operator^(const Integer ipp) {
	Integer ip = ipp;
	bool sign = m_num.m_posti;
	ip.m_posti = 1; //改正
	if (Integer(ipp) == Integer("0")) {
		if (m_num == Integer("0")) {
			throw "!!!! 0^0 has not defined !!!!";
		}
		else {
			return Decimal("1.0");
		}
	}
	else if (m_num == Integer("0")) {
		//cout << "0.0^1" << endl;
		return Decimal("0.0");
	}
	Integer v = ip;
	Decimal b = (*this);
	Decimal ans = (Integer("1"), Integer("1"));
	while (v.m_val.size()) {
		ans = ans * b;
		v = v - Integer("1");
	}
	if (ipp.m_posti == 0) {
		swap(ans.m_denum, ans.m_num);
	}
	ans.m_num.m_posti = sign;
	return ans;
}
Decimal operator^(const Integer a, const Decimal b) {
	//cout << "In" << endl;
	Decimal c(a, Integer("1"));
	//cout << c.output() << endl;
	return c^b;
}

Decimal Decimal::operator+() {
	return (*this);
}
Decimal Decimal::operator-() {
	Decimal ans(*this);
	ans.m_num.m_posti = !m_num.m_posti;
	return ans;
}

Decimal Decimal::operator*(const Decimal ip) {
	Decimal ans;
	ans.m_num = m_num * ip.m_num;
	ans.m_denum = m_denum * ip.m_denum;
	return ans;
}
Decimal Decimal::operator*(const Integer ip) {
	Decimal ans(*this);
	ans.m_num = ans.m_num * ip;
	return ans;
}
Decimal operator*(const Integer a, const Decimal b) {
	Decimal ans(b);
	ans.m_num = ans.m_num * a;
	return ans;
}

#define coutline cout << "Line " << __LINE__ << " : "

Decimal Decimal::operator/(const Decimal ip) {

#ifdef DEBUG
	coutline << ip.m_num.m_val << endl;
#endif // DEBUG
	if (ip.m_num.m_val == "") {
		throw "!!!! divided by 0 !!!!";
	}
	Decimal v(ip.m_denum, ip.m_num);
	v.m_num.m_posti = v.m_denum.m_posti ^ v.m_num.m_posti;
	v.m_denum.m_posti = v.m_denum.m_posti ^ v.m_num.m_posti;
	v.m_num.m_posti = v.m_denum.m_posti ^ v.m_num.m_posti;
	Decimal ans((*this) * v);
	return ans;
}

Decimal Decimal::operator/(const Integer ip) {
#ifdef DEBUG
	coutline << ip.m_val << endl;
#endif // DEBUG
	if (ip.m_val == "") {
		throw "!!!! divided by 0 !!!!";
	}

	Decimal ans(*this);
	Integer v(ip);
	
	ans.m_num.m_posti = !(v.m_posti ^ ans.m_num.m_posti);

	ans.m_denum = ans.m_denum * v;
	return ans;
}
Decimal operator/(const Integer a, const Decimal b) {
	//std::cout << b;
#ifdef DEBUG
	coutline << b.m_num.m_val << endl;
#endif // DEBUG
	Decimal v(b.m_denum, b.m_num);
	if (b.m_num.m_val == "") {
		throw "!!!! divided by 0 !!!!";
	}
	v = v * Decimal(a);
	return v;
}

Decimal Decimal::operator+(const Decimal ip) {
	Decimal a(*this), b(ip);
	//a.cout_nnnn(); b.cout_nnnn();
	a.m_num = (a.m_num * b.m_denum) + (b.m_num * a.m_denum);
	//a.cout_nnnn();
	a.m_denum = a.m_denum * b.m_denum;
	return a;
}
Decimal Decimal::operator+(const Integer ip) {
	Decimal a(*this), b(ip, Integer("1"));
	return a + b;
}
Decimal operator+(const Integer a, const Decimal b) {
	Decimal v(a, Integer("1"));
	return v + b;
}
Decimal Decimal::operator-(const Decimal ip) {
	Decimal a(*this), b(ip);
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
Decimal Decimal::operator-(const Integer ip) {
	Decimal b(ip, Integer("1")), a(*this);
	b.m_num.m_posti = !b.m_num.m_posti;
	return a + b;

}
Decimal operator-(const Integer a, const Decimal b) {
	Decimal p(a, Integer("1"));
	Decimal v = b;
	v.m_num.m_posti = !v.m_num.m_posti;
	return p + v;
}

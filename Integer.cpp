#include "Integer.h"
#include <iostream>
using std::ostream;
using std::istream;
using std::max;
#include <vector>
using std::vector;

#include <string>
using std::string;

#include<algorithm>
using std::reverse;

Integer::Integer(){
    m_name = "_INT_DEFAULT_CON";
    m_posti = 1;
    m_digit = 0;
    m_val = "0";
}

 Integer::Integer(const Integer& t_Int){
     m_name = "_INT_CON_INT";
     m_posti = t_Int.m_posti;
     m_digit = t_Int.m_digit;
     m_val = t_Int.m_val;
 }

Integer::Integer(string t_str){
    m_name = "_INT_CON_STR";
#ifdef Calculator_hpp
	calc XXX(*this, t_str);
#else
	this->CALC_assign(t_str);
#endif // CALC_h
}

Integer Integer::operator=(const Integer t_Int){
    m_name = "_INT_COPY_INT";
	m_val = t_Int.m_val;
	m_posti = t_Int.m_posti;
	m_digit = t_Int.m_digit;
    return *this;
}

Integer Integer::operator=(const string& t_str){
	m_name = "_INT_COPY_STR";
#ifdef Calculator_hpp
	calc XXX(*this, t_str);
#else 
	this->CALC_assign(t_str);
#endif // CALC_h
    return *this;
}

void Integer::CALC_assign(string t_str){
    m_name = "_INT_CALC_ASSIGN";
    if(t_str.find('.') != string::npos){
		t_str = t_str.substr(0, t_str.find('.'));
    }
    if(t_str[0] == '-'){
        m_val = string(t_str, 1);
        m_posti = 0;
    }
    else{
        m_val = string(t_str);
        m_posti = 1;
    }
	int i = 0;
	for (auto j : m_val) {
		if (j == '0')i++;
		else break;
	}
}
void Integer::output() {
	std::cout << (m_posti ? "" : "-") << m_val;
}

istream& operator>> (istream& is, Integer& t_Int){
    string str;
    is >> str;
#ifdef Calculator_hpp
	calc XXX(t_Int, t_str);
#else 
	t_Int.CALC_assign(str);
#endif // CALC_h
    return is;
}

ostream& operator<< (ostream& os, Integer t_Int){
    os << (t_Int.m_posti?"" : "-") << t_Int.m_val;
    return os;
}
//----------------------------------------------------------
bool bigger(string a, string b){
	if(a.size()>b.size()){return true;}
	else if(a.size()==b.size()){return a>=b;}
	else{return false;}
}

Integer Integer::operator!(){
	Integer T, ans("1");
	T.m_val = m_val;
	while(T.m_val!="1"){
		ans = ans*T;
		T = T-Integer("1");
	}
	return ans;
}
Integer Integer::operator^(const Integer ip){
	Integer ans("1");
	Integer b(*this);
	Integer p(ip);
	while(p.m_val!=""){
		ans = ans*b;
		p = p-Integer("1");
		//cout << p.m_val << endl;
		//system("PAUSE");
	}
	return ans;
}

Integer Integer::operator+(){
	return *this;
}
Integer Integer::operator-(){
	m_posti = !m_posti;
	return *this;
}

Integer Integer::operator*(const Integer ip){
	string a(m_val), b(ip.m_val);
	bool sign = m_posti ^ ip.m_posti;
	Integer ans("0");
	if (a.size() < b.size()) { swap(a, b); }
	Integer curr(a);
	reverse(a.begin(), a.end());
	reverse(b.begin(), b.end());
	for (int i = 0; i < b.size(); ++i) {
		int dg = b[i] - '0';
		while (dg--) {
			ans = ans + curr;
		}
		//cout << ans << endl;
		curr.m_val+='0';
	}
	ans.m_posti = !sign;
	return ans;
}

Integer Integer::operator/(const Integer ip){
	Integer aa(*this), bb(ip);
	bool sign = aa.m_posti ^ bb.m_posti;
	aa.m_posti = 1;
	bb.m_posti = 1;
	if(!bigger(aa.m_val, bb.m_val)){
		return Integer("0");
	}

	Integer cnt("0");
	string bb_orgval = bb.m_val;
	int length_diff = aa.m_val.length() - bb.m_val.length();
	
	while (length_diff > -1) {
		bb.m_val = bb_orgval + string(length_diff--, '0');
		cnt = cnt * Integer("10");
		while (bigger(aa.m_val, bb.m_val)) {
			cnt = cnt + Integer("1");
			aa = aa - bb;
		}
	}
	
	cnt.m_posti = !sign;

	return cnt;
}

Integer Integer::operator+(const Integer ip){
	Integer R(*this), L(ip); 
	if (m_posti && ip.m_posti) {
		string ans, a, b;
		a = m_val;
		b = ip.m_val;
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		bool have_c = false;
		int c;
		int SZ = max(a.size(), b.size());
		for (int i = 0; i < SZ; ++i) {
			if (i >= a.size()) {
				int v = have_c ? c + b[i] - '0' : b[i] - '0';
				if (v >= 10) {
					c = v / 10;
					have_c = 1;
					v %= 10;
				}
				else { have_c = 0; }
				ans.push_back(v + '0');
			}
			else if (i >= b.size()) {
				int v = have_c ? c + a[i] - '0' : a[i] - '0';
				if (v >= 10) {
					c = v / 10;
					have_c = 1;
					v %= 10;
				}
				else { have_c = 0; }
				ans.push_back(v + '0');
			}
			else {
				int v = have_c ? c + a[i] + b[i] - '0' - '0' : a[i] + b[i] - '0' - '0';
				if (v >= 10) {
					c = v / 10;
					have_c = 1;
					v %= 10;
				}
				else { have_c = 0; }
				ans.push_back(v + '0');
			}
		}
		if (have_c) {
			ans.push_back(c + '0');
		}
		reverse(ans.begin(), ans.end());
		return Integer(ans);
	}
	else if (m_posti == 0 && ip.m_posti) {
		return -(-R-L);
	}
	else if (m_posti && ip.m_posti == 0) {
		return (R-(-L));
	}
	else if (m_posti == 0 && ip.m_posti == 0) {
		return -((-R)+(-L));
	}
	
}
Integer Integer::operator-(const Integer ip){
	Integer R(*this), L(ip);
	if (m_posti && ip.m_posti) {
		string a = m_val, b = ip.m_val, ans;
		bool neg = 0;
		Integer ret;
		if (bigger(a, b)) {}
		else {
			swap(a, b);
			neg = 1;
		}
		reverse(a.begin(), a.end());
		reverse(b.begin(), b.end());
		int SZ = a.size();
		for (int i = 0; i < SZ; ++i) {
			if (i >= b.size()) {
				ans.push_back(a[i]);
			}
			else if (a[i] < b[i]) {
				int j = i + 1;
				while (a[j] == '0') { a[j] = '9'; j++; }
				a[j]--;
				int v = a[i] - '0' + 10 - b[i] + '0';
				ans.push_back(v + '0');
			}
			else {
				ans.push_back(a[i] - b[i] + '0');
			}
		}
		reverse(ans.begin(), ans.end());
		while (ans.size() && *ans.begin() == '0') { ans.erase(ans.begin()); }
		if (neg) { m_posti = false; }
		ret.m_val = ans;
		return ret;
	}
	else if (m_posti == 0 && ip.m_posti) {
		Integer v =  -R+L;
		v.m_posti = 0;
		return v;
	}
	else if (m_posti && ip.m_posti == 0) {
		Integer v = R + (-L);
		v.m_posti = 1;
		return v;
	}
	else if (m_posti == 0 && ip.m_posti == 0) {
		return (-L) - (-R);
	}
}

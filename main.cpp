
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using std::endl;

#include <vector>
using std::vector;

#include <string>
using std::string;

#include "Calculator.hpp"
#include "numberobj.h"
#include "Integer.h"
#include "Decimal.h"

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (T i : vec) {
		os << i << endl;
	}
	return os;
}


int main(){
	Decimal a(Integer("987580089"), Integer("35645615646541564")), b("-0.5"), c("0.5"), d("1"), e("-1");

	// Decimal f = a + b;
	// Decimal g = a - b;
	// Decimal h = a * b;
	// Decimal i = a / b;

	cout << vector<Decimal>({ a,b,c,d,e,f,g,h,i });

	// Integer INTa("-1156564"), INTb("1000."), INTc("-0.5"), INTd("0.5"), INTe("1132515641036546145346546313");
	// Integer INTf = INTa + INTb;
	// Integer INTg = INTa - INTb;
	// Integer INTh = INTa * INTb;
	// Integer INTi = INTa / INTb;
	
	
	// cout << vector<Decimal>({ a + INTa, a - INTa , a * INTa , a / INTa });
	// cout << vector<Decimal>({ INTa + a, INTa - a , INTa * a , INTa / a });

	// cout << vector<Integer>({ INTa,INTb,INTc,INTd,INTe,INTf,INTg,INTh,INTi });

	// cout << vector<numberobj*>({&INTa, &INTb, &INTc, &INTd, &a, &b, &c, &i});


	// Calculator calculator;

	// while (calculator.isPowerOn()) {
	// 	std::string str;
	// 	getline(cin, str);
	// 	cout << calculator.inputCommand(str) << endl;
	// }
}

/*

Decimal ostream undone

*/
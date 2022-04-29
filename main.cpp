
#include <iostream>
using std::ostream;
using std::istream;
using std::cout;
using std::cin;
using namespace std;
#include <vector>
using std::vector;

#include <string>
using std::string;

#include "numberobj.h"
#include "Integer.h"
#include "Decimal.h"

template<typename T>
ostream& operator<<(ostream& os, vector<T> vec) {
	for (auto i : vec) {
		os << i << endl;
	}
	return os;
}

int main(){
	Decimal a(Integer("987580089"), Integer("35645615646541564")), b("-0.5"), c("0.5"), i("1"), j("-1");
	
	//cout << vector<Decimal>({a,b,c,i,j});

	Decimal e = a + b;
	Decimal f = a - b;
	Decimal g = a * b;
	Decimal h = a / b;
	//g.cout_nnnn();
	//h.cout_nnnn();
	cout << vector<Decimal>({a,b,c,e,f,g,h,i,j});

	Integer INTa("-1"), INTb("1000."), INTc("-0.5"), INTd("0.5"), INTe("1");
	Integer INTf = INTa + INTb;
	Integer INTg = INTa - INTb;
	Integer INTh = INTa * INTb;
	Integer INTi = INTa / INTb;
	
	cout << vector<Integer>({ INTa,INTb,INTc,INTe,INTf,INTg,INTh,INTi });

	cout << vector<Decimal>({ a + INTa, a - INTa , a * INTa , a / INTa });
	cout << vector<Decimal>({ INTa + a, INTa - a , INTa * a , INTa / a });
	
}

/*

Decimal ostream undone

*/
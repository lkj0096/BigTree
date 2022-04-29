
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


int main(){
	Decimal a(Integer("987580089"), Integer("35645615646541564")), b("-0.5"), c("0.5"), i("1"), j("-1");
	Integer z("10");
	//cout << vector<Decimal>({a,b,c,i,j});

	Decimal e = a + b;
	Decimal f = a - b;
	Decimal g = a * b;
	Decimal h = a / b;
	//g.cout_nnnn();
	//h.cout_nnnn();

	Integer INTa("-1"), INTb("1000."), INTc("-0.5"), INTd("0.5"), INTe("1");
	Integer INTf = INTa + INTb;
	Integer INTg = INTa - INTb;
	Integer INTh = INTa * INTb;
	Integer INTi = INTa / INTb;
	vector<numberobj*> nums = { &z, &a };
	cout << nums[0]<<endl<<nums[1];
}

/*

Decimal ostream undone

*/
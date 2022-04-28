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
	Decimal a("-0.5"), b(Integer("432874798324"), Integer("987580089")), c(Integer("27489327"), Integer("74643082"));
	//							 432874798324
	//Decimal e = b+c;
	//Decimal f = b - c;
	//Decimal g = b * c;
	//Decimal h = b / c;

	//e.cout_nnnn();
	//f.cout_nnnn();
	//g.cout_nnnn();
	//h.cout_nnnn();
	//Integer A("1000");
	cout << a << endl << b << endl;
				   //10000000

}

/*

Decimal ostream undone

*/
#ifndef DEBUG
//#define DEBUG
#endif // !DEBUG

#ifndef API1
//#define API1
#endif // !DEBUG

#ifndef API2
//#define API2
#endif // !DEBUG

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

#include "Calculator.h"
#include "numberobj.h"
#include "Integer.h"
#include "Decimal.h"

int main(){

#ifdef API1
	Integer x;
	Decimal y;

	cin >> x; // ¿é¤J 123456789
	cin >> y; // ¿é¤J 3.1415926

	cout << x + y << endl;
	cout << x - y << endl;
	cout << x * y << endl;
	cout << x / y << endl;
#else 
#ifdef API2
	Integer x = "123 * 8 + 456";
	Decimal y = "-1.0 / 3 - 45 / 13.0";

	vector<numberobj*> nums;
	nums.push_back(&x);
	nums.push_back(&y);
	for (const auto& num : nums)
	cout << num << endl;

#else
	Calculator calculator;
	while (calculator.isPowerOn()) {
		std::string str;
		getline(cin, str);
		try {
			calculator.inputCommand(str);
		}
		catch (const char* errstr) {
			cout << errstr << endl;
		}
	}
#endif
#endif // API
	
}

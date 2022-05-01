//
//  Calculator.hpp
//  bigNum
//
//  Created by 林士傑 on 2022/4/27.
//

#define DEBUG

#ifndef Calculator_hpp
#define Calculator_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
#include "numberobj.h"
#include "Integer.h"
#include "Decimal.h"

#endif /* Calculator_hpp */

#include <string>


class CalcuObj {
public:
    bool isOperator;
    std::string value;
    CalcuObj();
    CalcuObj(bool, std::string);
};

class Memoryer {
public:
    std::map<std::string, numberobj*> numbers;
    bool setNumberObj(std::string cmd);
    numberobj* getNumberObj(std::string name);
};


class Calculator {
private:
    std::stack<numberobj*> resultStack;
    std::stack<CalcuObj> ComputeStack;
    std::stack<char> SupportStack;

    Memoryer memoryer;

    void PreCalculate(std::string input);

    std::string suffixToPrefix(std::string input);
    void TakeSupportStack(int priority);
    int OperatorPriority(char op);
    int OperatorLeftToRight(char op);

    numberobj* Calculate();

public:
    bool isPowerOn();
    void inputCommand(std::string input);
    friend void NumberConstruct(Integer* self, std::string input);
    friend void NumberConstruct(Decimal* self, std::string input);
};

void NumberConstruct(Integer* self, std::string input);
void NumberConstruct(Decimal* self, std::string input);
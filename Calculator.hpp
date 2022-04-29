//
//  Calculator.hpp
//  bigNum
//
//  Created by 林士傑 on 2022/4/27.
//

#ifndef Calculator_hpp
#define Calculator_hpp

#include <stdio.h>
#include <vector>
#include <stack>
#include <map>
#include "NumberObj.hpp"

#endif /* Calculator_hpp */

#include <string>


class CalcuObj {
public:
    bool isOperator;
    std::string value;
    CalcuObj();
    CalcuObj(bool, std::string);
};

class Memoryer{
public:
    std::map<std::string, NumberObj*> numbers;
    bool setNumberObj(std::string cmd);
    NumberObj* getNumberObj(std::string name);
};


class Calculator {
private:
    std::stack<NumberObj*> resultStack;
    std::stack<CalcuObj> ComputeStack;
    std::stack<char> SupportStack;
    
    Memoryer memoryer;
    
    void PreCalculate(std::string input);
    
    std::string suffixToPrefix(std::string input);
    void TakeSupportStack(int priority);
    int OperatorPriority(char op);
    int OperatorLeftToRight(char op);
    
    NumberObj* Calculate();
    
public:
    bool isPowerOn();
    NumberObj* inputCommand(std::string input);
    static int NumberConstruct(std::string input);
};

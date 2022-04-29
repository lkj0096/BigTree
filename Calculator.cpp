//
//  Calculator.cpp
//  bigNum
//
//  Created by 林士傑 on 2022/4/27.
//

#include "Calculator.hpp"

#include <iostream>
#include <regex>

using namespace std;

CalcuObj::CalcuObj(){}

CalcuObj::CalcuObj(bool b, std::string s){
    isOperator = b;
    value = s;
};

bool Memoryer::setNumberObj(std::string cmd){
    cmd = regex_replace(cmd, regex(" +"), " ");
    std::smatch sm;
    bool match = regex_search(cmd, sm, regex("^([^ ]+) ([^ ]+) ([^ ]+) ([^ ]+) ?$"));
    if(!match) return false;
    
    //action
    match &= regex_match(sm[1].str(), regex("^[Ss][Ee][Tt]$"));
    
    //type
    bool isInteger = regex_match(sm[2].str(), regex("^[Ii][Nn][Tt][Ee][Gg][Ee][Rr]$"));
    bool isDecimal = regex_match(sm[2].str(), regex("^[Dd][Ee][Cc][Ee][Mm][Aa][Ll]$"));
    match &= ( isInteger || isDecimal );
    
    //name
    match &= !regex_search(sm[3].str(), regex("[\\(\\)\\!\\^\\+\\-\\*\\/]"));
    
    //value
    match &= regex_match(sm[4].str(), regex("^[-+]?\\d+\\.?\\d*$"));
    
    if(!match){
        return false;
    }
    
    ///type add var
    
//    if(isInteger){
//        numbers[sm[3]] =
//    }else{
//        numbers[sm[3]] =
//    }
    
    return true;
}

NumberObj* Memoryer::getNumberObj(std::string name){
    auto num = numbers.find(name);
    if(num != numbers.end()){
        return numbers[name];
    }
    throw ("Variable : " + name + " is not found.");
}



void Calculator::PreCalculate(std::string input) {
    resultStack = stack<NumberObj*>();
    ComputeStack = stack<CalcuObj>();
    SupportStack = stack<char>();
    //normalize input -> (input)
    input = "(" + input + ")";
    
    //no space
    input = regex_replace(input, regex(" "), "");

    //[(-num) or (+num)] -> [(0-num) or (0+num)]
    input = regex_replace(input, regex("\\(-"), "(0-");
    input = regex_replace(input, regex("\\(\\+"), "(0+");
    
    //[num-num] -> [num+-num]
    input = regex_replace(input, regex("([^\\(\\)\\!\\^\\+\\-\\*\\/])-"), "$1+-");
    
    suffixToPrefix(input);
}

std::string Calculator::suffixToPrefix(std::string input) {
    while(input.size()){
        std::smatch sm;
        bool isNotOperator = regex_search(input, sm, regex("^[^\\(\\)\\!\\^\\+\\-\\*\\/]+"));
        if(isNotOperator){
            string str = sm[0];
            ComputeStack.push(CalcuObj(false, str));
            input = input.substr(str.size(), input.size() - str.size());
            
            ///todo
            continue;
//            return "";
        }
        char op = input[0];
        input = input.substr(1, input.size() - 1);
        cout << "Operator : " << op << endl;
        
        int level = OperatorPriority(op);
        int leftToRight = OperatorLeftToRight(op);
        
        switch (op) {
            case '+':
            case '*':
            case '/':
            case '-':
            case '^':
            case '!':
                TakeSupportStack(level + leftToRight);
                SupportStack.push(op);
                break;
            case '(':
                //
                SupportStack.push(op);
//                input = Calculate("0" + input);
                break;
            case ')':
                TakeSupportStack(-1);
//                return input;
                break;
            default:
                throw ("something wrong AT get operator " + to_string(op));
                break;
        }
    }
    TakeSupportStack(6);
    return "";
}

void Calculator::TakeSupportStack(int priority){
    char c;
    if(priority == -1){
        while (!SupportStack.empty() && (c = SupportStack.top()) != '(') {
            ComputeStack.push(CalcuObj(true, string(1,c)));
            SupportStack.pop();
        }
        SupportStack.pop();
        return;
    }
    while(!SupportStack.empty() && OperatorPriority(c = SupportStack.top()) < priority){
        ComputeStack.push(CalcuObj(true, string(1,c)));
        SupportStack.pop();
    }
}

int Calculator::OperatorPriority(char op){
    switch (op) {
        case '(': return 6;
        case ')': return 6;
        case '!': return 1;
        case '^': return 2;
        case '-': return 3;
        case '*':
        case '/': return 4;
        case '+': return 5;
        default:  return 7;
    }
}

int Calculator::OperatorLeftToRight(char op){
    switch (op) {
        case '(': return 1;
        case ')': return 1;
        case '!': return 1;
        case '^': return 0;
        case '-': return 0;
        case '*':
        case '/': return 1;
        case '+': return 1;
        default:  return 2;
    }
}

NumberObj* Calculator::Calculate(){
    CalcuObj obj;
    while(!ComputeStack.empty()){
        obj = ComputeStack.top();
        if(!obj.isOperator){
            ///todo
            //if number -> calc_assign
            //
            //else find in memoryer
            //
            
            continue;
        }
        
        char op = obj.value[0];
        NumberObj *var0, *var1;
        var0 = resultStack.top();
        resultStack.pop();
        try{
            switch (op) {
                case '+':
                    var1 = resultStack.top();
                    resultStack.pop();
                    //var1 + var0
                    break;
                case '-':
                    //-var0
                    break;
                case '*':
                    var1 = resultStack.top();
                    resultStack.pop();
                    //var1 * var0
                    break;
                case '/':
                    var1 = resultStack.top();
                    resultStack.pop();
                    //var1 / var0
                    break;
                case '!':
                    //var0!
                    break;
                case '^':
                    var1 = resultStack.top();
                    resultStack.pop();
                    //var1^var0
                    break;
                default:
                    break;
            }
        }catch(const char* s){
            cout << "ERROR : " << s << endl;
        }
    }
    return resultStack.top();
}

int Calculator::NumberConstruct(std::string input) {
    return 0;
}

bool Calculator::isPowerOn() {
    return true;
}


NumberObj* Calculator::inputCommand(std::string input) {
    //1+2+3*4/5*-6/(7+8)+9^10!
    //1,2,+,3,4,*,5,/,6,-,*,7,8,+,/,+,9,10,!,^,+
    
    //-2!
    //2,!,-
    
    //(-2)!
    //2,-,!
    
    //2*-6
    //2,6,-,*
    
    bool succeed = memoryer.setNumberObj(input);
    
    return nullptr;
    
    PreCalculate(input);
    
    return Calculate();
}

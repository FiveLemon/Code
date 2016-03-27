#include <iostream>
#include <string>
#include <stack>
#include <vector>
#include <boost/lexical_cast.hpp>

using namespace std;
using namespace boost;

/*
 isOper: This function used to check whether oper is +, -, *, /, (, )
    The other isOper function is overload function for same use.
 */
bool isOper(string oper);
bool isOper(char oper);
/*
 getPriority: This function used to get priority of math operator which will
     used in converting Prefix Expression To Postfix Expression.
     The other same name function is a ovlerload function for same function.
 */
int getPriority(char oper);
int getPriority(string oper);
/*
 doMath: This function used to real calculate of add sub multiply and divide.
    The other same name function is a ovlerload function for same function.
 */
double doMath(double operOne, double operTwo, char oper);
double doMath(double operOne, double operTwo, string oper);
/*
 splitPrefixExpression: split the string to vector whic contains every element of equaltion
    in same order, like 9+(3-1)*3+10/2 -> 9, +, (, 3, -, 1, ), *, 3, +, 10, /, 2
 */
vector<string> splitPrefixExpression(string prefixExpression);
/*
 convertPrefixExpressionToPostfixExpression: convert Prefix Expression To Postfix Expression.
 */
vector<string> convertPrefixExpressionToPostfixExpression(vector<string> prefixExpression);
/*
 calculatePostfixExpression: calculate Postfix Expression.
 */
double calculatePostfixExpression(vector<string> postfixExpression);

bool isOper(string oper) {
    if (1 == oper.size()) {
        return isOper(oper[0]);
    }
    return false;
}

bool isOper(char oper) {
    return ('+' == oper || '-' == oper || '*' == oper ||
            '/' == oper || '(' == oper || ')' == oper )? true : false;
}

int getPriority(char oper) {
    switch (oper) {
        case '+':
        case '-':
            return 1;
        case '*':
        case '/':
            return 2;
        case '(':
        case ')':
            return 0;
        default:
            return -1;
    }
}

int getPriority(string oper) {
    if (1 == oper.size()) {
        return getPriority(oper[0]);
    }
    return -1;
}

double doMath(double operOne, double operTwo, char oper) {
    switch(oper){
        case '+':
            return operOne + operTwo;
        case '-':
            return operOne - operTwo;
        case '*':
            return operOne * operTwo;
        case '/':
            return operOne / operTwo;
        default:
            return 0.0f;
    }
}

double doMath(double operOne, double operTwo, string oper) {
    if (1 == oper.size()) {
        return doMath(operOne, operTwo, oper[0]);
    }
    return 0.0f;
}

vector<string> splitPrefixExpression(string prefixExpression) {
    vector<string> result;
    int tempIndex = 0;
    for (int index = 0; index < prefixExpression.size(); index++) {
        /*below statements of if is to get the operator in the equaltion*/
        if (isOper(prefixExpression[index])) {
            result.push_back(prefixExpression.substr(index, 1));
            continue;
        }
        /*filter away the spaces which may be exist in equaltion*/
        if (' ' == prefixExpression[index]) {
            continue;
        }
        /*below while statements which will get numbers(maybe more than one bits 
         or may have dot in that(float))*/
        tempIndex = index;
        while (prefixExpression[index] >= '0' && prefixExpression[index] <= '9') {
            if (' ' == prefixExpression[index + 1] || isOper(prefixExpression[index + 1]) ||
                index == prefixExpression.size() - 1) {
                result.push_back(prefixExpression.substr(tempIndex, index - tempIndex + 1));
                //index--;
                break;
            }
            index++;
        }
    }
    return result;
}
/*
 中缀表达式转后缀表达式的方法：
 1.遇到操作数：直接输出（添加到后缀表达式中）
 2.栈为空时，遇到运算符，直接入栈
 3.遇到左括号：将其入栈
 4.遇到右括号：执行出栈操作，并将出栈的元素输出，直到弹出栈的是左括号，左括号不输出。
 5.遇到其他运算符：加减乘除：弹出所有优先级大于或者等于该运算符的栈顶元素，然后将该运算符入栈
 6.最终将栈中的元素依次出栈，输出。
 */
vector<string> convertPrefixExpressionToPostfixExpression(vector<string> prefixExpression) {
    vector<string> result;
    stack<string> tool;
    for (auto const& item : prefixExpression) {
        if (isOper(item)) {
            if (tool.empty() || "(" == item) {
                tool.push(item);
            } else if (")" == item) {
                while ("(" != tool.top()) {
                    result.push_back(tool.top());
                    tool.pop();
                }
                tool.pop();
            } else {
                while (!tool.empty() && (getPriority(item) <= getPriority(tool.top()))) {
                    result.push_back(tool.top());
                    tool.pop();
                }
                tool.push(item);
            }
        } else {
            result.push_back(item);
        }
    }
    while (!tool.empty()){
        result.push_back(tool.top());
        tool.pop();
    }
    return result;
}
/*
 从左到右遍历表达式的每个数字和符号，遇到数字就进栈，遇到符号就将栈顶的两个元素出栈(第一个出栈的
 是操作数B，第二个出栈的是被操作数A),然后做运算A 操作符 B，将计算的结果进栈，一直到获得最终结果。
 */
double calculatePostfixExpression(vector<string> postfixExpression) {
    stack<double> tool;
    double operOne = 0.0f;
    double operTwo = 0.0f;
    for (auto const & item : postfixExpression) {
        if (!isOper(item)){
            tool.push(lexical_cast<double>(item));
        } else {
            operTwo = tool.top();
            tool.pop();
            operOne = tool.top();
            tool.pop();
            tool.push(doMath(operOne, operTwo, item));
        }
    }
    return tool.top();
}

int main() {
    string expression = "9 + 6*(3 - (3 + 9) *1) * 3 + 10 / 2";
    cout << calculatePostfixExpression(convertPrefixExpressionToPostfixExpression(splitPrefixExpression(expression))) << endl;
    return 0;
}

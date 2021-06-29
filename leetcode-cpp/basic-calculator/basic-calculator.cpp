//
// Created by smile on 2021/6/20.
//

#include <string>
#include <stack>
#include <tuple>
#include <vector>
#include <cmath>

// 表达式分离数据
struct exprItem {
    char Operator;
    int Number;

    explicit exprItem(char _operator) : Operator(_operator), Number(NULL) {};
    explicit exprItem(int _number) : Operator(NULL), Number(_number) {};
};

class Solution {
public:
    int calculate(std::string &s) {
        getInfixExpr(s);
        getPostfixFromInfix();
        return postfixCalculate();
    }

private:
    // 中缀表达式
    std::vector<exprItem> infix;

    // 后缀表达式
    std::vector<exprItem> postfix;


    // 运算符判定
    static constexpr bool isOperator(char ch) {
        return ch == '+'
               or ch == '-'
               or ch == '*'
               or ch == '/'
               or ch == '^';
    }

    // 数字判定
    static inline bool isNumber(char ch) {
        return isdigit(ch) or ch == '.';
    }

    //优先级判定
    static inline uint8_t priority(char operatorChar) {
        uint8_t level = 0;  // level越大，优先级越高
        if (operatorChar == '^') {
            level = 2;
        } else if (operatorChar == '*' or operatorChar == '/') {
            level = 1;
        } else if (operatorChar == '+' or operatorChar == '-') {
            level = 0;
        }
        return level;
    }

    //获取数字栈顶双数
    template<typename T>
    std::tuple<T, T> getTwoNums(std::stack<T> &nums) {
        auto second = nums.top();
        nums.pop();
        auto first = nums.top();
        nums.pop();
        return {first, second};
    }   // return {first, second}

    // 计算后缀表达式
    int postfixCalculate() {
        int first, second;
        std::stack<int> nums;
        for (const auto &item : postfix) {
            switch (item.Operator) {
                case '*':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.push(first * second);
                    break;
                case '/':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.push(first / second);
                    break;
                case '+':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.push(first + second);
                    break;
                case '-':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.push(first - second);
                    break;
                case '^':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.push(int(pow(first, second)));
                    break;
                default:
                    nums.push(item.Number);
                    break;
            }
        }
        return nums.top();
    }

    // 表达式做分割，形成中缀表达式
    void getInfixExpr(std::string &expr) {
        std::string numStr;  // 单个连续字符的数字
        for (const auto &ch : expr) {
            if (isNumber(ch)) {
                numStr += ch;
            } else if (isOperator(ch) or ch == '(' or ch == ')') {
                if (not numStr.empty()) {
                    infix.emplace_back(exprItem{stoi(numStr)});
                }
                numStr = "";
                infix.emplace_back(exprItem{ch});
            }
        }
        if (not numStr.empty()) {
            infix.emplace_back(exprItem{stoi(numStr)});
        }

        //前导缺损+-符号补0
        std::vector<exprItem> fullPostfix;
        char preChar = '(';
        for (const auto &p : infix) {
            if (p.Operator != NULL) {
                if (preChar == '(' and (p.Operator == '-' or p.Operator == '+'))
                    fullPostfix.emplace_back(exprItem{0});
                preChar = p.Operator;
            } else {
                preChar = NULL;
            }
            fullPostfix.emplace_back(p);
        }
        std::swap(fullPostfix, infix);
    }

    //中缀转后缀表达式
    std::vector<exprItem> getPostfixFromInfix() {
        std::stack<char> operatorStack;
        for (const auto &item: infix) {
            if (isOperator(item.Operator)) {
                while (not operatorStack.empty()
                       and isOperator(operatorStack.top())
                       and priority(operatorStack.top()) >= priority(item.Operator)) {      // 优先级
                    postfix.emplace_back(exprItem{operatorStack.top()});
                    operatorStack.pop();
                }
                operatorStack.emplace(item.Operator);
            } else if (item.Operator == '(') {
                operatorStack.emplace(item.Operator);
            } else if (item.Operator == ')') {
                while (operatorStack.top() != '(') {
                    postfix.emplace_back(exprItem{operatorStack.top()});
                    operatorStack.pop();
                }
                operatorStack.pop();
            } else {
                postfix.emplace_back(item);
            }

        }
        while (not operatorStack.empty()) {
            postfix.emplace_back(exprItem{operatorStack.top()});
            operatorStack.pop();
        }
        return postfix;
    }
};
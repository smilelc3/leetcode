//
// Created by smile on 2021/9/25.
//

#include <string>
#include <stack>
#include <tuple>
#include <vector>
#include <cmath>


// 定义的多种数据类型
enum {
    OPERATOR_TYPE,
    INTEGER_TYPE,
    DECIMAL_TYPE,
};

// 表达式分离数据类 (数据和符号共用内存)
class ExprItem {
public:
    union {
        char Operator;
        int64_t Integer;
        double Decimal;
    } Value{};
    uint8_t Type{};

    explicit ExprItem(char _operator) {
        Type = OPERATOR_TYPE;
        Value.Operator = _operator;
    };

    explicit ExprItem(int64_t _number) {
        Type = INTEGER_TYPE;
        Value.Integer = _number;
    };

    explicit ExprItem(int _number) {
        new(this) ExprItem((int64_t) _number);
    };

    explicit ExprItem(double _number) {
        Type = DECIMAL_TYPE;
        Value.Decimal = _number;
    };
};


class Solution {
public:
    int calculate(std::string &s) {
        calInfixExpr(s);
        calPostfixFromInfix();
        return (int) postfixCalculate();
    }

private:
    // 中缀表达式
    std::vector<ExprItem> infix;

    // 后缀表达式
    std::vector<ExprItem> postfix;


    // 二元运算符判定
    static constexpr bool isBinOperator(char ch) {
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
        if (operatorChar == '+' or operatorChar == '-') {
            level = 0;
        } else if (operatorChar == '*' or operatorChar == '/') {
            level = 1;
        } else if (operatorChar == '^') {
            level = 2;
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
    double postfixCalculate() {
        int first, second;
        std::stack<int> nums;

        for (const auto &item: postfix) {
            if (item.Type != OPERATOR_TYPE) {
                if (item.Type == INTEGER_TYPE) {
                    nums.emplace(static_cast<int>(item.Value.Integer));
                }
                if (item.Type == DECIMAL_TYPE) {
                    nums.emplace(static_cast<int>(item.Value.Decimal));
                }
                continue;
            }
            switch (item.Value.Operator) {
                case '*':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.push(first * second);
                    break;
                case '/':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.emplace(first / second);
                    break;
                case '+':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.emplace(first + second);
                    break;
                case '-':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.emplace(first - second);
                    break;
                case '^':
                    std::tie(first, second) = getTwoNums(nums);
                    nums.emplace(static_cast<int>(pow(first, second)));
                    break;
            }
        }
        return nums.top();
    }

    // 表达式做分割，形成中缀表达式
    void calInfixExpr(std::string &expr) {
        std::stringstream numBuf;  // 单个连续字符的数字
        bool isDecimal = false; // 判断是否是小数
        for (const auto &ch: expr) {
            if (isNumber(ch)) {
                isDecimal = ch == '.';
                numBuf << ch;
            } else if (isBinOperator(ch) or ch == '(' or ch == ')') {
                if (not numBuf.str().empty()) {
                    infix.emplace_back(
                            isDecimal ? ExprItem{std::stod(numBuf.str())}
                                      : ExprItem{std::stoi(numBuf.str())});
                }
                numBuf.str("");     // 清空buf
                isDecimal = false;
                infix.emplace_back(ExprItem{ch});
            }
        }
        if (not numBuf.str().empty()) {
            infix.emplace_back(
                    isDecimal ? ExprItem{std::stod(numBuf.str())}
                              : ExprItem{std::stoi(numBuf.str())});
        }

        // +-符号作为数字正负数形式 -> 前补0
        std::vector<ExprItem> fullPostfix;
        fullPostfix.reserve(infix.size());
        for (size_t idx = 0; idx < infix.size(); ++idx) {
            if (infix[idx].Type == OPERATOR_TYPE &&
                (infix[idx].Value.Operator == '+' or infix[idx].Value.Operator == '-')) {
                if (idx == 0 or (infix[idx - 1].Type == OPERATOR_TYPE and infix[idx - 1].Value.Operator != ')')) {
                    fullPostfix.emplace_back(ExprItem{0});
                }
            }
            fullPostfix.emplace_back(infix[idx]);
        }
        std::swap(fullPostfix, infix);
    }

    //中缀转后缀表达式
    void calPostfixFromInfix() {
        std::stack<char> operatorStack;
        for (const auto &item: infix) {
            if (item.Type == OPERATOR_TYPE) {
                if (isBinOperator(item.Value.Operator)) {
                    while (not operatorStack.empty()
                           and isBinOperator(operatorStack.top())
                           and priority(operatorStack.top()) >= priority(item.Value.Operator)) {      // 优先级
                        postfix.emplace_back(ExprItem{operatorStack.top()});
                        operatorStack.pop();
                    }
                    operatorStack.emplace(item.Value.Operator);
                } else if (item.Value.Operator == '(') {
                    operatorStack.emplace(item.Value.Operator);
                } else if (item.Value.Operator == ')') {
                    while (operatorStack.top() != '(') {
                        postfix.emplace_back(ExprItem{operatorStack.top()});
                        operatorStack.pop();
                    }
                    operatorStack.pop();
                }
            } else {
                postfix.emplace_back(item);
            }
        }
        while (not operatorStack.empty()) {
            postfix.emplace_back(ExprItem{operatorStack.top()});
            operatorStack.pop();
        }
    }
};
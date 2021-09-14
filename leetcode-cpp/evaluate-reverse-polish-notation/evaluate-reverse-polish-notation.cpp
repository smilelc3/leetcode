//
// Created by smile on 2021/5/2.
//
#include <vector>
#include <string>
#include <stack>
#include <cmath>

class Solution {
public:
    int evalRPN(std::vector<std::string> &tokens) {
        int first, second;
        for (const auto &token: tokens) {
            if (not isOperator(token)) {
                numsStack.emplace(std::stoi(token));
            } else {
                second = numsStack.top();
                numsStack.pop();
                first = numsStack.top();
                numsStack.pop();
                switch (token[0]) {
                    case '+':
                        numsStack.emplace(first + second);
                        break;
                    case '-':
                        numsStack.emplace(first - second);
                        break;
                    case '*':
                        numsStack.emplace(first * second);
                        break;
                    case '/':
                        numsStack.emplace(first / second);
                        break;
                    case '^':
                        numsStack.emplace((int) std::pow(first, second));
                        break;
                    case '%':
                        numsStack.emplace(first % second);
                        break;
                }
            }
        }

        return numsStack.top();
    }

private:
    std::stack<int> numsStack;

    inline bool isOperator(const std::string &token) {
        return token.size() == 1
               and (token == "+"
                    or token == "-"
                    or token == "*"
                    or token == "/"
                    or token == "^"
                    or token == "%");
    }

};
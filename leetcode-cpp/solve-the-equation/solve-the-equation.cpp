//
// Created by smile on 24-6-1.
//

#include <string>
#include <sstream>

class Solution {
public:
    static std::string solveEquation(std::string &equation) {
        auto eqCharPos = equation.find_first_of('=');
        auto left = simplifiedFormula(equation, 0, eqCharPos);
        auto right = simplifiedFormula(equation, eqCharPos + 1, equation.size());
        auto factor = left.first - right.first;
        auto constant = right.second - left.second;
        if (factor == 0) {
            return constant == 0 ? "Infinite solutions" : "No solution";
        }
        std::stringstream ss;
        ss << "x=" << constant / factor;
        return ss.str();
    }

private:
    static std::pair<int32_t, int32_t> simplifiedFormula(std::string &equation, size_t startPos, size_t endPos) {
        int32_t factor = 0; // x系数
        int32_t constant = 0; // 常数

        int32_t num = 0;
        bool isExistNum = false;
        bool isNeg = false;
        for (auto pos = startPos; pos < endPos; ++pos) {
            if (equation[pos] == '+') {
                isNeg = false;
            } else if (equation[pos] == '-') {
                isNeg = true;
            } else if (equation[pos] == 'x') {
                if (isExistNum) {
                    factor += isNeg ? -num : num;
                    num = 0;
                    isExistNum = false;
                } else {
                    factor += isNeg ? -1 : 1;
                }
            } else {
                num = num * 10 + (equation[pos] - '0');
                isExistNum = true;
                if (pos + 1 == endPos or equation[pos + 1] == '+' or equation[pos + 1] == '-') {
                    constant += isNeg ? -num : num;
                    num = 0;
                    isExistNum = false;
                }
            }
        }

        return {factor, constant};
    }
};

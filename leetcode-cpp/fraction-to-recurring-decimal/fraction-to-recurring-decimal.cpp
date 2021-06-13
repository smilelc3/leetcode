//
// Created by smile on 2021/6/12.
//

#include <string>
#include <unordered_map>
#include <stdexcept>

class Solution {
public:
    std::string fractionToDecimal(int64_t numerator, int64_t denominator) {
        if (denominator == 0) {
            throw std::logic_error("div shouldn't be Zero");
        }
        if (denominator < 0) {
            denominator = -denominator;
            numerator = -numerator;
        }
        if (numerator < 0) {
            numerator = -numerator;
            isResNeg = true;
        }
        auto gcdVal = gcd(numerator, denominator);
        numerator /= gcdVal;
        denominator /= gcdVal;

        intPart = std::to_string(numerator / denominator);
        numerator %= denominator;
        // 长除法产生的差与对应位置map
        std::unordered_map<int64_t, size_t> diffMap;
        size_t idx = 0;
        while (numerator != 0 and diffMap.find(numerator) == diffMap.end()) {
            diffMap.emplace(numerator, idx);
            numerator *= 10;
            decPart.append(std::to_string(numerator / denominator));
            numerator %= denominator;
            idx++;
        }
        if (numerator != 0) {
            this->isCycleDec = true;
            this->cycleIdx = diffMap[numerator];
        }
        return getFracRes();
    }

private:
    // 整数部分
    std::string intPart;

    // 小数部分
    std::string decPart;

    // 是否是循环小数
    bool isCycleDec = false;

    // 循环在小数部分的起始位置
    size_t cycleIdx;

    // 结果是否是负数
    bool isResNeg = false;

    // 返回答案
    std::string getFracRes() {
        std::stringstream res;
        if (isResNeg) {
            res << '-';
        }
        res << intPart;
        if (not decPart.empty()) {
            res << '.';
            if (isCycleDec) {
                res << decPart.substr(0, cycleIdx) << '(' + decPart.substr(cycleIdx) + ')';
            } else {
                res << decPart;
            }
        }
        return res.str();
    }

    // 最大公约数
    template<typename T=int64_t>
    T gcd(T m, T n) {
        return n == 0 ? m : gcd(n, m % n);
    }
};
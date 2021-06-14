//
// Created by smile on 2021/6/14.
//

#include <string>

class Solution {
public:
    int titleToNumber(const std::string &columnTitle) {
        int res = 0;
        for (const auto &col : columnTitle) {
            res *= 26;
            res += col - 'A' + 1;
        }
        return res;
    }
};
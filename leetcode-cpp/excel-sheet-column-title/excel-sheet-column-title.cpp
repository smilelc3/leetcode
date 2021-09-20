//
// Created by smile on 2021/6/13.
//

#include <string>
#include <stack>
#include <algorithm>

class Solution {
public:
    std::string convertToTitle(int columnNumber) {
        std::string res;
        while (columnNumber != 0) {
            columnNumber -= 1;
            res += char('A' + columnNumber % 26);
            columnNumber = columnNumber / 26;
        }
        std::reverse(res.begin(), res.end());
        return res;
    }
};
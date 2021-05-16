//
// Created by smile on 2021/5/15.
//

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(const std::string &s) {

        std::vector<std::vector<std::string>> res;
        if (s.empty()) {
            return res;
        }

        std::vector<bool> dpOdd(s.size(), true);     // 以i为中心，奇数长度的字符串是否是回文串，初始化半径为0.5
        std::vector<bool> dpEven(s.size() - 1);      // 以i+0.5中心，偶数长度的字符串是否是回文串，初始化半径为1

        res.emplace_back();
        for (auto idx = 0; idx < s.size(); idx++) {
            res[0].emplace_back(s.substr(idx,1));
        }

        for (auto idx = 0; idx < dpEven.size(); idx++) {
            dpEven[idx] = s[idx] == s[idx + 1];
        }

        return res;
    }
};
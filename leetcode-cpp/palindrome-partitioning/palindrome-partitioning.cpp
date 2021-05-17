//
// Created by smile on 2021/5/15.
//

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(std::string &s) {
        std::vector<std::vector<std::string>> res;
        std::vector<std::vector<int>> dp;

        // dp[i]表示以i起点，所有可以形成回文子串的终点
        dp.resize(s.size());

        for (auto idx = 0; idx < s.size(); idx++) {
            for (auto width = 0; width < 2; width++) {
                auto left = idx, right = idx + width;
                while (left >= 0 and right < s.size() and s[left] == s[right]) {
                    dp[left].emplace_back(right);
                    left--;
                    right++;
                }
            }
        }
        std::vector<std::string> temp;
        temp.reserve(s.size());
        dfsSplit(s, 0, temp, res, dp);
        return res;
    }

private:
    void dfsSplit(const std::string &s, size_t start, std::vector<std::string> &temp,
                  std::vector<std::vector<std::string>> &res, std::vector<std::vector<int>> &dp) {
        if (start == s.size()) {
            // 保存结果
            res.emplace_back(temp);
            return;
        }
        for (auto stop : dp[start]) {
            temp.emplace_back(s.substr(start, stop - start + 1));
            dfsSplit(s, stop + 1, temp, res, dp);
            temp.pop_back();
        }
    }


};
//
// Created by smile on 2021/5/15.
//

#include <vector>
#include <string>

class Solution {
public:
    std::vector<std::vector<std::string>> partition(const std::string &s) {
        if (s.empty()) {
            return res;
        }
        // dp[i][j]表示s[i,j]子字符串是否是回文串
        dp = std::vector<std::vector<bool>>(s.size(), std::vector<bool>(s.size(), false));

        for (int right = 0; right < s.size(); right++) {
            for (auto left = 0; left <= right; left++) {
                dp[left][right] = s[left] == s[right] and (right - left <= 1 or dp[left + 1][right - 1]);
            }
        }
        std::vector<std::string> temp;
        dfsSplit(s, 0, temp);

        return res;
    }

private:
    void dfsSplit(const std::string &s, size_t start, std::vector<std::string> &temp) {
        if (start == s.size()) {
            // 保存结果
            res.emplace_back(temp);
            return;
        }
        for (auto stop = start; stop < s.size(); stop++) {
            if (dp[start][stop]) {
                temp.emplace_back(s.substr(start, stop - start + 1));
                dfsSplit(s, stop + 1, temp);
                temp.pop_back();
            }
        }
    }

    std::vector<std::vector<std::string>> res;
    std::vector<std::vector<bool>> dp;
};
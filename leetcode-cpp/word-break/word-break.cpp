//
// Created by smile on 2021/4/7.
//

#include <vector>
#include <string>
#include <unordered_set>
#include <algorithm>

class Solution {
public:
    static bool wordBreak(std::string &s, std::vector<std::string> &wordDict) {
        std::unordered_set<std::string> wordSet; // word字典
        int wordMaxLen = 0;
        for (const auto &item : wordDict) {
            wordSet.insert(item);
            wordMaxLen = std::max(wordMaxLen, int(item.length()));
        }
        return wordBreakDp(s, wordSet, wordMaxLen);
    }

    static bool wordBreakDp(std::string &s, std::unordered_set<std::string> &wordSet, int wordMaxLen) {
        size_t n = s.length();
        auto dp = std::vector<bool>(n + 1);  // dp[i] 表示范围 [0, i) 内的子串是否可以拆分后能够组成
        dp[0] = true;
        for (auto i = 1; i <= n; i++) {
            for (auto j = 0; j <= i; j++) {
                if (dp[j] and i - j <= wordMaxLen and wordSet.find(s.substr(j, i - j)) != wordSet.end()) {
                    dp[i] = true;
                    break;
                }
            }
        }
        return dp.back();
    }
};



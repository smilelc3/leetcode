//
// Created by smile on 2021/5/17.
//
#include <string>
#include <algorithm>

class Solution {
public:
    int minCut(std::string &s) {

        // 参考： https://www.youtube.com/watch?v=kTCymFbU2ok
        // dp[i]表示从0~i的子串最小切割次数
        std::vector<size_t> dp(s.size(), s.size());

        for (auto mid = 0; mid < s.size(); mid++) {     // 从中间开始循环
            for (auto diff = 0; diff <= 1; diff++) {    // 处理奇/偶
                auto i = mid, j = mid + diff;
                while (i >= 0 and j < s.size() and s[i] == s[j]) {      //找s[i,j]回文串，向外扩展
                    if (i == 0) {
                        dp[j] = 0;
                    } else {
                        dp[j] = std::min(dp[j], dp[i - 1] + 1);
                    };
                    i--;
                    j++;
                }
            }
        }
        return (int) dp[s.size() - 1];
    }
};
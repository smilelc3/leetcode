//
// Created by smile on 24-7-14.
//

#include <numeric>
#include <vector>

class Solution {
public:
    template<typename T=int8_t>
    static bool canPartition(std::vector<int> &nums) {
        const auto sum = std::reduce(nums.begin(), nums.end());
        if ((sum & 1) == 1) {
            return false;
        }
        const auto half = sum / 2;
        auto dp = std::vector<T>(half + 1, false); // vector<bool>会导致严重性能下降
        dp[0] = true;
        int jMax = 0;
        // dp[i][j] = 表示前i个物品构成限重j的可能性
        // dp[i][j] = dp[i-1][j] or [i-1][j - w[i]]     // 选或不选第i个物品
        for (const int num: nums) {
            jMax = std::min(jMax + num, half); // 前面小部分可能还未到half，不用便利所有
            for (int j = jMax; j >= num; --j) { //从后往推
                dp[j] = dp[j] or dp[j - num];
            }
            if (dp.back()) { // 已经找到答题，提前退出
                return true;
            }
        }
        return dp.back();
    }
};

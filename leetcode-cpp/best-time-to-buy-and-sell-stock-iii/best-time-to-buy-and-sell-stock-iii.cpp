//
// Created by smile on 2021/5/18.
//

#include <array>
#include <algorithm>

class Solution {
public:
    int maxProfit(const std::vector<int> &prices) {
        // DP
        if (prices.empty()) {
            return 0;
        }

        /*
         * global[i][j]：当前到达第i天可以最多进行j次交易，最好的利润
         * local[i][j]：当前到达第i天，最多可进行j次交易，并且最后一次交易在当天卖出，最好的利润
         * 状态转移方程：
         *  global[i][j] = max(local[i][j], global[i-1][j])
         *  local[i][j] = max(global[i-1][j-1], local[i-1][j]) + diff
         */
        const int maxTransTime = 2;
        std::array<int, maxTransTime + 1> local{0};
        std::array<int, maxTransTime + 1> global{0};

        for (auto i = 0; i < prices.size() - 1; i++) {
            for (auto j = maxTransTime; j >= 1; j--) {
                local[j] = std::max(global[j - 1], local[j]) + (prices[i + 1] - prices[i]);
                global[j] = std::max(local[j], global[j]);
            }
        }
        return global[maxTransTime];
    }
};
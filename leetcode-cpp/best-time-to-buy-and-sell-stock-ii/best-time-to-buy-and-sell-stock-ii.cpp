//
// Created by smile on 2021/4/16.
//

#include <vector>

class Solution {
public:
    int maxProfit(std::vector<int> &prices) {
        int profit = 0;
        for (auto idx = 0; idx < prices.size() - 1; idx++) {
            if (prices[idx + 1] > prices[idx]) {
                profit += prices[idx + 1] - prices[idx];
            }
        }
        return profit;
    }
};
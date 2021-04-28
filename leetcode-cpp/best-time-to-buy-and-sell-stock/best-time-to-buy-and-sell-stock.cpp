//
// Created by smile on 2021/4/9.
//
#include <vector>
#include <algorithm>
#include <limits>

class Solution {
public:
    static int maxProfit(std::vector<int> &prices) {
        int maxProfitVal = 0;
        int preMinPrice = std::numeric_limits<int>::max();
        for (int &price : prices) {
            maxProfitVal = std::max(maxProfitVal, price - preMinPrice);
            preMinPrice = std::min(preMinPrice, price);
        }
        return maxProfitVal;
    }
};
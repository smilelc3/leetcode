//
// Created by smile on 2023/7/14.
//

#include <vector>

class Solution {
public:
    static int minCostClimbingStairs(const std::vector<int> &cost) {
        int last_dp = 0, cur_dp = 0;
        for (int i = 0; i < cost.size() - 1; ++i) {
            auto tmp_dp = std::min(last_dp + cost[i], cur_dp + cost[i + 1]);
            last_dp = cur_dp;
            cur_dp = tmp_dp;
        }
        return cur_dp;
    }
};